#include "inventoryModel.h"

InventoryModel::InventoryModel()
{

}

unsigned int InventoryModel::manId() const
{
    return m_manId;
}

void InventoryModel::setManId(unsigned int manId)
{
    m_manId = manId;
}

QHash<QString, QString> InventoryModel::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[MAN_ID] = QString("%0").arg(manId());
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}

QString InventoryModel::MAN_ID = "man_id";
