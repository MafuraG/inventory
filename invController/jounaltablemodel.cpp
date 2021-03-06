#include "jounaltablemodel.h"

#include <journal.h>

JournalTableModel::JournalTableModel()
{
    QVector<QString> headers;
    headers.append(Journal::ID);
    headers.append(Journal::Name);
    headers.append(Journal::INVENTORYID);
    headers.append(Journal::DATE);
    headers.append(Journal::STATUSID);
    headers.append(Journal::COMMENT);
    setHeaders(headers);
}

QVariant JournalTableModel::headerImplementation(const unsigned int col)
{
    QVector<QString> headers = getHeaders();
    if (col <headers.count()) return headers[col];

    return QVariant();
}

DbEntity *JournalTableModel::newDbEntityImplementation()
{
    DbEntity *entity = new Journal();
    return entity;
}


