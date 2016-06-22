#include <QString>
#include <QtTest>
#include <dataconverter.h>
#include <inventory.h>
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

    void sqlDataConverterTest();
private:
    SQLDataContext ctx;
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

void InvControllerTests::sqlDataConverterTest()
{
    DataConverter *c = new SqliteDataConverter();
    QString expected, actual;

    QVariant param = "Hello World!";
    expected = QString("'%0'").arg(param.toString());
    actual = c->toString(param);

    QVERIFY2(expected == actual, "FAIL");
}

QTEST_APPLESS_MAIN(InvControllerTests)

#include "tst_invcontrollertests.moc"
