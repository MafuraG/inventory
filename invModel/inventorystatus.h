#ifndef INVENTORYSTATUS_H
#define INVENTORYSTATUS_H

#include "dbentity.h"



class InventoryStatus : public DbEntity
{
public:
    static QString ENTITYNAME;
    InventoryStatus();

private:
    virtual QHash<QString, QVariant> dbValuesImplementation();

    // DbEntity interface
private:
    virtual QString getEntityNameImplementation();
};

#endif // INVENTORYSTATUS_H
