#include "inventorytype.h"

InventoryType::InventoryType()
{

}

QHash<QString, QString> InventoryType::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}
QString InventoryType::ENTITYNAME = "invent_type";
