#ifndef JOUNALTABLEMODEL_H
#define JOUNALTABLEMODEL_H

#include "dbentitytablemodel.h"



class JounalTableModel: public DbEntityTableModel
{
public:
    JounalTableModel();

    // DbEntityTableModel interface
private:
    virtual QVariant headerImplementation(const unsigned int col);
    virtual DbEntity *newDbEntityImplementation();

};

#endif // JOUNALTABLEMODEL_H
