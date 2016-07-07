#ifndef SQLDATACONTEXT_H
#define SQLDATACONTEXT_H

#include "datacontext.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>



class SQLDataContext : public DataContext
{
    Q_OBJECT
public:
    SQLDataContext(const QString &dbtype = "QSQLITE", const QString &dbname="invdb.sqlite");

    virtual ~SQLDataContext();

    // DataContext interface
    QString sqlStr() const;
    void setSqlStr(const QString &sqlStr);

private:
    virtual void CreateEntityImplementation(DbEntity *entity);
    virtual void DeleteEntityImplementation(DbEntity *entity);
    virtual void UpdateEntityImplementation(DbEntity *entity);
    virtual void SelectEntitiesImplementation(const QString entityname, const QStringList &filter, QList<DbEntity*> &selectedEntities);
    virtual void CreateDatabaseImplementation();
    virtual QStringList GetEntitiesListImplementation();
    virtual DbEntity *CreateNewEntityImplementation(const QString entityName);


    void buildSelectQuery(QString &q, const QStringList &columns, const QString &table, const QStringList &filter);
    void buildString(QStringList &result, const QList<QVariant> &fragments, const QString &separator);
    void buildString(QStringList &result, const QStringList &fragments, const QString &separator);
    void buildFilter(QString &q,  const QString &oper, const QStringList &params);
    void buildInsertQuery(QString &q, const QStringList &columns, const QString &table, const QList<QVariant> &values);
    void buildDeleteQuery(QString &q, const QString &tableName, const QString &idfilter);
    void buildUpdateQuery(QString &q, const QStringList &keyvalPairs, const QString &table, const QStringList &filter);
    void buildCreateQuery(QString &q, const QString entityName);
    QStringList buildkeyValPairs(const QHash<QString, QVariant> &dbvalues, const QString &separator);
    QStringList buildCreateFields(const QString &entityName);
    void executeQuery(const QString &q, const QString &entityName, QList<DbEntity *> &result);
    DbEntity *createNewSqlEntity(const QString &entityName);

    QSqlDatabase db;
    QSqlQuery query;
    QString m_sqlStr;

};

#endif // SQLDATACONTEXT_H
