#include "inventorystatus.h"

InventoryStatus::InventoryStatus()
{

}

QHash<QString, QVariant> InventoryStatus::dbValuesImplementation()
{
    QHash <QString,QVariant> keyVals;
    keyVals[Name] = name();
    keyVals[ID] = id();
    return keyVals;
}

QString InventoryStatus::getEntityNameImplementation()
{
    return InventoryStatus::ENTITYNAME;
}

void InventoryStatus::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setId(dbValues[ID].toUInt());
        setName(dbValues[Name].toString());
    }
}

QVariant InventoryStatus::dataImplementation(const unsigned int col)
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

    return QVariant();

}

bool InventoryStatus::setDataImplementation(const unsigned int col, QVariant value)
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

    if (success == true) {
        setDbValues(dBvalues);
    }

    return success;
}

QString InventoryStatus::ENTITYNAME = "invent_status";
