#ifndef DATACONTEXT_H
#define DATACONTEXT_H

#include <dbentity.h>



class DataContext
{
public:
    DataContext();
    void CreateEntity(DbEntity &entity);
    void DeleteEntity(DbEntity &entity);
    void UpdateEntity(DbEntity &entity);
    void SelectEntities(QString filter);

    virtual ~DataContext(){}
};

#endif // DATACONTEXT_H
