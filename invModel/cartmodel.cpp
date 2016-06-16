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

QString InventoryModel::MAN_ID = "man_id";
