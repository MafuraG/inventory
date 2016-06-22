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
    void CreateEntity(DbEntity *entity);
    void DeleteEntity(DbEntity *entity);
    void UpdateEntity(DbEntity *entity);
    void SelectEntities(const QString entityname, const QStringList &filter, QList<DbEntity*> &selectedEntities);
    void CreateDatabase();

    virtual ~DataContext(){}

private:
    virtual void CreateEntityImplementation(DbEntity *entity) = 0;
    virtual void DeleteEntityImplementation(DbEntity *entity) = 0;
    virtual void UpdateEntityImplementation(DbEntity *entity) = 0;
    virtual void SelectEntitiesImplementation(const QString entityname, const QStringList &filter, QList<DbEntity*> &selectedEntities) = 0;
    virtual void CreateDatabaseImplementation() = 0;
};

#endif // DATACONTEXT_H
