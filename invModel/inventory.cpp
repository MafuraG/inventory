#include "inventory.h"
#include <QDebug>

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
    keyVals[Name] = name();
    keyVals[ID] =id();
    keyVals[INVENTORYTYPEID] = inventoryTypeId();
    keyVals[MODELID] = modelId();
    keyVals[NUMBER] = number();
    keyVals[OWNERID] = ownerId();
    keyVals[SERIAL] = serial();

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
        qDebug()<<dbValues[ID]<<"to Uint"<<dbValues[ID].toUInt();
        setName(dbValues[Name].toString());
        setNumber(dbValues[NUMBER].toString());
        setOwnerId(dbValues[OWNERID].toUInt());
        setSerial(dbValues[SERIAL].toString());
    }
}

QVariant Inventory::dataImplementation(const unsigned int col)
{
    QHash<QString, QVariant> dBvalues = dbValues();
    if (col == 0 ){
        //ID
        return dBvalues[ID];
    }
    if (col == 1 ){
        //Name
        return dBvalues[Name];
    }
    if (col == 2){
       //Inventory type
        return dBvalues[INVENTORYTYPEID];
    }

    if (col == 3){
        //Model id
        return dBvalues[MODELID];
    }

    if (col == 4){
        //Number
        return dBvalues[NUMBER];
    }

    if (col == 5){
        //Ownerid
        return dBvalues[OWNERID];
    }

    if (col == 6){
        //Serial
        return dBvalues[SERIAL];
    }

    return QVariant();

}

bool Inventory::setDataImplementation(const unsigned int col, QVariant value)
{
    QHash<QString, QVariant> dBvalues = dbValues();
    bool success = false;
    if (col == 0 ){
        //ID
        dBvalues[ID] = value;
        success = true;
    }
    if (col == 1 ){
        //Name
        dBvalues[Name] = value;
        success = true;
    }
    if (col == 2){
       //Inventory type
        dBvalues[INVENTORYTYPEID] = value;
        success = true;
    }

    if (col == 3){
        //Model id
        dBvalues[MODELID] = value;
        success = true;
    }

    if (col == 4){
        //Number
        dBvalues[NUMBER] = value;
        success = true;
    }

    if (col == 5){
        //Ownerid
        dBvalues[OWNERID] = value;
        success = true;
    }

    if (col == 6){
        //Serial
        dBvalues[SERIAL] = value;
        success = true;
    }

    if (success == true) {
        setDbValues(dBvalues);
    }

    return success;
}

QString Inventory::INVENTORYTYPEID = "inventory_type_id";
QString Inventory::MODELID = "model_id";
QString Inventory::NUMBER = "number";
QString Inventory::OWNERID = "owner_id";
QString Inventory::SERIAL = "serial_number";
QString Inventory::ENTITYNAME = "inventory";

