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
QString InventoryType::ENTITYNAME = "invent_type";
