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
    virtual QString getEntityNameImplementation();
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues);
    virtual QVariant dataImplementation(const unsigned int col);
    virtual bool setDataImplementation(const unsigned int col, QVariant value);
};

#endif // ORGANISATION_H
