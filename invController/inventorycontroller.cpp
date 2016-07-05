#include "inventorycontroller.h"


InventoryController::InventoryController(const QString dbType, const QString dbPath )
{
    SQLDataContext *ctx = new SQLDataContext(dbType,dbPath);

    InventoryTableModel *imodel = new InventoryTableModel();
    JournalTableModel *jmodel = new JournalTableModel();

    setCtx(ctx);
    setJModel(jmodel);
    setInvModel(imodel);
}

JournalTableModel *InventoryController::jModel() const
{
    return m_jModel;
}

void InventoryController::setJModel(JournalTableModel *jModel)
{
    m_jModel = jModel;
}

InventoryTableModel *InventoryController::invModel() const
{
    return m_invModel;
}

void InventoryController::setInvModel(InventoryTableModel *invModel)
{
    m_invModel = invModel;
}

SQLDataContext *InventoryController::ctx() const
{
    return m_ctx;
}

void InventoryController::setCtx(SQLDataContext *ctx)
{
    m_ctx = ctx;
}

void InventoryController::addInventory()
{
    invModel()->addDbEntity();
}

void InventoryController::addJournal()
{
    jModel()->addDbEntity();
}
