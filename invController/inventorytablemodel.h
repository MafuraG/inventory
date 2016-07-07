#ifndef INVENTORYTABLEMODEL_H
#define INVENTORYTABLEMODEL_H

#include "dbentitytablemodel.h"



class InventoryTableModel :public DbEntityTableModel
{
    Q_OBJECT
public:
    InventoryTableModel();

    // DbEntityTableModel interface
private:
    virtual QVariant headerImplementation(const unsigned int col);
    virtual DbEntity *newDbEntityImplementation();


};

#endif // INVENTORYTABLEMODEL_H
