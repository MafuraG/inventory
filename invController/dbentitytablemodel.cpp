#include "dbentitytablemodel.h"
#include <QDebug>
#include <dbentity.h>

DbEntityTableModel::DbEntityTableModel()
{
    //setEntityName(entityName);
}

int DbEntityTableModel::rowCount(const QModelIndex &parent) const
{
    return m_entityList.count();
}

int DbEntityTableModel::columnCount(const QModelIndex &parent) const
{
    //return columnCount();
    int col = getHeaders().count();
    return col;
}

QVariant DbEntityTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    DbEntity *item = getItem(index);

    if (item == nullptr) return QVariant();

    return item->data(index.column());
}

bool DbEntityTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole) return false;

    DbEntity *item = getItem(index);
    bool result = item->setData(index.column(),value);

    if (result){
        emit dataChanged(index,index);
    }

    return result;
}

QVariant DbEntityTableModel::headerData(int section, Qt::Orientation orientation, int role)
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return headerImplementation(section);
    }

    return QVariant();
}

void DbEntityTableModel::setHeaders(const QVector<QString> &headers)
{
    m_headers = headers;
}

QVector<QString> DbEntityTableModel::getHeaders() const {
    return m_headers;
}

QVariant DbEntityTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return headerData(section,orientation,role);
}

bool DbEntityTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    bool success = true;

    beginInsertRows(parent, row, row + count - 1);
    for(int i = row; i < row + count; i++){
        DbEntity *entity = newDbEntity();
        m_entityList.insert(i,entity);
        //qDebug()<<"row inserted row:"<<i;
    }
    endInsertRows();

    return success;
}

bool DbEntityTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    bool success = true;

    beginRemoveRows(parent, row, row + count - 1);
    for(int i = row; i < row + count; i++){
        //qDebug()<<"Removed row at : "<< i;
        delete m_entityList[row];
        m_entityList.removeAt(row);        
    }
    endRemoveRows();
    //qDebug()<<"Success! rows removed";
    return success;
}

Qt::ItemFlags DbEntityTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
            return 0;

        return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

QString DbEntityTableModel::entityName() const
{
    return m_entityName;
}

void DbEntityTableModel::setEntityName(const QString &entityName)
{
    m_entityName = entityName;
}

DbEntity *DbEntityTableModel::getDbEntity(const unsigned int row)
{
    if (row < rowCount())
            return m_entityList[row];

    return nullptr;
}

QList<DbEntity *> DbEntityTableModel::getEntityList() const
{
    return m_entityList;
}

DbEntity *DbEntityTableModel::newDbEntity()
{
    return newDbEntityImplementation();
}

void DbEntityTableModel::removeDbEntity(const unsigned int row)
{
    removeRows(row,1);
}

DbEntity *DbEntityTableModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()){
        DbEntity *item = m_entityList[index.row()];
        if (item)
            return item;
    }
    return nullptr; //IMPORTANT: We have to check for null wherever we use this method
}
