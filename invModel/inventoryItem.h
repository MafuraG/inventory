#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include "dbentity.h"



class InventoryItem: public DbEntity
{

public:
    static QString MAN_ID;
    static QString ENTITYNAME;
    InventoryItem();
    unsigned int manId() const;
    void setManId(unsigned int manId);

private:
    unsigned int m_manId;

private:
    virtual QHash<QString, QVariant> dbValuesImplementation();

    // DbEntity interface
private:
    virtual QString getEntityNameImplementation();
};

#endif // CARTMODEL_H
