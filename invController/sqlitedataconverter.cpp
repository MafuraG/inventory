#include "sqlitedataconverter.h"

SqliteDataConverter::SqliteDataConverter()
{

}

QString SqliteDataConverter::toDbStringImplementation(QVariant &val)
{
    if (val.type() == QVariant::String)
        return QString("'%0'").arg(val.toString());

    return val.toString();
}

QString SqliteDataConverter::toDbTypeImplementation(QVariant &val)
{
    if (val.type() == QVariant::String) return SqliteDataConverter::sqltTEXT;
    if (val.type() == QVariant::Int) return SqliteDataConverter::sqltINTEGER;
    if (val.isNull() == true) return SqliteDataConverter::sqltNULL;

    return SqliteDataConverter::sqltTEXT;
}

QString SqliteDataConverter::sqltBLOB = "BLOB";
QString SqliteDataConverter::sqltINTEGER = "INTEGER";
QString SqliteDataConverter::sqltNULL = "NULL";
QString SqliteDataConverter::sqltREAL = "REAL";
QString SqliteDataConverter::sqltTEXT = "TEXT";
