#include <QString>
#include <QtTest>
#include <inventory.h>
#include <journal.h>
#include <manufacturer.h>
#include <organisation.h>

class InvModelTest : public QObject
{
    Q_OBJECT

public:
    InvModelTest();

private Q_SLOTS:
    void organisationTest();
    void orgdbvaluesTest();

    void manufactureTest();
    void mandbvaluesTest();

    void inventoryTest();
    void invdbvaluesTest();

    void journalTest();
    void journaldbvaluesTest();
};

InvModelTest::InvModelTest()
{
}

void InvModelTest::organisationTest()
{
    Organisation expected, actual;
    expected.setId(1);
    expected.setName("org1");
    expected.setAddress("Xyz");
    expected.setTelephone("123456");

    actual.setId(1);
    actual.setName("org1");
    actual.setAddress("Xyz");
    actual.setTelephone("123456");

    QVERIFY2(expected.id() == actual.id(), "Failure");
    QVERIFY2(expected.name() == actual.name(), "Failure");
    QVERIFY2(expected.address() == actual.address(), "Failure");
    QVERIFY2(expected.telephone() == actual.telephone(), "Failure");
}

void InvModelTest::orgdbvaluesTest()
{
    Organisation actual;
    QHash<QString,QVariant> dbval_exp, dbval_actual;
    actual.setId(1);
    actual.setName("org1");
    actual.setAddress("Xyz");
    actual.setTelephone("123456");

    dbval_actual = actual.dbValues();

    dbval_exp[Organisation::ADDRESS] = "Xyz";
    dbval_exp[Organisation::TELEPHONE] = "123456";
    dbval_exp[Organisation::Name] = "org1";
    dbval_exp[Organisation::ID] = 1;

    QVERIFY2( dbval_exp[Organisation::ADDRESS] == dbval_actual[Organisation::ADDRESS], "Failure");
    QVERIFY2(dbval_exp[Organisation::TELEPHONE] == dbval_actual[Organisation::TELEPHONE], "Failure");
    QVERIFY2(dbval_exp[Organisation::Name] == dbval_actual[Organisation::Name], "Failure");
    QVERIFY2(dbval_exp[Organisation::ID] == dbval_actual[Organisation::ID], "Failure");
}

void InvModelTest::manufactureTest()
{
    Manufacturer expected, actual;
    expected.setId(1);
    expected.setName("man1");

    actual.setId(1);
    actual.setName("man1");

    QVERIFY2(expected.id() == actual.id(), "Failure");
    QVERIFY2(expected.name() == actual.name(), "Failure");

}

void InvModelTest::mandbvaluesTest()
{
    Manufacturer actual;
    QHash<QString,QVariant> dbval_exp, dbval_actual;
    actual.setId(1);
    actual.setName("man1");


    dbval_actual = actual.dbValues();

    dbval_exp[Manufacturer::Name] = "man1";
    dbval_exp[Manufacturer::ID] = 1;


    QVERIFY2(dbval_exp[Manufacturer::Name] == dbval_actual[Manufacturer::Name], "Failure");
    QVERIFY2(dbval_exp[Manufacturer::ID] == dbval_actual[Manufacturer::ID], "Failure");
}

void InvModelTest::inventoryTest()
{
    Inventory expected, actual;
    expected.setId(1);
    expected.setName("inv1");
    expected.setInventoryTypeId(1);
    expected.setModelId(1);
    expected.setNumber("aaaaa");
    expected.setOwnerId(1);
    expected.setSerial("aaaaa");

    actual.setId(1);
    actual.setName("inv1");
    actual.setInventoryTypeId(1);
    actual.setModelId(1);
    actual.setNumber("aaaaa");
    actual.setOwnerId(1);
    actual.setSerial("aaaaa");

    QVERIFY2(expected.id() == actual.id(), "Failure");
    QVERIFY2(expected.name() == actual.name(), "Failure");
    QVERIFY2(expected.inventoryTypeId() == actual.inventoryTypeId(), "Failure");
    QVERIFY2(expected.modelId() == actual.modelId(), "Failure");
    QVERIFY2(expected.number() == actual.number(), "Failure");
    QVERIFY2(expected.ownerId() == actual.ownerId(), "Failure");
    QVERIFY2(expected.serial() == actual.serial(), "Failure");

}

