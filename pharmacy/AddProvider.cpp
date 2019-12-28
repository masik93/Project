#include "AddProvider.h"
#include "ui_AddProvider.h"

AddProvider::AddProvider(QString idProvider, QWidget *parent) : QDialog(parent),
    ui(new Ui::AddProvider)
{
    ui->setupUi(this);
    
    QRegExp rx("[0-9]{9}");
    validator = new QRegExpValidator(rx, this);
    ui->leUNN->setValidator(validator);
    
    if(idProvider != "")
    {
        ui->pbAdd->setText("Обновить");
        
        m_idUpdProvider = idProvider;
        
        m_provider = new Provider(ui->leName->text(),
                                  ui->leAddress->text(),
                                  ui->lePhone->text(),
                                  ui->leUNN->text());
        
        QStringList lstFormData = m_provider->load(m_idUpdProvider);
        
        ui->leName->setText(lstFormData.at(0));
        ui->leAddress->setText(lstFormData.at(1));
        ui->lePhone->setText(lstFormData.at(2));
        ui->leUNN->setText(lstFormData.at(3));
    }
}

AddProvider::~AddProvider()
{
    delete ui;
    
    delete m_provider, validator;
}

void AddProvider::on_pbAdd_clicked()
{ 
    m_provider = new Provider(ui->leName->text(),
                              ui->leAddress->text(),
                              ui->lePhone->text(),
                              ui->leUNN->text());
    
    if(ui->pbAdd->text() == "Добавить")
    {
        m_provider->save();
    }
    else
    {
        m_provider->edit(m_idUpdProvider);
    }
    
    emit providerAdded();
    
    this->close();
}

void AddProvider::on_pbCancel_clicked()
{
    this->close();
}
