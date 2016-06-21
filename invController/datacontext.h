#ifndef DATACONTEXT_H
#define DATACONTEXT_H

#include <dbentity.h>
/**
 * @brief The DataContext class
 *
 * Non Virtual Interface Idiom (NVI)
 * more in http://www.gotw.ca/publications/mill18.htm
 */


class DataContext
{
public:
    DataContext();
    void CreateEntity(DbEntity &entity);
    void DeleteEntity(DbEntity &entity);
    void UpdateEntity(DbEntity &entity);
    void SelectEntities(QString filter, QList<DbEntity> &selectedEntities);

    virtual ~DataContext(){}

private:
    virtual void CreateEntityImplementation(DbEntity &entity) = 0;
    virtual void DeleteEntityImplementation(DbEntity &entity) = 0;
    virtual void UpdateEntityImplementation(DbEntity &entity) = 0;
    virtual void SelectEntitiesImplementation(QString filter, QList<DbEntity> &selectedEntities);
};

#endif // DATACONTEXT_H
