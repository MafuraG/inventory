#include "dataconverter.h"
#include "sqldatacontext.h"
#include "sqlitedataconverter.h"
#include <QDebug>
#include <inventory.h>
#include <inventoryItem.h>
#include <inventorystatus.h>
#include <inventorytype.h>
#include <journal.h>
#include <manufacturer.h>
#include <organisation.h>

SQLDataContext::SQLDataContext(const QString &dbtype, const QString &dbname)
{
    db = QSqlDatabase::addDatabase(dbtype);
    db.setDatabaseName(dbname);

    if( db.open() )
    {
        QSqlQuery temp1;
        query = temp1;
    }
    else
    {
        //qDebug()<< "Error :"<<db.lastError();
    }
}

SQLDataContext::~SQLDataContext()
{    
}

void SQLDataContext::CreateEntityImplementation(DbEntity *entity)
{
    //TODO implement create for Relational databases
    QHash<QString, QVariant> vals = entity->dbValues();
    QString q;
    buildInsertQuery(q,vals.keys(),entity->getEntityName(),vals.values());
    setSqlStr(q);
    qDebug()<<sqlStr();
}

void SQLDataContext::DeleteEntityImplementation(DbEntity *entity)
{
    //TODO implement delete for Relational Daatbase
}

void SQLDataContext::UpdateEntityImplementation(DbEntity *entity)
{
    //TODO implement update for Relational Daatbase
    QHash<QString,QVariant> dbvalues = entity->dbValues();
    QStringList updatePairs = buildkeyValPairs(dbvalues,QString("="));
    QStringList filter;
    filter.append(QString("%0 = %1").arg(DbEntity::ID)
                                    .arg(entity->id()));

    QString q;
    buildUpdateQuery(q,updatePairs,entity->getEntityName(),filter);
    setSqlStr(q);
    qDebug()<<sqlStr();
}

void SQLDataContext::SelectEntitiesImplementation(const QString entityname, const QStringList &filter, QList<DbEntity *> &selectedEntities)
{
    //TODO select delete for Relational Daatbase
    QString q ;
    QStringList columns;
    buildSelectQuery(q,columns,entityname,filter);
    setSqlStr(q);
    qDebug()<<sqlStr();
}

void SQLDataContext::CreateDatabaseImplementation()
{
    DbEntity *entity = new Inventory();
    QString q;
    buildCreateQuery(q,entity);
    qDebug()<<q;
}

void SQLDataContext::buildSelectQuery(QString &q, const QStringList &columns, const QString &table, const QStringList &filter)
{
    QStringList q_str;
    q_str.append("SELECT ");
    if (columns.size() == 0)
    {
        q_str.append(" * ");
    }
    else
    {
        buildString(q_str,columns,QString(","));
    }

    q_str.append("FROM ");

    q_str.append(QString("%0 ").arg(table));

    if (filter.size() > 0 )
    {
        q_str.append("WHERE ");

        buildString(q_str,filter,QString(" AND "));
    }

    QString str;

    for(QString s: q_str)
    {
        str += s;
    }

    q = str;
}

void SQLDataContext::buildString(QStringList &result, const QList<QVariant> &fragments, const QString &separator)
{
    DataConverter *c = new SqliteDataConverter();
    int i = 0;
    for(QVariant s:fragments)
    {
        if (i == 0)
        {
            result.append(c->toDbString(s));
            i++;
        }
        else
        {
            result.append(QString("%0 %1 ").arg(separator,c->toDbString(s)));
        }
    }
}

void SQLDataContext::buildString(QStringList &result, const QStringList &fragments, const QString &separator)
{
    int i = 0;
    for(QString s:fragments)
    {
        if (i == 0)
        {
            result.append(QString("%0").arg(s));
            i++;
        }
        else
        {
            result.append(QString("%0 %1 ").arg(separator,s));
        }
    }
}

QStringList SQLDataContext::buildkeyValPairs(const QHash<QString,QVariant> &dbvalues, const QString &separator)
{
    QList<QString> keys = dbvalues.keys();
    QList<QVariant> values = dbvalues.values();
    DataConverter *c = new SqliteDataConverter();
    QStringList result;
    for(int i = 0 ; i < keys.count(); i++)
    {
        QString key = keys[i];
        QVariant val = values[i];
        QString keyVal = QString("%0 %1 %2").arg(key,separator,c->toDbString(val));
        result.append(keyVal);
    }

    return result;
}

void SQLDataContext::buildFilter(QString &q, const QString &oper, const QStringList &params)
{
    if (params.size() != 2) return;
    q = QString("%0 %1 %2").arg(params[0],oper,params[1]);
}

