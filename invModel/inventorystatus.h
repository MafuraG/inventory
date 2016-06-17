#ifndef INVENTORYSTATUS_H
#define INVENTORYSTATUS_H

#include "dbentity.h"



class InventoryStatus : public dbEntity
{
public:
    static QString ENTITYNAME;
    InventoryStatus();

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // INVENTORYSTATUS_H
