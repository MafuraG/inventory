#ifndef SQLDATACONTEXT_H
#define SQLDATACONTEXT_H

#include "datacontext.h"



class SQLDataContext : public DataContext
{
public:
    SQLDataContext();

    virtual ~SQLDataContext();
};

#endif // SQLDATACONTEXT_H
