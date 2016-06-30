#ifndef MANUFACTURER_H
#define MANUFACTURER_H

#include "dbentity.h"



class Manufacturer:public DbEntity
{
public:
    static QString ENTITYNAME;
    Manufacturer();

private:
    virtual QHash<QString, QVariant> dbValuesImplementation();

    // DbEntity interface
private:
    virtual QString getEntityNameImplementation();   
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
    virtual QVariant dataImplementation(const unsigned int col);
    virtual bool setDataImplementation(const unsigned int col, QVariant value);
};

#endif // MANUFACTURER_H
