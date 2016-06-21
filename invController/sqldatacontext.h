#ifndef SQLDATACONTEXT_H
#define SQLDATACONTEXT_H

#include "datacontext.h"

#include <QSqlDatabase>
#include <QSqlQuery>



class SQLDataContext : public DataContext
{
public:
    SQLDataContext(const QString &dbtype, const QString &dbname);

    virtual ~SQLDataContext();

    // DataContext interface
private:
    virtual void CreateEntityImplementation(DbEntity &entity);
    virtual void DeleteEntityImplementation(DbEntity &entity);
    virtual void UpdateEntityImplementation(DbEntity &entity);
    virtual void SelectEntitiesImplementation(QString filter, QList<DbEntity> &selectedEntities);


    void buildSelectQuery(QString &q, const QStringList &columns, const QString &table, const QStringList &filter);
    void buildString(QStringList &result, const QStringList &fragments, const QString &separator);
    void buildFilter(QString &q,  const QString &oper, const QStringList &params);
    void buildInsertQuery(QString &q, const QStringList &columns, const QString &table, const QStringList &values);

    QSqlDatabase db;
    QSqlQuery query;
};

#endif // SQLDATACONTEXT_H
