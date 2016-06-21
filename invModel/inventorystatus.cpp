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

QString InventoryStatus::ENTITYNAME = "invent_status";
