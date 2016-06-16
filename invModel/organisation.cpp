#include "organisation.h"
QString organisation::ADDRESS = "address_";
QString organisation::TELEPHONE = "telephone_";

organisation::organisation()
{

}

QString organisation::address() const
{
    return m_address;
}

void organisation::setAddress(const QString &address)
{
    m_address = address;
}

QString organisation::telephone() const
{
    return m_telephone;
}

void organisation::setTelephone(const QString &telephone)
{
    m_telephone = telephone;
}
