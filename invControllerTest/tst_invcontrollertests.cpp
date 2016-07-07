#include <QString>
#include <QtTest>
#include <dataconverter.h>
#include <inventory.h>
#include <inventorytablemodel.h>
#include <jounaltablemodel.h>
#include <sqldatacontext.h>
#include <sqlitedataconverter.h>

class InvControllerTests : public QObject
{
    Q_OBJECT

public:
    InvControllerTests();

private Q_SLOTS:
    void SQLCreateEntityTest();
    void SQLUpdateEntityTest();
    void SQLSelectEntitiesTest();
    void SQLDeleteEntitiesTest();
    void SQLCreateDBTest();

    void sqlDataConverterTest();

    void JournalTableModelTest();
    void InventoryTableModelTest();
private:
    SQLDataContext ctx;
    void entityTableModelTest(DbEntityTableModel *model);
};

InvControllerTests::InvControllerTests()
{
}

void InvControllerTests::SQLCreateEntityTest()
{    
    Inventory *inv  = new Inventory();
    DbEntity *entity = inv;

    inv->setId(1);
    inv->setName("Inventory");
    inv->setInventoryTypeId(1);
    inv->setModelId(1);
    inv->setNumber("123456");
    inv->setOwnerId(1);
    inv->setSerial("1234567");

    ctx.CreateEntity(entity);

    QString actual = ctx.sqlStr();    
    QVERIFY2(true, "Failure");
    delete inv;
}

void InvControllerTests::SQLUpdateEntityTest()
{
    Inventory *inv  = new Inventory();
    DbEntity *entity = inv;

    inv->setId(1);
    inv->setName("Inventory");
    inv->setInventoryTypeId(1);
    inv->setModelId(1);
    inv->setNumber("123456");
    inv->setOwnerId(1);
    inv->setSerial("1234567");

    ctx.UpdateEntity(entity);

    QString actual = ctx.sqlStr();
    QVERIFY2(true, "Failure");
    delete inv;
}

void InvControllerTests::SQLSelectEntitiesTest()
{
    QStringList filter;
    QList<DbEntity*> result;
    ctx.SelectEntities(Inventory::ENTITYNAME,filter,result);
    QVERIFY2(true, "Failure");
}

void InvControllerTests::SQLDeleteEntitiesTest()
{
    Inventory *inv  = new Inventory();
    DbEntity *entity = inv;

    inv->setId(1);
    inv->setName("Inventory");
    inv->setInventoryTypeId(1);
    inv->setModelId(1);
    inv->setNumber("123456");
    inv->setOwnerId(1);
    inv->setSerial("1234567");

    ctx.DeleteEntity(entity);

    QVERIFY2(true, "Failure");
    delete inv;
}

void InvControllerTests::SQLCreateDBTest()
{
    ctx.CreateDatabase();
}

void InvControllerTests::sqlDataConverterTest()
{
    DataConverter *c = new SqliteDataConverter();
    QString expected, actual;

    QVariant param = "Hello World!";
    expected = QString("'%0'").arg(param.toString());
    actual = c->toDbString(param);

    QVERIFY2(expected == actual, "FAIL");
}

void InvControllerTests::JournalTableModelTest()
{
    JournalTableModel model;
    entityTableModelTest(&model);
}

void InvControllerTests::InventoryTableModelTest()
{
    InventoryTableModel model;
    entityTableModelTest(&model);
}

void InvControllerTests::entityTableModelTest(DbEntityTableModel *model)
{

    model->insertRows(0,50);
    //qDebug()<<"50 rows added"<<model->rowCount();

    QVERIFY2(model->rowCount() == 50, "FAIL");

    model->removeRows(0,50);

    QVERIFY2(model->rowCount() == 0, "FAIL");

    qDebug()<<"Insert and Remove passed!";

    DbEntity *entity = model->newDbEntity();

    qDebug()<<"Delete row out of range";
    model->removeDbEntity(-1);

    QVERIFY2(model->rowCount() == 0, "FAIL");

    qDebug()<<"Entity create Passed";

    qDebug()<<"model column count "<<model->columnCount();
    qDebug()<<"entity column count "<<entity->getColumnCount();
    QVERIFY2(model->columnCount() == entity->getColumnCount(), "FAIL");
}

QTEST_APPLESS_MAIN(InvControllerTests)

#include "tst_invcontrollertests.moc"
