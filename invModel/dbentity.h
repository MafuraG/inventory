#ifndef DBENTITY_H
#define DBENTITY_H

#include <QHash>
#include <QString>



class dbEntity
{
public:
    dbEntity();

    static QString ID;
    static QString Name;
    QString name() const;
    void setName(const QString &name);

    unsigned int id() const;
    void setId(unsigned int id);

    QHash<QString, QString> dbValues() const;
    void setDbValues(const QHash<QString, QString> &dbValues);

private:
    QString m_name;
    unsigned int m_id;
    QHash<QString,QString> m_dbValues;
};

#endif // DBENTITY_H
