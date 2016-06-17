#include "manufacturer.h"

manufacturer::manufacturer()
{

}

QHash<QString, QString> manufacturer::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}

QString manufacturer::ENTITYNAME = "manufacturer";
