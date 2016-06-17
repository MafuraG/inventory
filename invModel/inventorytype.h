#ifndef INVENTORYTYPE_H
#define INVENTORYTYPE_H

#include "dbentity.h"



class InventoryType : public dbEntity
{
public:
    InventoryType();

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // INVENTORYTYPE_H
