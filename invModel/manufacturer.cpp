#include "manufacturer.h"

Manufacturer::Manufacturer()
{

}

QHash<QString, QString> Manufacturer::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}

QString Manufacturer::ENTITYNAME = "manufacturer";