void SQLDataContext::buildInsertQuery(QString &q, const QStringList &columns, const QString &table, const QList<QVariant> &values)
{
    QStringList q_str;
    //"insert or replace into genres(name) values(?)"

    if (columns.size() != values.size()) return;

    q_str.append("INSERT OR REPLACE  INTO ");
    q_str.append(QString("%0 ").arg(table));

    q_str.append("( ");
    buildString(q_str,columns,QString(","));
    q_str.append(" ) ");

    q_str.append("VALUES ");

    q_str.append("( ");
    buildString(q_str,values,QString(","));
    q_str.append(" ) ");

    QString str;

    for(QString s: q_str)
    {
        str += s;
    }

    q = str;
}

void SQLDataContext::buildUpdateQuery(QString &q, const QStringList &keyvalPairs, const QString &table, const QStringList &filter)
{
    QStringList q_str;
    //UPDATE table_name
    //SET column1 = value1, column2 = value2...., columnN = valueN
    //WHERE [condition];

    q_str.append("UPDATE ");
    q_str.append(QString("%0 ").arg(table));

    q_str.append("SET ");
    buildString(q_str,keyvalPairs,QString(","));
    q_str.append("   ");
    if (filter.size() > 0 )
    {
        q_str.append("WHERE ");

        buildString(q_str,filter,QString(" AND "));
    }


    QString str;

    for(QString s: q_str)
    {
        str += s;
    }

    q = str;
}

void SQLDataContext::buildCreateQuery(QString &q, DbEntity * entity)
{
    QStringList q_str;
    //CREATE TABLE IF NOT EXISTS Testing(Id INTEGER,NAME TEXT)
    QStringList createfields = buildCreateFields(entity);


    q_str.append("CREATE TABLE IF NOT EXISTS ");
    q_str.append(QString("%0 ").arg(entity->getEntityName()));

    q_str.append(" ( ");
    buildString(q_str,createfields,QString(","));
    q_str.append(")");

    QString str;

    for(QString s: q_str)
    {
        str += s;
    }

    q = str;
}

QStringList SQLDataContext::buildCreateFields(DbEntity *entity)
{
    QHash<QString,QVariant> dbvalues = entity->dbValues();

    QList<QString> keys = dbvalues.keys();
    QList<QVariant> values = dbvalues.values();
    DataConverter *c = new SqliteDataConverter();
    QStringList result;
    /**CREATE TABLE COMPANY(
       ID INT PRIMARY KEY     NOT NULL,
       NAME           TEXT    NOT NULL,
       AGE            INT     NOT NULL,
       ADDRESS        CHAR(50),
       SALARY         REAL
    );
    */
    for(int i = 0 ; i < keys.count(); i++)
    {
        QString key = keys[i];
        QVariant val = values[i];
        QString keyVal;

        if (key == DbEntity::ID)
            keyVal = QString("%0 INT PRIMARY KEY NOT NULL").arg(key);
        else
            keyVal = QString("%0 %2").arg(key).arg(c->toDbType(val));

        result.append(keyVal);
    }
    return result;
}

void SQLDataContext::executeQuery(const QString &q,const QString &entityName, QList<DbEntity> &result)
{
    if (query.exec(q)){
        while (query.next()) {
            DbEntity *item = createNewEntity(entityName);

            QHash<QString, QVariant> dbvalues = item->dbValues();
            QList<QString> keys = dbvalues.keys();
            QList<QVariant> values = dbvalues.values();
            for(int i = 0 ; i < dbvalues.count(); i++){
                QString key = keys[i];
                QVariant val = values[i];
                dbvalues[key] = query.value(key);
            }
        }
    }
}

DbEntity *SQLDataContext::createNewEntity(const QString &entityName)
{
    DbEntity *entity = nullptr;


    if (entityName == Inventory::ENTITYNAME){
        entity = new Inventory();
        return entity;
    }
    if (entityName ==InventoryItem::ENTITYNAME){
        entity = new InventoryItem();
        return entity;
     }
    if (entityName ==InventoryStatus::ENTITYNAME){
        entity = new InventoryStatus();
        return entity;
    }
    if (entityName ==InventoryType::ENTITYNAME){
        entity = new InventoryType();
        return entity;
    }
    if (entityName == Journal::ENTITYNAME){
        entity = new Journal();
        return entity;
    }
    if (entityName == Manufacturer::ENTITYNAME){
            entity = new Manufacturer();
            return entity;
    }
    if (entityName == Organisation::ENTITYNAME){
            entity = new Organisation();
            return entity;
    }

    return entity;
}

QString SQLDataContext::sqlStr() const
{
    return m_sqlStr;
}

void SQLDataContext::setSqlStr(const QString &sqlStr)
{
    m_sqlStr = sqlStr;
}
