#ifndef ANNOTATION_H
#define ANNOTATION_H

#include<annotationentry.h>

#include<QJsonObject>
#include<QList>



class Annotation{
public:
    Annotation();

    enum SaveFormat{
        Json,Binary
    };

    void setEntryList(const QList<AnnotationEntry> &entryList);
    const QList<AnnotationEntry>& getEntryList();

    virtual bool loadAnnotation(SaveFormat saveFormat, QString fileName);
    virtual bool saveAnnotation(SaveFormat saveFormat, QString fileName) const;

    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;
private:
    QList<AnnotationEntry> m_entryList;
};

#endif // ANNOTATION_H
