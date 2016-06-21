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

QString Manufacturer::ENTITYNAME = "manufacturer";
