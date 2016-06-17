#ifndef CARTMODEL_H
#define CARTMODEL_H

#include "dbentity.h"



class InventoryDetail: public dbEntity
{

public:
    static QString MAN_ID;
    static QString ENTITYNAME;
    InventoryDetail();
    unsigned int manId() const;
    void setManId(unsigned int manId);

private:
    unsigned int m_manId;

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // CARTMODEL_H
