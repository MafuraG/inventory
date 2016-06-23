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

    // DbEntity interface
private:
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
};

#endif // MANUFACTURER_H
