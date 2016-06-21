#include "journal.h"

Journal::Journal()
{

}

unsigned int Journal::inventoryID() const
{
    return m_inventoryID;
}

void Journal::setInventoryID(unsigned int inventoryID)
{
    m_inventoryID = inventoryID;
}

QString Journal::date() const
{
    return m_date;
}

void Journal::setDate(const QString &date)
{
    m_date = date;
}

unsigned int Journal::statusID() const
{
    return m_statusID;
}

void Journal::setStatusID(unsigned int statusID)
{
    m_statusID = statusID;
}

QString Journal::comment() const
{
    return m_comment;
}

void Journal::setComment(const QString &comment)
{
    m_comment = comment;
}

QHash<QString, QVariant> Journal::dbValuesImplementation()
{
    QHash <QString,QVariant> keyVals;
    keyVals[INVENTORYID] = inventoryID();
    keyVals[DATE] = date();
    keyVals[STATUSID] = statusID();
    keyVals[Name] = name();
    keyVals[ID] = id();
    keyVals[COMMENT] = comment();
    return keyVals;
}

QString Journal::getEntityNameImplementation()
{
    return Journal::ENTITYNAME;
}


QString Journal::COMMENT = "comment";
QString Journal::DATE = "date_";
QString Journal::INVENTORYID = "inventory_id";
QString Journal::STATUSID = "status_id";
QString Journal::ENTITYNAME = "journal";
