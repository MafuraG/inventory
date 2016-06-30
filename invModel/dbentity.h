#ifndef DBENTITY_H
#define DBENTITY_H

#include <QHash>
#include <QString>
#include <QVariant>
#include <QVector>



class DbEntity
{
public:
    DbEntity();
    virtual ~DbEntity();

    static QString ID;
    static QString Name;
    QString name() const;
    void setName(const QString &name);

    unsigned int id() const;
    void setId(unsigned int id);

    QHash<QString, QVariant> dbValues();
    void setDbValues(const QHash<QString, QVariant> &dbValues);
    QString getEntityName();
    unsigned int getColumnCount();
    QVariant data(const unsigned int col);
    bool setData(const unsigned int col, QVariant value);


private:
    QString m_name;
    unsigned int m_id;
    QHash<QString,QVariant> m_dbValues;
    QVector<QString> m_headers;

    virtual QHash<QString,QVariant> dbValuesImplementation() = 0;
    virtual void setDbValuesImplementation(const QHash<QString, QVariant> &dbValues) = 0;
    virtual QString getEntityNameImplementation() = 0;
    virtual QVariant dataImplementation(const unsigned int col) = 0;
    virtual bool setDataImplementation(const unsigned int col, QVariant value) = 0;    
};

#endif // DBENTITY_H
