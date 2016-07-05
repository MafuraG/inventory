#ifndef DBENTITYTABLEMODEL_H
#define DBENTITYTABLEMODEL_H

#include <QAbstractTableModel>
#include <dbentity.h>



class DbEntityTableModel:public QAbstractTableModel
{
public:
    DbEntityTableModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex())  const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;

    QString entityName() const;
    void setEntityName(const QString &entityName);

    DbEntity *getDbEntity(const unsigned int row);

    QList<DbEntity *> getEntityList() const;

    void addDbEntity();
    DbEntity *newDbEntity();
    void removeDbEntity(const unsigned int row);

    QVector<QString> getHeaders() const;
    void setHeaders(const QVector<QString> &headers);

private:
    DbEntity *getItem(const QModelIndex &index) const;
    QList<DbEntity*> m_entityList;
    QString m_entityName;
    virtual QVariant headerImplementation(const unsigned int col) = 0;
    virtual DbEntity *newDbEntityImplementation() = 0;    

    QVector<QString> m_headers;
};

#endif // DBENTITYTABLEMODEL_H
