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
    virtual QString getEntityNameImplementation();
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
};

#endif // INVENTORYSTATUS_H
