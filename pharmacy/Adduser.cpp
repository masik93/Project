#include "Adduser.h"
#include "ui_Adduser.h"

AddUser::AddUser(QString id, QWidget *parent) : QDialog(parent), ui(new Ui::AddUser)
{
    ui->setupUi(this);
    
    mIdUpdUser = id;
    
    if(!id.isEmpty())
    {
        ui->pbAdd->setText("Обновить");
        
        /// Запрос основных данных о пользователе
        QSqlQuery       queryGetUserInfo;
        QString         strGetUserInfo = "SELECT surname, name, patronymic, login, password FROM User where id = '" + id + "';";
        
        if(!queryGetUserInfo.exec(strGetUserInfo))
        {
            QMessageBox::warning(nullptr, "Error ", "Ошибка получения данных о пользователе!");
        }
        
        QSqlRecord      recordGetUserInfo = queryGetUserInfo.record();      
        
        while (queryGetUserInfo.next())
        {
            ui->leSurname->setText(queryGetUserInfo.value(recordGetUserInfo.indexOf("surname")).toString());
            ui->leName->setText(queryGetUserInfo.value(recordGetUserInfo.indexOf("name")).toString());
            ui->lePatronymic->setText(queryGetUserInfo.value(recordGetUserInfo.indexOf("patronymic")).toString());
            ui->leLogin->setText(queryGetUserInfo.value(recordGetUserInfo.indexOf("login")).toString());
            ui->lePassword->setText(queryGetUserInfo.value(recordGetUserInfo.indexOf("password")).toString());
        }
        
        /// Запрос дополнительных данных о пользователе
        QSqlQuery       queryGetSecondClientInfo;
        QString         strGetSecondClientInfo = "SELECT phone FROM clients where id_user = '" + id + "';";
        
        if(queryGetSecondClientInfo.exec(strGetSecondClientInfo))
        {
            QSqlRecord      recordGetSecondClientInfo = queryGetSecondClientInfo.record();      
            
            while (queryGetSecondClientInfo.next())
            {
                ui->leOtherData->setText(queryGetSecondClientInfo.value(recordGetSecondClientInfo.indexOf("phone")).toString());
            }
        }
        if(!ui->leOtherData->text().isEmpty())
        {
            ui->radioBtnClient->setChecked(true);
        }
        else
        {
            QSqlQuery       queryGetSecondEmployeeInfo;
            QString         strGetSecondEmployeeInfo = "SELECT post FROM employee where id_user = '" + id + "';";
            
            if(queryGetSecondEmployeeInfo.exec(strGetSecondEmployeeInfo))
            {
                QSqlRecord      recordGetSecondEmployeeInfo = queryGetSecondEmployeeInfo.record();      
                
                while (queryGetSecondEmployeeInfo.next())
                {
                    ui->leOtherData->setText(queryGetSecondEmployeeInfo.value(recordGetSecondEmployeeInfo.indexOf("post")).toString());
                }
                
                if(!ui->leOtherData->text().isEmpty())
                {
                    ui->radioBtnWorker->setChecked(true);
                }
            }
        }
    }
}

AddUser::~AddUser()
{
    delete ui;
    
    if(mUser != nullptr)
    {
        delete mUser;
    }
}

void AddUser::on_pbCancel_clicked()
{
    this->close();
}

void AddUser::on_pbAdd_clicked()
{
    if(ui->radioBtnClient->isChecked())
    {
        mUser = new Client(ui->leLogin->text(),
                           ui->lePassword->text(),
                           ui->leName->text(),
                           ui->leSurname->text(),
                           ui->leOtherData->text(),
                           ui->lePatronymic->text());
    }
    else
    {
        mUser = new Employee(ui->leLogin->text(),
                             ui->lePassword->text(),
                             ui->leName->text(),
                             ui->leSurname->text(),
                             ui->leOtherData->text(),
                             ui->lePatronymic->text());
    }
    
    if(ui->pbAdd->text() == "Добавить")
    {
        mUser->save();
    }
    else
    {
        mUser->edit(mIdUpdUser);
    }
    
    emit userAdded();
    
    this->close();
}
