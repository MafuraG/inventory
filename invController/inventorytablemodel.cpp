#include "inventorytablemodel.h"
#include <QDebug>
#include <inventory.h>

InventoryTableModel::InventoryTableModel()
{
    QVector<QString> headers ;
    headers.append(Inventory::ID);
    headers.append(Inventory::Name);
    headers.append(Inventory::INVENTORYTYPEID);
    headers.append(Inventory::MODELID);
    headers.append(Inventory::NUMBER);
    headers.append(Inventory::OWNERID);
    headers.append(Inventory::SERIAL);

    setHeaders(headers);
}

QVariant InventoryTableModel::headerImplementation(const unsigned int col)
{
    QVector<QString> headers = getHeaders();
    if (col < headers.count()) return headers[col];
    return QVariant();
}

DbEntity *InventoryTableModel::newDbEntityImplementation()
{    
    DbEntity *entity = new Inventory();
    return entity;
}
