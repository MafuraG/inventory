#include <QString>
#include <QtTest>
#include <inventory.h>
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
    QHash<QString,QString> dbval_exp, dbval_actual;
    actual.setId(1);
    actual.setName("org1");
    actual.setAddress("Xyz");
    actual.setTelephone("123456");

    dbval_actual = actual.dbValues();

    dbval_exp[Organisation::ADDRESS] = QString("%0").arg("Xyz");
    dbval_exp[Organisation::TELEPHONE] = QString("%0").arg("123456");
    dbval_exp[Organisation::Name] = QString("%0").arg("org1");
    dbval_exp[Organisation::ID] = QString("%0").arg(1);

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
    QHash<QString,QString> dbval_exp, dbval_actual;
    actual.setId(1);
    actual.setName("man1");


    dbval_actual = actual.dbValues();

    dbval_exp[Manufacturer::Name] = QString("%0").arg("man1");
    dbval_exp[Manufacturer::ID] = QString("%0").arg(1);


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

}

QTEST_APPLESS_MAIN(InvModelTest)

#include "tst_invmodeltest.moc"
