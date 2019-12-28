#include "AddOrder.h"
#include "ui_AddOrder.h"

AddOrder::AddOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddOrder)
{
    ui->setupUi(this);
    
    ui->cboxPreparation->addItem("-");
    
    foreach (Preparation item, Preparation::getPreparationList())
    {
        ui->cboxPreparation->addItem(item.getName());
    }
}

AddOrder::~AddOrder()
{
    delete ui;
}

void AddOrder::on_pbCancel_clicked()
{
    this    ->close();
}

void AddOrder::on_cboxPreparation_currentTextChanged(const QString &arg1)
{
    if(arg1 == "-")
    {
        ui->spinNumber->setValue(0);
        ui->pbAdd->setDisabled(true);
    }
    else
    {
        // Ограничиваем числом препарата имеющегося на складе
        ui->spinNumber->setMaximum(Preparation::getPreparationList().at(ui->cboxPreparation->currentIndex()-1).getNumber().toInt());
        
        if(ui->spinNumber->value() != 0)
        {
            ui->pbAdd->setEnabled(true);
        }
    }
}

void AddOrder::on_spinNumber_valueChanged(int arg1)
{
    if(arg1 == 0)
    {
        ui->pbAdd->setDisabled(true);
    }
    else
    {
        if(ui->cboxPreparation->currentText() != "-")
        {
            ui->pbAdd->setEnabled(true);
        }
    }
}

void AddOrder::on_pbAdd_clicked()
{
    emit preparationAdded(Preparation(Preparation::getPreparationList().at(ui->cboxPreparation->currentIndex()-1).getName(),
                                      ui->spinNumber->text(),
                                      Preparation::getPreparationList().at(ui->cboxPreparation->currentIndex()-1).getPrice(),
                                      Preparation::getPreparationList().at(ui->cboxPreparation->currentIndex()-1).getInfo(),
                                      Preparation::getPreparationList().at(ui->cboxPreparation->currentIndex()-1).getId_provider()));
    this->close();
}




