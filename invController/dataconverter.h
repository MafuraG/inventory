#ifndef DATACONVERSION_H
#define DATACONVERSION_H

#include <QVariant>



class DataConverter
{
public:
    DataConverter();
    QString toString(QVariant &val);
private:
    virtual QString toStringImplementation(QVariant &val) = 0;
};

#endif // DATACONVERSION_H
