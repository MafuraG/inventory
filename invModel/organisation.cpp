#include "organisation.h"
QString Organisation::ADDRESS = "address_";
QString Organisation::TELEPHONE = "telephone_";
QString Organisation::ENTITYNAME = "organisation";

Organisation::Organisation()
{

}

QString Organisation::address() const
{
    return m_address;
}

void Organisation::setAddress(const QString &address)
{
    m_address = address;
}

QString Organisation::telephone() const
{
    return m_telephone;
}

void Organisation::setTelephone(const QString &telephone)
{
    m_telephone = telephone;
}

QHash<QString, QVariant> Organisation::dbValuesImplementation()
{
    QHash<QString,QVariant> keyVals;
    keyVals[ADDRESS] = address();
    keyVals[TELEPHONE] = telephone();
    keyVals[Name] = name();
    keyVals[ID] = id();
    return keyVals;
}

QString Organisation::getEntityNameImplementation()
{
    return Organisation::ENTITYNAME;
}

void Organisation::setDbValuesImplementation(const QHash<QString, QVariant> &dbValues)
{
    if (dbValues.count() > 0) {
        setId(dbValues[ID].toUInt());
        setName(dbValues[Name].toString());
        setAddress(dbValues[ADDRESS].toString());
        setTelephone(dbValues[TELEPHONE].toString());
    }
}

QVariant Organisation::dataImplementation(const unsigned int col)
{
    QHash<QString, QVariant> dBvalues = dbValues();
    if (col == 0 ){
        //ID
        return dBvalues[ID];
    }
    if (col == 1 ){
        //Name
        return dBvalues[Name];
    }

    if (col == 2){
        //Address
        return dBvalues[ADDRESS];
    }

    if (col == 3){
        //Telephone
        return dBvalues[TELEPHONE];
    }

    return QVariant();

}

bool Organisation::setDataImplementation(const unsigned int col, QVariant value)
{
    QHash<QString, QVariant> dBvalues = dbValues();
    bool success = false;
    if (col == 0 ){
        //ID
        dBvalues[ID] = value;
        success = true;
    }
    if (col == 1 ){
        //Name
        dBvalues[Name] = value;
        success = true;
    }

    if (col == 2){
        //Address
        dBvalues[ADDRESS] = value;
    }

    if (col == 3){
        //Telephone
        dBvalues[TELEPHONE] = value;
    }

    if (success == true) {
        setDbValues(dBvalues);
    }


    return success;
}


