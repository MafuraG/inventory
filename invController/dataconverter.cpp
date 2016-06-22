#include "dataconverter.h"

DataConverter::DataConverter()
{

}

QString DataConverter::toDbString(QVariant &val)
{
    return toDbStringImplementation(val);
}

QString DataConverter::toDbType(QVariant &val)
{
    return toDbTypeImplementation(val);
}
