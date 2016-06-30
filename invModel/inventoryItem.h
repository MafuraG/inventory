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
    virtual QString getEntityNameImplementation();
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);    
    virtual QVariant dataImplementation(const unsigned int col);
    virtual bool setDataImplementation(const unsigned int col, QVariant value);
};

#endif // CARTMODEL_H
