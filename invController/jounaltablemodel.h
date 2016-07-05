#ifndef JOUNALTABLEMODEL_H
#define JOUNALTABLEMODEL_H

#include "dbentitytablemodel.h"



class JournalTableModel: public DbEntityTableModel
{
public:
    JournalTableModel();

    // DbEntityTableModel interface
private:
    virtual QVariant headerImplementation(const unsigned int col);
    virtual DbEntity *newDbEntityImplementation();

};

#endif // JOUNALTABLEMODEL_H
