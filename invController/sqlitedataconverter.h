#ifndef SQLITEDATACONVERTER_H
#define SQLITEDATACONVERTER_H

#include "dataconverter.h"



class SqliteDataConverter: public DataConverter
{
public:
    SqliteDataConverter();

    // DataConverter interface
private:
    virtual QString toStringImplementation(QVariant &val);
};

#endif // SQLITEDATACONVERTER_H
