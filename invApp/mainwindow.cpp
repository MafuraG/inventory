#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

QString MainWindow::INVDBNAME = "invdb.sqlite";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!QSqlDatabase::drivers().contains("QSQLITE")){
        QMessageBox::critical(this,"Program cannot start","Sqlite driver not present");
        this->close();
    }
    QString dbname = QString("%0/%1").arg(qApp->applicationDirPath(),MainWindow::INVDBNAME);
    setInvController(new InventoryController("QSQLITE",dbname));

    ui->tvInventory->setModel(invController()->invModel());
    ui->tvJournal->setModel(invController()->jModel());

}

MainWindow::~MainWindow()
{
    delete ui;
}

InventoryController *MainWindow::invController() const
{
    return m_invController;
}

void MainWindow::setInvController(InventoryController *invController)
{
    m_invController = invController;
}

void MainWindow::on_btnAddEntry_clicked()
{
    //Journal entry
    invController()->addJournal();
}

void MainWindow::on_btnAddItem_clicked()
{
    //Inventory
    invController()->addInventory();
}
