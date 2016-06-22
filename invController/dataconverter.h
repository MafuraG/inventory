#ifndef DATACONVERSION_H
#define DATACONVERSION_H

#include <QVariant>



class DataConverter
{
public:
    DataConverter();
    QString toDbString(QVariant &val);
    QString toDbType(QVariant &val);
private:
    virtual QString toDbStringImplementation(QVariant &val) = 0;
    virtual QString toDbTypeImplementation(QVariant &val) = 0;
};

#endif // DATACONVERSION_H
