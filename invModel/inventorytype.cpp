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
QString InventoryType::ENTITYNAME = "invent_type";
