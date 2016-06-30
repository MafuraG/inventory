#include "inventorytype.h"

InventoryType::InventoryType()
{

}

QHash<QString, QVariant> InventoryType::dbValuesImplementation()
{
    QHash <QString,QVariant> keyVals;
    keyVals[Name] = name();
    keyVals[ID] =id();
    return keyVals;
}

QString InventoryType::getEntityNameImplementation()
{
    return InventoryType::ENTITYNAME;
}

void InventoryType::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setId(dbValues[ID].toUInt());
        setName(dbValues[Name].toString());
    }
}

QVariant InventoryType::dataImplementation(const unsigned int col)
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

bool InventoryType::setDataImplementation(const unsigned int col, QVariant value)
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
QString InventoryType::ENTITYNAME = "invent_type";
