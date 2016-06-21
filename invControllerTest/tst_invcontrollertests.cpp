#include <QString>
#include <QtTest>
#include <inventory.h>
#include <sqldatacontext.h>

class InvControllerTests : public QObject
{
    Q_OBJECT

public:
    InvControllerTests();

private Q_SLOTS:
    void SQLCreateEntityTest();
};

InvControllerTests::InvControllerTests()
{
}

void InvControllerTests::SQLCreateEntityTest()
{
    SQLDataContext ctx;
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
    QString expected = "INSERT OR REPLACE  INTO inventory ( number, model_id , serial_number , id_ , inventory_type_id , owner_id , name_  ) VALUES ( , 812045144 ,  , 140 , 10617028 , 17260 ,   ) ";
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(InvControllerTests)

#include "tst_invcontrollertests.moc"
