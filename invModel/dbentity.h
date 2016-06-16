#ifndef DBENTITY_H
#define DBENTITY_H

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

private:
    QString m_name;
    unsigned int m_id;
};

#endif // DBENTITY_H
