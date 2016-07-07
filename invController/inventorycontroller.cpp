#include "inventorycontroller.h"

#include <inventory.h>


InventoryController::InventoryController(const QString dbType, const QString dbPath )
{
    SQLDataContext *ctx_ = new SQLDataContext(dbType,dbPath);

    InventoryTableModel *imodel = new InventoryTableModel();
    JournalTableModel *jmodel = new JournalTableModel();

    setCtx(ctx_);
    setJModel(jmodel);
    setInvModel(imodel);

    ctx()->CreateDatabase();

    connect(imodel,&InventoryTableModel::EntityCreated,ctx_,&SQLDataContext::onEntityCreated);
    connect(jmodel,&JournalTableModel::EntityCreated,ctx_,&SQLDataContext::onEntityCreated);

    connect(imodel,&InventoryTableModel::EntityDeleted,ctx_,&SQLDataContext::onEntityDeleted);
    connect(jmodel,&JournalTableModel::EntityDeleted,ctx_,&SQLDataContext::onEntityDeleted);

    loadDataFromDB(imodel);
    loadDataFromDB(jmodel);
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

void InventoryController::deleteInventory(const unsigned int row)
{
    invModel()->removeDbEntity(row);
}

void InventoryController::addJournal()
{
    jModel()->addDbEntity();
}

void InventoryController::deleteJournal(const unsigned int row)
{
    jModel()->removeDbEntity(row);
}

void InventoryController::loadDataFromDB(DbEntityTableModel *model)
{
    DbEntity *entity = model->newDbEntity();
    QList<DbEntity*> list;
    QStringList filter;
    ctx()->SelectEntities(entity->getEntityName(),filter,list);

    for (int i = 0; i < list.count(); i++){
        model->addDbEntity(list[i]);
    }
}


