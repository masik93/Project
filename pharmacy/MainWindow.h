#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTimer>
#include <QList>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QPushButton>
#include<QProcess>
#include "Adduser.h"
#include "AddProvider.h"
#include "AddPreparation.h"
#include "AddOrder.h"
#include "User.h"
#include "CheckWindow.h"
#include <QApplication>
#include <QProcess>
#include "TableModelPreparation.h"
#include "TableModelOther.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    Ui::MainWindow *ui;
    
    User                    *m_user = nullptr;
    TableModelOther         modelClientsLoad;
    TableModelOther         modelProvidersLoad;
    TableModelPreparation   modelPrepapration;
    QString                 strSelectedUserID;
    QString                 strSelectedProviderID;
    QString                 strSelectedPreparationID;
    // Индекс строки с удаляемым препаратом (Вкладка "Main")
    int                     strSelectedPreparationRow;
    // Сумма покупки
    double                  m_summ{};
    // id последнего чека
    QString                 strLastCheckId;
    
    QList<Preparation>      *m_lstPreparation = nullptr;
    QStandardItemModel      * m_modelMain;
    CheckWindow             *cWin;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void show(User *user);
private slots:

    void on_reset_button_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_tableViewClients_clicked(const QModelIndex &index);
    void on_pbAddUser_clicked();
    void on_pbDeleteUser_clicked();
    void loadTableClients();
    void on_tableViewClients_doubleClicked(const QModelIndex &index);
    void on_tableViewProviders_clicked(const QModelIndex &index);
    void on_tableViewProviders_doubleClicked(const QModelIndex &index);
    void on_pbAddProvider_clicked();
    void on_pbDeleteProvider_clicked();
    void loadTableProviders();
    void on_pbDeletePreparation_clicked();
    void on_tableViewPreparationInfo_clicked(const QModelIndex &index);
    void on_tableViewPreparationInfo_doubleClicked(const QModelIndex &index);
    void on_pbAddPreparation_clicked();
    void loadTablePreparation();
    void on_pbAddToOrder_clicked();
    void addToOrderList(Preparation);
    void loadTableMain();
    void on_pbToPay_clicked();
    void on_tableViewMain_clicked(const QModelIndex &index);
    void on_pbRemoveFromOrder_clicked();
    void on_cboxClient_currentIndexChanged(int index);
    void calculateSum(QList<Preparation> * lstPrep);



};

#endif // MAINWINDOW_H
