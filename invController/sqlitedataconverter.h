#ifndef SQLITEDATACONVERTER_H
#define SQLITEDATACONVERTER_H

#include "dataconverter.h"



class SqliteDataConverter: public DataConverter
{
public:
    SqliteDataConverter();
    static QString sqltNULL;
    static QString sqltINTEGER;
    static QString sqltREAL;
    static QString sqltTEXT;
    static QString sqltBLOB;

    // DataConverter interface
private:
    virtual QString toDbStringImplementation(QVariant &val);

    // DataConverter interface
private:
    virtual QString toDbTypeImplementation(QVariant &val);
};
/***
 *  NULL — The value is a NULL value
    INTEGER — a signed integer
    REAL — a floating point value
    TEXT — a text string
    BLOB — a blob of data
 ***/

#endif // SQLITEDATACONVERTER_H
