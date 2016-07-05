#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <inventorycontroller.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:    
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    InventoryController *invController() const;
    void setInvController(InventoryController *invController);

private slots:
    void on_btnAddEntry_clicked();

    void on_btnAddItem_clicked();

private:
    Ui::MainWindow *ui;

    InventoryController *m_invController;


    static QString INVDBNAME;
};

#endif // MAINWINDOW_H
