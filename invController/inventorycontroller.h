#ifndef INVCONTROLLER_H
#define INVCONTROLLER_H

#include "inventorytablemodel.h"
#include "jounaltablemodel.h"
#include "sqldatacontext.h"

#include <QString>



class InventoryController
{

public:
    InventoryController(const QString dbType, const QString dbPath );

    JournalTableModel *jModel() const;
    void setJModel(JournalTableModel *jModel);

    InventoryTableModel *invModel() const;
    void setInvModel(InventoryTableModel *invModel);

    SQLDataContext *ctx() const;
    void setCtx(SQLDataContext *ctx);

    void addInventory();
    void deleteInventory(const unsigned int row);
    void addJournal();
    void deleteJournal(const unsigned int row);

private:
    JournalTableModel *m_jModel;
    InventoryTableModel *m_invModel;

    SQLDataContext *m_ctx;
};

#endif // INVCONTROLLER_H
