#include "CheckWindow.h"
#include "ui_CheckWindow.h"

CheckWindow::CheckWindow(double sum, QString checlId, QList<Preparation> * lstPrep, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckWindow)
{
    ui->setupUi(this);
    
    QString str;
    str.setNum(sum);
    ui->lblSum->setText(str);
    
    QSqlQuery       queryGetCheckDate;
    QString         strGetCheckDate = "SELECT date from checks where id = " + checlId + ";";

    if(!queryGetCheckDate.exec(strGetCheckDate))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка формирования чека!");
    }
    
    QSqlRecord      recordGetCheckDate = queryGetCheckDate.record();      
    
    while (queryGetCheckDate.next())
    {
        ui->lblDate->setText(queryGetCheckDate.value(recordGetCheckDate.indexOf("date")).toString());
        ui->lblDate_2->setText(queryGetCheckDate.value(recordGetCheckDate.indexOf("date")).toString());
    }
    
    model = new QStandardItemModel(lstPrep->size(),3);
    
    model->setHeaderData(0,Qt::Horizontal,"Наименование\nпрепарата");
    model->setHeaderData(1,Qt::Horizontal,"Количество");
    model->setHeaderData(2,Qt::Horizontal,"Цена за ед.");
    //model->setHeaderData(3,Qt::Horizontal,"описание");

    
    for (int row = 0; row < lstPrep->size(); ++row)
    {
        QStandardItem *item1 = new QStandardItem((lstPrep->at(row).getName()));
        model->setItem(row, 0, item1);
        QStandardItem *item2 = new QStandardItem((lstPrep->at(row).getNumber()));
        model->setItem(row, 1, item2);
        QStandardItem *item3 = new QStandardItem((lstPrep->at(row).getPrice()));
        model->setItem(row, 2, item3);
        /*QStandardItem *item4 = new QStandardItem((lstPrep->at(row).getInfo()));
        model->setItem(row, 3, item4);
*/

    }
    
    ui->tableView->setModel(model);
    
    ui->tableView->setColumnWidth(0, 170);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 100);
   // ui->tableView->setColumnWidth(3,150);
}

CheckWindow::~CheckWindow()
{
    delete ui;
}
