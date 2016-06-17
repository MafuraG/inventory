#ifndef CARTMODEL_H
#define CARTMODEL_H

#include "dbentity.h"



class InventoryModel: public dbEntity
{

public:
    static QString MAN_ID;
    InventoryModel();
    unsigned int manId() const;
    void setManId(unsigned int manId);

private:
    unsigned int m_manId;

    // dbEntity interface
public:
    QHash<QString, QString> dbValues();
};

#endif // CARTMODEL_H
