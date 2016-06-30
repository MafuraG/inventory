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
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
    virtual QVariant dataImplementation(const unsigned int col);
    virtual bool setDataImplementation(const unsigned int col, QVariant value);
};

#endif // INVENTORYTYPE_H
