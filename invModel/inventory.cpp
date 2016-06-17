#include "inventory.h"

Inventory::Inventory()
{

}

unsigned int Inventory::modelId() const
{
    return m_modelId;
}

void Inventory::setModelId(unsigned int modelId)
{
    m_modelId = modelId;
}

QString Inventory::number() const
{
    return m_number;
}

void Inventory::setNumber(const QString &number)
{
    m_number = number;
}

QString Inventory::serial() const
{
    return m_serial;
}

void Inventory::setSerial(const QString &serial)
{
    m_serial = serial;
}

unsigned int Inventory::ownerId() const
{
    return m_ownerId;
}

void Inventory::setOwnerId(unsigned int ownerId)
{
    m_ownerId = ownerId;
}

unsigned int Inventory::inventoryTypeId() const
{
    return m_inventoryTypeId;
}

void Inventory::setInventoryTypeId(unsigned int inventoryType)
{
    m_inventoryTypeId = inventoryType;
}

QHash<QString, QString> Inventory::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[INVENTORYTYPEID] = QString("%0").arg(inventoryTypeId());
    keyVals[MODELID] = QString("%0").arg(modelId());
    keyVals[NUMBER] = QString("%0").arg(number());
    keyVals[OWNERID] = QString("%0").arg(ownerId());
    keyVals[SERIAL] = QString("%0").arg(serial());
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}

QString Inventory::INVENTORYTYPEID = "inventory_type_id";
QString Inventory::MODELID = "model_id";
QString Inventory::NUMBER = "number";
QString Inventory::OWNERID = "owner_id";
QString Inventory::SERIAL = "serial_number";
QString Inventory::ENTITYNAME = "inventory";

