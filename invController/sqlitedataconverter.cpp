#include "sqlitedataconverter.h"

SqliteDataConverter::SqliteDataConverter()
{

}

QString SqliteDataConverter::toStringImplementation(QVariant &val)
{
    if (val.type() == QVariant::String)
        return QString("'%0'").arg(val.toString());

    return val.toString();
}
