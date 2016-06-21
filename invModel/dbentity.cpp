#include "dbentity.h"

DbEntity::dbEntity()
{

}

QString DbEntity::ID = "id_";
QString DbEntity::Name= "name_";

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



