#include "AddPreparation.h"
#include "ui_AddPreparation.h"

AddPreparation::AddPreparation(QString idPreparation, QWidget *parent) : QDialog(parent),
    ui(new Ui::AddPreparation)
{
    ui->setupUi(this);
    
    ui->sboxCost->setLocale(QLocale::c());
    
    
    foreach (Provider item, Provider::getProviderList())
    {
        ui->cboxProviders->addItem(item.getName());
    }
    
    if(idPreparation != "")
    {
        ui->pbAdd->setText("Обновить");
        
        mIdUpdPreparation = idPreparation;
        
        ui->cboxProviders->setDisabled(true);
        
        m_preparation = new Preparation();
        
        ui->leNamePreparation->setText(m_preparation->load(mIdUpdPreparation).at(0));
        ui->sboxNumber->setValue(m_preparation->load(mIdUpdPreparation).at(1).toInt());
        ui->sboxCost->setValue(m_preparation->load(mIdUpdPreparation).at(2).toDouble());
        ui->teditLabelPreparation->setPlainText(m_preparation->load(mIdUpdPreparation).at(3));
        ui->cboxProviders->setCurrentText(m_preparation->load(mIdUpdPreparation).at(4));
    }
}

AddPreparation::~AddPreparation()
{
    delete ui;
}

void AddPreparation::on_pbCancel_clicked()
{
    this->close();
}

void AddPreparation::on_pbAdd_clicked()
{
    m_preparation = new Preparation(ui->leNamePreparation->text(),
                                    ui->sboxNumber->text(),
                                    ui->sboxCost->text(),
                                    ui->teditLabelPreparation->toPlainText(),
                                    ui->cboxProviders->currentText());
    
    if(ui->pbAdd->text() == "Добавить")
    {
        if(ui->leNamePreparation->text().isEmpty() || ui->teditLabelPreparation->toPlainText().isEmpty() || 
          (ui->sboxCost->value() == 0) || (ui->sboxNumber->value() == 0))
        {
            QMessageBox::information(0, "Информация", "Заполните все поля");
        }
        else
        {
            if(m_preparation->save())
            {
                emit preparationAdded();
                
                this->close();
            }
        }
    }
    else
    {
        if(ui->leNamePreparation->text().isEmpty() || ui->teditLabelPreparation->toPlainText().isEmpty() || 
          (ui->sboxCost->value() == 0) || (ui->sboxNumber->value() == 0))
        {
            QMessageBox::information(0, "Информация", "Заполните все поля");
        }
        else
        {
            if(m_preparation->edit(mIdUpdPreparation))
            {
                emit preparationAdded();
                
                this->close();
            }
        }
    }
}
