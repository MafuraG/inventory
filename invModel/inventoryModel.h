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
};

#endif // CARTMODEL_H
