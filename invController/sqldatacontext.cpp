#include "sqldatacontext.h"

SQLDataContext::SQLDataContext(const QString &dbtype = "QSQLITE", const QString &dbname="invdb.sqlite")
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

void SQLDataContext::CreateEntityImplementation(DbEntity &entity)
{
    //TODO implement create for Relation databases
}

void SQLDataContext::DeleteEntityImplementation(DbEntity &entity)
{
    //TODO implement delete for Relation Daatbase
}

void SQLDataContext::UpdateEntityImplementation(DbEntity &entity)
{
    //TODO implement update for Relation Daatbase
}

void SQLDataContext::SelectEntitiesImplementation(QString filter, QList<DbEntity> &selectedEntities)
{
    //TODO select delete for Relation Daatbase
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

void SQLDataContext::buildFilter(QString &q, const QString &oper, const QStringList &params)
{
    if (params.size() != 2) return;
    q = QString("%0 %1 %2").arg(params[0],oper,params[1]);
}

void SQLDataContext::buildInsertQuery(QString &q, const QStringList &columns, const QString &table, const QStringList &values)
{
    QStringList q_str;
    //"insert into genres(name) values(?)"

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
