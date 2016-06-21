#ifndef INVENTORYTYPE_H
#define INVENTORYTYPE_H

#include "dbentity.h"



class InventoryType : public DbEntity
{
public:
    static QString ENTITYNAME;
    InventoryType();

private:
    virtual QHash<QString, QVariant> dbValuesImplementation();
};

#endif // INVENTORYTYPE_H
