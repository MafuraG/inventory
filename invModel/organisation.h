#ifndef ORGANISATION_H
#define ORGANISATION_H

#include "dbentity.h"



class organisation: public dbEntity
{
public:
    static QString ADDRESS;
    static QString TELEPHONE;

    organisation();
    QString address() const;
    void setAddress(const QString &address);

    QString telephone() const;
    void setTelephone(const QString &telephone);

private:
    QString m_address;
    QString m_telephone;
};

#endif // ORGANISATION_H
