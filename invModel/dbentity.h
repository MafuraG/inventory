#ifndef DBENTITY_H
#define DBENTITY_H

#include <QHash>
#include <QString>
#include <QVariant>



class DbEntity
{
public:
    dbEntity();

    static QString ID;
    static QString Name;
    QString name() const;
    void setName(const QString &name);

    unsigned int id() const;
    void setId(unsigned int id);

    QHash<QString, QVariant> dbValues();

private:
    QString m_name;
    unsigned int m_id;
    QHash<QString,QVariant> m_dbValues;

    virtual QHash<QString,QVariant> dbValuesImplementation()=0;
};

#endif // DBENTITY_H
