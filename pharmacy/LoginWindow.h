#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>

#include "MainWindow.h"
#include "Employee.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    
signals:
    /// Сигнал, который излучается при авторизации пользователя.
    void onAuthorization(User* user);
    
private slots:
    
    void on_pbOK_clicked();
    
    void on_pbCancel_clicked();
    
private:
    Ui::LoginWindow *ui;
    
    QSqlDatabase    database;
    
    QString         m_name;
    QString         m_patronymic;
    QString         m_surname;

    Employee        *user;
};

#endif // LOGINWINDOW_H