void InvModelTest::invdbvaluesTest()
{
    Inventory actual;
    QHash<QString,QVariant> dbval_exp, dbval_actual;
    actual.setId(1);
    actual.setName("inv1");
    actual.setInventoryTypeId(1);
    actual.setModelId(1);
    actual.setNumber("12345");
    actual.setOwnerId(1);
    actual.setSerial("12345");


    dbval_actual = actual.dbValues();

    dbval_exp[Inventory::Name] = "inv1";
    dbval_exp[Inventory::ID] = 1;
    dbval_exp[Inventory::INVENTORYTYPEID] = 1;
    dbval_exp[Inventory::MODELID] = 1;
    dbval_exp[Inventory::NUMBER] = "12345";
    dbval_exp[Inventory::OWNERID] = 1;
    dbval_exp[Inventory::SERIAL] = "12345";


    QVERIFY2(dbval_exp[Inventory::Name] == dbval_actual[Inventory::Name], "Failure");
    QVERIFY2(dbval_exp[Inventory::ID] == dbval_actual[Inventory::ID], "Failure");
    QVERIFY2(dbval_exp[Inventory::INVENTORYTYPEID] == dbval_actual[Inventory::INVENTORYTYPEID], "Failure");
    QVERIFY2(dbval_exp[Inventory::MODELID] == dbval_actual[Inventory::MODELID], "Failure");
    QVERIFY2(dbval_exp[Inventory::NUMBER] == dbval_actual[Inventory::NUMBER], "Failure");
    QVERIFY2(dbval_exp[Inventory::OWNERID] == dbval_actual[Inventory::OWNERID], "Failure");
    QVERIFY2(dbval_exp[Inventory::SERIAL] == dbval_actual[Inventory::SERIAL], "Failure");
}

void InvModelTest::journalTest()
{
    Journal expected, actual;
    expected.setId(1);
    expected.setName("j1");
    expected.setInventoryID(1);
    expected.setComment("Comment");
    expected.setDate("Date");
    expected.setStatusID(1);

    actual.setId(1);
    actual.setName("j1");
    actual.setInventoryID(1);
    actual.setComment("Comment");
    actual.setDate("Date");
    actual.setStatusID(1);

    QVERIFY2(expected.id() == actual.id(), "Failure");
    QVERIFY2(expected.name() == actual.name(), "Failure");
    QVERIFY2(expected.inventoryID() == actual.inventoryID(), "Failure");
    QVERIFY2(expected.date() == actual.date(), "Failure");
    QVERIFY2(expected.comment() == actual.comment(), "Failure");
    QVERIFY2(expected.statusID() == actual.statusID(), "Failure");
}

void InvModelTest::journaldbvaluesTest()
{
    Journal actual;
    QHash<QString,QVariant> dbval_exp, dbval_actual;

    actual.setId(1);
    actual.setName("j1");
    actual.setInventoryID(1);
    actual.setComment("Comment");
    actual.setDate("Date");
    actual.setStatusID(1);


    dbval_actual = actual.dbValues();

    dbval_exp[Journal::Name] = "j1";
    dbval_exp[Journal::ID] = 1;
    dbval_exp[Journal::INVENTORYID] = 1;
    dbval_exp[Journal::COMMENT] = "Comment";
    dbval_exp[Journal::DATE] = "Date";
    dbval_exp[Journal::STATUSID] = 1;

    QVERIFY2(dbval_exp[Journal::Name] == dbval_actual[Journal::Name], "Failure");
    QVERIFY2(dbval_exp[Journal::ID] == dbval_actual[Journal::ID], "Failure");
    QVERIFY2(dbval_exp[Journal::INVENTORYID] == dbval_actual[Journal::INVENTORYID], "Failure");
    QVERIFY2(dbval_exp[Journal::COMMENT] == dbval_actual[Journal::COMMENT], "Failure");
    QVERIFY2(dbval_exp[Journal::DATE] == dbval_actual[Journal::DATE], "Failure");
    QVERIFY2(dbval_exp[Journal::STATUSID] == dbval_actual[Journal::STATUSID], "Failure");
}

QTEST_APPLESS_MAIN(InvModelTest)

#include "tst_invmodeltest.moc"
