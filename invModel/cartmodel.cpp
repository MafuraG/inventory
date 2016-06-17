#include "inventoryDetail.h"

InventoryDetail::InventoryDetail()
{

}

unsigned int InventoryDetail::manId() const
{
    return m_manId;
}

void InventoryDetail::setManId(unsigned int manId)
{
    m_manId = manId;
}

QHash<QString, QString> InventoryDetail::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[MAN_ID] = QString("%0").arg(manId());
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}

QString InventoryDetail::MAN_ID = "man_id";
QString InventoryDetail::ENTITYNAME = "invent_detail";
