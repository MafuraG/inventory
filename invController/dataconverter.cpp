#include "dataconverter.h"

DataConverter::DataConverter()
{

}

QString DataConverter::toString(QVariant &val)
{
    return toStringImplementation(val);
}
