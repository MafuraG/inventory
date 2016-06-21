#include "organisation.h"
QString Organisation::ADDRESS = "address_";
QString Organisation::TELEPHONE = "telephone_";
QString Organisation::ENTITYNAME = "organisation";

Organisation::Organisation()
{

}

QString Organisation::address() const
{
    return m_address;
}

void Organisation::setAddress(const QString &address)
{
    m_address = address;
}

QString Organisation::telephone() const
{
    return m_telephone;
}

void Organisation::setTelephone(const QString &telephone)
{
    m_telephone = telephone;
}

QHash<QString, QVariant> Organisation::dbValuesImplementation()
{
    QHash<QString,QVariant> keyVals;
    keyVals[ADDRESS] = address();
    keyVals[TELEPHONE] = telephone();
    keyVals[Name] = name();
    keyVals[ID] = id();
    return keyVals;
}

QString Organisation::getEntityNameImplementation()
{
    return Organisation::ENTITYNAME;
}


