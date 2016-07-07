#include "journal.h"
#include <QDebug>
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

void Journal::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setId(dbValues[ID].toUInt());
        qDebug()<<dbValues[ID]<<"to Uint"<<dbValues[ID].toUInt();
        setName(dbValues[Name].toString());
        setDate(dbValues[DATE].toString());
        setInventoryID(dbValues[INVENTORYID].toUInt());
        setStatusID(dbValues[STATUSID].toUInt());
        setComment(dbValues[COMMENT].toString());
    }
}
QVariant Journal::dataImplementation(const unsigned int col)
{
    QHash<QString, QVariant> dBvalues = dbValues();
    if (col == 0 ){
        //ID
        return dBvalues[ID];
    }
    if (col == 1 ){
        //Name
        return dBvalues[Name];
    }

    if (col == 2 ){
        //Date
        return dBvalues[DATE];
    }

    if (col == 3) {
        //Inventory ID
        return dBvalues[INVENTORYID];
    }

    if (col == 4){
        //Status ID
        return dBvalues[STATUSID];
    }

    if (col == 5){
        //COMMENT
        return dBvalues[COMMENT];
    }
    return QVariant();

}

bool Journal::setDataImplementation(const unsigned int col, QVariant value)
{
    QHash<QString, QVariant> dBvalues = dbValues();
    bool success = false;
    if (col == 0 ){
        //ID
        dBvalues[ID] = value;
        success = true;
    }
    if (col == 1 ){
        //Name
        dBvalues[Name] = value;
        success = true;
    }

    if (col == 2 ){
        //Date
        dBvalues[DATE] = value;
        success = true;
    }

    if (col == 3) {
        //Inventory ID
        dBvalues[INVENTORYID] = value;
        success = true;
    }

    if (col == 4){
        //Status ID
        dBvalues[STATUSID] = value;
        success = true;
    }

    if (col == 5){
        //COMMENT
        dBvalues[COMMENT] = value;
        success = true;
    }

    if (success == true) {
        setDbValues(dBvalues);
    }

    return success;
}


QString Journal::COMMENT = "comment";
QString Journal::DATE = "date_";
QString Journal::INVENTORYID = "inventory_id";
QString Journal::STATUSID = "status_id";
QString Journal::ENTITYNAME = "journal";
