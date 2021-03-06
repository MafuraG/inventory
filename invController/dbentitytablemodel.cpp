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

void DbEntityTableModel::setHeaders(const QVector<QString> &headers)
{
    m_headers = headers;
}

QVector<QString> DbEntityTableModel::getHeaders() const {
    return m_headers;
}

QVariant DbEntityTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole){
        return getHeaders()[section];
    }

    return QVariant();
}

bool DbEntityTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    bool success = true;
    if (row < 0 || row > rowCount()) return false;

    beginInsertRows(parent, row, row + count - 1);
    for(int i = row; i < row + count; i++){
        DbEntity *entity = newDbEntity();
        m_entityList.insert(i,entity);
        if (getEmitSignal() == true) emit EntityCreated(entity);
        //qDebug()<<"row inserted row:"<<i;
    }
    endInsertRows();

    return success;
}

bool DbEntityTableModel::inRange(int row){
    if (row < 0 || row > (rowCount() -1)) return false;

    return true;
}

bool DbEntityTableModel::getEmitSignal() const
{
    return m_emitSignal;
}

void DbEntityTableModel::setEmitSignal(bool emitSignal)
{
    m_emitSignal = emitSignal;
}

bool DbEntityTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    bool success = true;

    if (row < 0 || row > (rowCount() - 1)) return false;

    beginRemoveRows(parent, row, row + count - 1);
    for(int i = row; i < row + count; i++){
        //qDebug()<<"Removed row at : "<< i;
        //delete m_entityList[row];
        DbEntity *entity = getDbEntity(row);
        if (getEmitSignal() == true) emit EntityDeleted(entity);
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

void DbEntityTableModel::addDbEntity(DbEntity *entity)
{
    if (entity == nullptr){
        insertRow(rowCount());
    }else{
        setEmitSignal(false);
        insertRow(rowCount());
        DbEntity* e_new = getDbEntity(rowCount() - 1);
        e_new->setDbValues(entity->dbValues());
        setEmitSignal(true);
    }

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
