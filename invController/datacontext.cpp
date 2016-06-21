#include "datacontext.h"

DataContext::DataContext()
{

}

void DataContext::CreateEntity(DbEntity *entity)
{
    CreateEntityImplementation(entity);
}

void DataContext::DeleteEntity(DbEntity *entity)
{
    DeleteEntityImplementation(entity);
}

void DataContext::UpdateEntity(DbEntity *entity)
{
    UpdateEntityImplementation(entity);
}

void DataContext::SelectEntities(QString filter, QList<DbEntity> &selectedEntities)
{
    SelectEntitiesImplementation(filter,selectedEntities);
}

void DataContext::CreateDatabase()
{
    CreateDatabaseImplementation();
}
