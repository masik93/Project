#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

#include "User.h"
#include "Employee.h"
#include "Client.h"

namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddUser(QString id = "", QWidget *parent = 0);
    ~AddUser();
    
private slots:
    void on_pbCancel_clicked();
    void on_pbAdd_clicked();
    
signals:
    void userAdded(void);
    
private:
    Ui::AddUser *ui;
    
    QString mIdUpdUser;
    
    /// 
    User    *mUser {nullptr};
    
};

#endif // ADDUSER_H
