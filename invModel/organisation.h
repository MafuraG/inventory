#ifndef ORGANISATION_H
#define ORGANISATION_H

#include "dbentity.h"



class Organisation: public DbEntity
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



    // DbEntity interface
private:
    virtual QHash<QString, QVariant> dbValuesImplementation();

    // DbEntity interface
private:
    virtual QString getEntityNameImplementation();

    // DbEntity interface
private:
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
};

#endif // ORGANISATION_H
