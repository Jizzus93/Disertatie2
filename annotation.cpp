#include <annotation.h>


#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

Annotation::Annotation()
{

}

void Annotation::setEntryList(const QList<AnnotationEntry> &entryList)
{
    this->m_entryList = entryList;
}

const QList<AnnotationEntry>& Annotation::getEntryList()
{
    return m_entryList;
}

void Annotation::read(const QJsonObject &json)
{
    this->m_entryList.clear();

    QJsonArray entryArray = json["annotationList"].toArray();

    for(int entryIndex = 0; entryIndex < entryArray.size(); ++entryIndex)
    {
        QJsonObject entryObject = entryArray[entryIndex].toObject();
        AnnotationEntry entry;
        entry.read(entryObject);
        m_entryList.append(entry);
    }
}

void Annotation::write(QJsonObject &json) const
{
    QJsonArray entryArray;

    foreach(const AnnotationEntry entry, m_entryList)
    {
        QJsonObject entryObject;
        entry.write(entryObject);
        entryArray.append(entryObject);
    }

    json["annotationList"] = entryArray;
}

bool Annotation::loadAnnotation(SaveFormat saveFormat, QString fileName)
{
    QFile loadFile(fileName);

        if (!loadFile.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open load file.");
            return false;
        }

        QByteArray saveData = loadFile.readAll();

        QJsonDocument loadDoc(saveFormat == Json
            ? QJsonDocument::fromJson(saveData)
            : QJsonDocument::fromBinaryData(saveData));

        read(loadDoc.object());

        return true;
}

bool Annotation::saveAnnotation(SaveFormat saveFormat, QString fileName) const
{
    QFile saveFile(fileName);

        if (!saveFile.open(QIODevice::WriteOnly)) {
            qWarning("Couldn't open save file.");
            return false;
        }

        QJsonObject gameObject;
        write(gameObject);
        QJsonDocument saveDoc(gameObject);
        saveFile.write(saveFormat == Json
            ? saveDoc.toJson()
            : saveDoc.toBinaryData());

        return true;
}
