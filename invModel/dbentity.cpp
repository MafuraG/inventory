#include "dbentity.h"

dbEntity::dbEntity()
{

}

QString dbEntity::ID = "id_";
QString dbEntity::Name= "name_";

QString dbEntity::name() const
{
    return m_name;
}

void dbEntity::setName(const QString &name)
{
    m_name = name;
}

unsigned int dbEntity::id() const
{
    return m_id;
}

void dbEntity::setId(unsigned int id)
{
    m_id = id;
}



