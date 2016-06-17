#include <QString>
#include <QtTest>
#include <organisation.h>

class InvModelTest : public QObject
{
    Q_OBJECT

public:
    InvModelTest();

private Q_SLOTS:
    void organisationTest();
    void orgdbvaluesTest();
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

QTEST_APPLESS_MAIN(InvModelTest)

#include "tst_invmodeltest.moc"
