#ifndef MANUFACTURER_H
#define MANUFACTURER_H

#include "dbentity.h"



class manufacturer:public dbEntity
{
public:
    static QString ENTITYNAME;
    manufacturer();

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // MANUFACTURER_H
