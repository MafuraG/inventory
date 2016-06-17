#ifndef INVENTORY_H
#define INVENTORY_H

#include "dbentity.h"



class Inventory : public dbEntity
{
public:
    static QString MODELID;
    static QString NUMBER;
    static QString SERIAL;
    static QString OWNERID;
    static QString INVENTORYTYPEID;
    Inventory();
    unsigned int modelId() const;
    void setModelId(unsigned int modelId);

    QString number() const;
    void setNumber(const QString &number);

    QString serial() const;
    void setSerial(const QString &serial);

    unsigned int ownerId() const;
    void setOwnerId(unsigned int ownerId);

    unsigned int inventoryTypeId() const;
    void setInventoryTypeId(unsigned int inventoryTypeId);

private:
    unsigned int m_modelId;
    QString m_number;
    QString m_serial;
    unsigned int m_ownerId;
    unsigned int m_inventoryTypeId;

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // INVENTORY_H
