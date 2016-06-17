#include "inventorystatus.h"

InventoryStatus::InventoryStatus()
{

}

QHash<QString, QString> InventoryStatus::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}

QString InventoryStatus::ENTITYNAME = "invent_status";
