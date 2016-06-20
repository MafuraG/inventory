#ifndef DBENTITY_H
#define DBENTITY_H

#include <QHash>
#include <QString>



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

    virtual QHash<QString, QString> dbValues() = 0;

private:
    QString m_name;
    unsigned int m_id;
    QHash<QString,QString> m_dbValues;
};

#endif // DBENTITY_H
