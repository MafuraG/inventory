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

    // DbEntity interface
private:
    virtual QString getEntityNameImplementation();

    // DbEntity interface
private:
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
};

#endif // INVENTORYTYPE_H
