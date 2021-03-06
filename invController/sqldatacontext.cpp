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
        qDebug()<< "Error :"<<db.lastError();
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
    vals.remove(DbEntity::ID);
    buildInsertQuery(q,vals.keys(),entity->getEntityName(),vals.values());    
    qDebug()<<q;
    QList<DbEntity*> result;
    executeQuery(q,entity->getEntityName(),result);
}

void SQLDataContext::DeleteEntityImplementation(DbEntity *entity)
{
    //TODO implement delete for Relational Daatbase
    QString idfilter = QString("%0 = %1").arg(DbEntity::ID)
                                         .arg(entity->id());

    QString q = "";

    buildDeleteQuery(q,entity->getEntityName(),idfilter);

    qDebug()<<q;

    QList<DbEntity*> result;
    executeQuery(q,entity->getEntityName(),result);
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
    qDebug()<<q;

    QList<DbEntity*> result;
    executeQuery(q,entity->getEntityName(),result);
}

void SQLDataContext::SelectEntitiesImplementation(const QString entityname, const QStringList &filter, QList<DbEntity *> &selectedEntities)
{
    //TODO select delete for Relational Daatbase
    QString q ;
    QStringList columns;
    buildSelectQuery(q,columns,entityname,filter);    
    qDebug()<<q;

    executeQuery(q,entityname,selectedEntities);
}

void SQLDataContext::CreateDatabaseImplementation()
{
    QStringList entityNames = GetEntitiesList();
    for(QString entityName:entityNames){
        //create tables
        QString q;
        QList<DbEntity*> result;
        buildCreateQuery(q,entityName);
        executeQuery(q,entityName,result);
        qDebug()<<q;
    }
}

QStringList SQLDataContext::GetEntitiesListImplementation()
{
    QStringList list;
    list.append(Inventory::ENTITYNAME);
    list.append(InventoryItem::ENTITYNAME);
    list.append(InventoryStatus::ENTITYNAME);
    list.append(InventoryType::ENTITYNAME);
    list.append(Journal::ENTITYNAME);
    list.append(Manufacturer::ENTITYNAME);
    list.append(Organisation::ENTITYNAME);
    return list;
}

DbEntity *SQLDataContext::CreateNewEntityImplementation(const QString entityName)
{
    return createNewSqlEntity(entityName);
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

void SQLDataContext::buildDeleteQuery(QString &q, const QString &tableName, const QString &idfilter)
{
    QStringList q_str;
    //DELETE FROM table_name
    //WHERE [condition];
    q_str.append("DELETE FROM ");
    q_str.append(tableName);\
    q_str.append("   WHERE ");
    q_str.append(idfilter);

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

void SQLDataContext::buildCreateQuery(QString &q, const QString entityName)
{
    QStringList q_str;
    //CREATE TABLE IF NOT EXISTS Testing(Id INTEGER,NAME TEXT)
    QStringList createfields = buildCreateFields(entityName);


    q_str.append("CREATE TABLE IF NOT EXISTS ");
    q_str.append(QString("%0 ").arg(entityName));

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

QStringList SQLDataContext::buildCreateFields(const QString &entityName)
{
    DbEntity *entity = createNewSqlEntity(entityName);
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
            keyVal = QString("%0 INTEGER PRIMARY KEY AUTOINCREMENT").arg(key);
        else
            keyVal = QString("%0 %2").arg(key).arg(c->toDbType(val));

        result.append(keyVal);
    }
    return result;
}

void SQLDataContext::executeQuery(const QString &q,const QString &entityName, QList<DbEntity*> &result)
{
    if (query.exec(q)){
        while (query.next()) {
            DbEntity *item = createNewSqlEntity(entityName);

            QHash<QString, QVariant> dbvalues = item->dbValues();
            QList<QString> keys = dbvalues.keys();            
            for(int i = 0 ; i < dbvalues.count(); i++){
                QString key = keys[i];
                dbvalues[key] = query.value(key);                
            }
            //qDebug()<<"dbValues from db"<< dbvalues;
            item->setDbValues(dbvalues);
            //qDebug()<<"dbValues from item"<<item->dbValues();
            result.append(item);
        }
    }
}

DbEntity *SQLDataContext::createNewSqlEntity(const QString &entityName)
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
