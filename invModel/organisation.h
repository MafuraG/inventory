#ifndef ORGANISATION_H
#define ORGANISATION_H

#include "dbentity.h"



class Organisation: public dbEntity
{
public:
    static QString ADDRESS;
    static QString TELEPHONE;
    static QString ENTITYNAME;

    Organisation();
    QString address() const;
    void setAddress(const QString &address);

    QString telephone() const;
    void setTelephone(const QString &telephone);

private:
    QString m_address;
    QString m_telephone;

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // ORGANISATION_H
