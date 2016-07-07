#ifndef DATACONTEXT_H
#define DATACONTEXT_H

#include <dbentity.h>
/**
 * @brief The DataContext class
 *
 * Using Non Virtual Interface Idiom (NVI)
 * more in http://www.gotw.ca/publications/mill18.htm
 */


class DataContext:public QObject
{
    Q_OBJECT
public:
    DataContext();
    void CreateEntity(DbEntity *entity);
    DbEntity *CreateNewEntity(const QString entityName);
    void DeleteEntity(DbEntity *entity);
    void UpdateEntity(DbEntity *entity);
    void SelectEntities(const QString entityname, const QStringList &filter, QList<DbEntity*> &selectedEntities);
    void CreateDatabase();
    QStringList GetEntitiesList();

    virtual ~DataContext(){}
public slots:
    void onEntityCreated(DbEntity *entity);
    void onEntityUpdated (DbEntity *entity);
    void onEntityDeleted(DbEntity *entity);

private:
    virtual void CreateEntityImplementation(DbEntity *entity) = 0;
    virtual void DeleteEntityImplementation(DbEntity *entity) = 0;
    virtual void UpdateEntityImplementation(DbEntity *entity) = 0;
    virtual void SelectEntitiesImplementation(const QString entityname, const QStringList &filter, QList<DbEntity*> &selectedEntities) = 0;
    virtual void CreateDatabaseImplementation() = 0;
    virtual QStringList GetEntitiesListImplementation() = 0;
    virtual DbEntity *CreateNewEntityImplementation(const QString entityName) = 0;
};

#endif // DATACONTEXT_H
