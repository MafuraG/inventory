#include "organisation.h"
QString Organisation::ADDRESS = "address_";
QString Organisation::TELEPHONE = "telephone_";

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

QHash<QString, QString> Organisation::dbValues()
{
    QHash<QString,QString> keyVals;
    keyVals[ADDRESS] = QString("%0").arg(address());
    keyVals[TELEPHONE] = QString("%0").arg(telephone());
    keyVals[Name] = QString("%0").arg(name());
    keyVals[ID] = QString("%0").arg(id());
    return keyVals;
}
