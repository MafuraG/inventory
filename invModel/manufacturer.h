#ifndef MANUFACTURER_H
#define MANUFACTURER_H

#include "dbentity.h"



class Manufacturer:public dbEntity
{
public:
    static QString ENTITYNAME;
    Manufacturer();

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // MANUFACTURER_H
