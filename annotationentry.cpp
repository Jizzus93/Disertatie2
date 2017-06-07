#include "annotationentry.h"

AnnotationEntry::AnnotationEntry():
    m_annotationType(E_ENTRY_MAX),
    m_startOffset(0),
    m_endOffset(0)
{

}

AnnotationEntry::AnnotationEntry(int entryType, int startOffset, int endOffset):
    m_annotationType(entryType),
    m_startOffset(startOffset),
    m_endOffset(endOffset)
{

}


void AnnotationEntry::read(const QJsonObject &json)
{
    this->m_annotationType = json["annotationType"].toInt();
    this->m_startOffset = json["startOffset"].toInt();
    this->m_endOffset = json["endOffset"].toInt();
}

void AnnotationEntry::write(QJsonObject &json) const
{
    json["annotationType"] = m_annotationType;
    json["startOffset"] = m_startOffset;
    json["endOffset"] = m_endOffset;
}

int AnnotationEntry::getAnnotationType()
{
    return this->m_annotationType;
}

void AnnotationEntry::setAnnotationType(int entryType)
{
    this->m_annotationType = entryType;
}


int AnnotationEntry::getStartOffset()
{
    return this->m_startOffset;
}

void AnnotationEntry::setStartOffset(int offset)
{
    this->m_startOffset = offset;
}

int AnnotationEntry::getEndOffset()
{
    return this->m_endOffset;
}

void AnnotationEntry::setEndOffset(int offset)
{
    this->m_endOffset = offset;
}
