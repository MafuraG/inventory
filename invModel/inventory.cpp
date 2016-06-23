#include "inventory.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
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

QHash<QString, QVariant> Inventory::dbValuesImplementation()
{
    QHash <QString,QVariant> keyVals;
    keyVals[INVENTORYTYPEID] = inventoryTypeId();
    keyVals[MODELID] = modelId();
    keyVals[NUMBER] = number();
    keyVals[OWNERID] = ownerId();
    keyVals[SERIAL] = serial();
    keyVals[Name] = name();
    keyVals[ID] =id();
    return keyVals;
}

QString Inventory::getEntityNameImplementation()
{
    return Inventory::ENTITYNAME;
}

void Inventory::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setInventoryTypeId(dbValues[INVENTORYTYPEID].toUInt());
        setModelId(dbValues[MODELID].toUInt());
        setId(dbValues[ID].toUInt());
        setName(dbValues[Name].toString());
        setNumber(dbValues[NUMBER].toString());
        setOwnerId(dbValues[OWNERID].toUInt());
        setSerial(dbValues[SERIAL].toString());
    }
}

QString Inventory::INVENTORYTYPEID = "inventory_type_id";
QString Inventory::MODELID = "model_id";
QString Inventory::NUMBER = "number";
QString Inventory::OWNERID = "owner_id";
QString Inventory::SERIAL = "serial_number";
QString Inventory::ENTITYNAME = "inventory";

