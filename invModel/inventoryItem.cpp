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

QString InventoryItem::MAN_ID = "man_id";
QString InventoryItem::ENTITYNAME = "invent_detail";
