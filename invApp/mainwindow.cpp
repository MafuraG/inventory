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

void MainWindow::on_tvInventory_clicked(const QModelIndex &index)
{
    //set current Inventory
    if (index.isValid()) setCurrent_invrow(index.row());
    else setCurrent_invrow(-1);
}

int MainWindow::current_invrow() const
{
    return m_current_invrow;
}

void MainWindow::setCurrent_invrow(int current_invrow)
{
    m_current_invrow = current_invrow;
}

int MainWindow::current_jrow() const
{
    return m_current_jrow;
}

void MainWindow::setCurrent_jrow(int current_jrow)
{
    m_current_jrow = current_jrow;
}


void MainWindow::on_btnRemoveItem_clicked()
{
    //remove Inventory Item
    if (current_invrow() != -1) invController()->deleteInventory(current_invrow());
}

void MainWindow::on_btnRemoveEntry_clicked()
{
    if (current_jrow() != -1) invController()->deleteJournal(current_jrow());
}

void MainWindow::on_tvJournal_clicked(const QModelIndex &index)
{
    if (index.isValid()) setCurrent_jrow(index.row());
    else setCurrent_jrow(-1);
}
