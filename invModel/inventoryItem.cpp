#include "inventoryItem.h"

InventoryItem::InventoryItem()
{

}

unsigned int InventoryItem::manId() const
{
    return m_manId;
}

void InventoryItem::setManId(unsigned int manId)
{
    m_manId = manId;
}

QHash<QString, QVariant> InventoryItem::dbValuesImplementation()
{
    QHash <QString,QVariant> keyVals;
    keyVals[MAN_ID] = manId();
    keyVals[Name] = name();
    keyVals[ID] = id();
    return keyVals;
}

QString InventoryItem::getEntityNameImplementation()
{
    return InventoryItem::ENTITYNAME;
}

void InventoryItem::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setId(dbValues[ID].toLongLong());
        setName(dbValues[Name].toString());
        setManId(dbValues[MAN_ID].toUInt());
    }
}

QVariant InventoryItem::dataImplementation(const unsigned int col)
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
    if (col == 2){
       //MAN_ID
        return dBvalues[MAN_ID];
    }

    return QVariant();

}

bool InventoryItem::setDataImplementation(const unsigned int col, QVariant value)
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
    if (col == 2){
       //MAN_ID
        dBvalues[MAN_ID] = value;
        success = true;
    }

    if (success == true) {
        setDbValues(dBvalues);
    }

    return success;
}

QString InventoryItem::MAN_ID = "man_id";
QString InventoryItem::ENTITYNAME = "invent_detail";
