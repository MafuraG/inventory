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

    int current_jrow() const;
    void setCurrent_jrow(int current_jrow);

    int current_invrow() const;
    void setCurrent_invrow(int current_invrow);

private slots:
    void on_btnAddEntry_clicked();

    void on_btnAddItem_clicked();

    void on_tvInventory_clicked(const QModelIndex &index);

    void on_btnRemoveItem_clicked();

    void on_btnRemoveEntry_clicked();

    void on_tvJournal_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    InventoryController *m_invController;


    static QString INVDBNAME;
    int m_current_jrow = -1;
    int m_current_invrow = -1;
};

#endif // MAINWINDOW_H
