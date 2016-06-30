#include "datacontext.h"

DataContext::DataContext()
{

}

void DataContext::CreateEntity(DbEntity *entity)
{
    CreateEntityImplementation(entity);
}

DbEntity *DataContext::CreateNewEntity(const QString entityName)
{
    return CreateNewEntityImplementation(entityName);
}

void DataContext::DeleteEntity(DbEntity *entity)
{
    DeleteEntityImplementation(entity);
}

void DataContext::UpdateEntity(DbEntity *entity)
{
    UpdateEntityImplementation(entity);
}

void DataContext::SelectEntities(const QString entityname, const QStringList &filter, QList<DbEntity *> &selectedEntities)
{
    SelectEntitiesImplementation(entityname,filter,selectedEntities);
}

void DataContext::CreateDatabase()
{
    CreateDatabaseImplementation();
}

QStringList DataContext::GetEntitiesList()
{
    return GetEntitiesListImplementation();
}
