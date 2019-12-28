#ifndef ADDPREPARATION_H
#define ADDPREPARATION_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDebug>
#include <QString>

#include "Provider.h"
#include "Preparation.h"

namespace Ui {
class AddPreparation;
}

class AddPreparation : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddPreparation(QString idPreparation = "", QWidget *parent = 0);
    ~AddPreparation();
    
signals:
    void preparationAdded();
    
private slots:
    void on_pbCancel_clicked();
    void on_pbAdd_clicked();
    
private:
    Ui::AddPreparation  *ui;
    QString             mIdUpdPreparation;
    
    Preparation         *m_preparation{nullptr};
};

#endif // ADDPREPARATION_H
