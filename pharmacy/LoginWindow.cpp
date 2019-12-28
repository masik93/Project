#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include "User.h"
#include "Employee.h"
#include "Client.h"

LoginWindow::LoginWindow(QWidget *parent) : ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pbOK_clicked()
{
    if(ui->leLogin->text().isEmpty() || ui->lePassword->text().isEmpty())
    {
        QMessageBox::warning(this, "Авторизация", "Логин или пароль не заданы!");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(QDir::currentPath() + "/DBPharmacy.sqlite3");
        
        if(!database.open())
        {
            QMessageBox::information(nullptr, "Авторизация", database.lastError().text());
        }
        else
        {
            int             userCounter;
            QSqlQuery       queryCheckUser;
            QString         strCheckUser = "SELECT count(id) as counter, surname, name, patronymic FROM User where login = '" + ui->leLogin->text() + "' and password = '" + ui->lePassword->text() + "';";
            // Получить должность, перенести в emploee
            if(!queryCheckUser.exec(strCheckUser))
            {
                QMessageBox::warning(this, "Авторизация", "Логин или пароль заданы неверно!");
            }
            
            QSqlRecord      recordCheckUser = queryCheckUser.record();      
            
            while (queryCheckUser.next())
            {
                userCounter = queryCheckUser.value(recordCheckUser.indexOf("counter")).toInt();

                m_name = queryCheckUser.value(recordCheckUser.indexOf("name")).toString();
                m_patronymic = queryCheckUser.value(recordCheckUser.indexOf("patronymic")).toString();
                m_surname = queryCheckUser.value(recordCheckUser.indexOf("surname")).toString();
            }
            
            if(userCounter)
            {
                user = new Employee(ui->leLogin->text(), ui->lePassword->text());
                MainWindow  *wind = new MainWindow();

                wind        ->show(user);
                this        ->close();

            }
            else
            {
                QMessageBox::warning(this, "Авторизация", "Логин или пароль указан неверно!");
                ui->leLogin->clear();
                ui->lePassword->clear();
            }
        }
    }
}

void LoginWindow::on_pbCancel_clicked()
{
    qApp->exit(0);
}
