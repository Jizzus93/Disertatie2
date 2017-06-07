#ifndef ANNOTATIONENTRY_H
#define ANNOTATIONENTRY_H

#include<QJsonObject>

class AnnotationEntry
{
public:

    enum EntryType{
        E_ENTRY_CLAUSE = 0,
        E_ENTRY_MAX
    } eEnumType;

    AnnotationEntry();

    AnnotationEntry(int entryType, int startOffset, int endOffset);


    virtual void read(const QJsonObject &json);
    virtual void write(QJsonObject &json) const;

    int getAnnotationType();
    void setAnnotationType(int entryType);

    int getStartOffset();
    void setStartOffset(int offset);

    int getEndOffset();
    void setEndOffset(int offset);

private:
    int m_annotationType;
    int m_startOffset;
    int m_endOffset;
};

#endif // ANNOTATIONENTRY_H
