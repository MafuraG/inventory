#include "manufacturer.h"

Manufacturer::Manufacturer()
{

}

QHash<QString, QVariant> Manufacturer::dbValuesImplementation()
{
    QHash <QString,QVariant> keyVals;
    keyVals[Name] = name();
    keyVals[ID] =id();
    return keyVals;
}

QString Manufacturer::getEntityNameImplementation()
{
    return Manufacturer::ENTITYNAME;
}

void Manufacturer::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setId(dbValues[ID].toUInt());
        setName(dbValues[Name].toString());
    }
}

QString Manufacturer::ENTITYNAME = "manufacturer";
