#ifndef JOURNAL_H
#define JOURNAL_H

#include "dbentity.h"



class Journal: public dbEntity
{
public:
    Journal();
    static QString ENTITYNAME;
    static QString INVENTORYID;
    static QString DATE;
    static QString STATUSID;
    static QString COMMENT;

    unsigned int inventoryID() const;
    void setInventoryID(unsigned int inventoryID);

    QString date() const;
    void setDate(const QString &date);

    unsigned int statusID() const;
    void setStatusID(unsigned int statusID);

    QString comment() const;
    void setComment(const QString &comment);

private:
    unsigned int m_inventoryID;
    QString m_date;
    unsigned int m_statusID;
    QString m_comment;

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // JOURNAL_H
