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

QString InventoryStatus::ENTITYNAME = "invent_status";
