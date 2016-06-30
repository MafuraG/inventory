#include "dbentity.h"


QString DbEntity::ID = "id";
QString DbEntity::Name= "name_";

DbEntity::DbEntity()
{

}

DbEntity::~DbEntity()
{

}

QString DbEntity::name() const
{
    return m_name;
}

void DbEntity::setName(const QString &name)
{
    m_name = name;
}

unsigned int DbEntity::id() const
{
    return m_id;
}

void DbEntity::setId(unsigned int id)
{
    m_id = id;
}

QHash<QString, QVariant> DbEntity::dbValues()
{
    return dbValuesImplementation();
}

QString DbEntity::getEntityName()
{
    return getEntityNameImplementation();
}

unsigned int DbEntity::getColumnCount()
{
    return dbValues().count();
}

QVariant DbEntity::data(const unsigned int col)
{
    return dataImplementation(col);
}

bool DbEntity::setData(const unsigned int col, QVariant value)
{
    return setDataImplementation(col,value);
}

void DbEntity::setDbValues(const QHash<QString, QVariant> &dbValues)
{    
    setDbValuesImplementation(dbValues);
}




