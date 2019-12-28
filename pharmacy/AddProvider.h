#ifndef ADDPROVIDER_H
#define ADDPROVIDER_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QMessageBox>
#include <QRegExp>
#include <QValidator>

#include "Provider.h"
#include <QDebug>

namespace Ui {
class AddProvider;
}

class AddProvider : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddProvider(QString idProvider = "", QWidget *parent = 0);
    ~AddProvider();
    
private slots:
    void on_pbAdd_clicked();
    
    void on_pbCancel_clicked();
    
signals:
    void providerAdded(void);
    
private:
    Ui::AddProvider *ui;
    
    QString         m_idUpdProvider;
    Provider        *m_provider;
    QValidator      *validator;
};

#endif // ADDPROVIDER_H
