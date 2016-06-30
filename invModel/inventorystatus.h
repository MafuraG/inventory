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
    virtual QVariant dataImplementation(const unsigned int col);
    virtual bool setDataImplementation(const unsigned int col, QVariant value);
};

#endif // INVENTORYSTATUS_H
