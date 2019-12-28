#ifndef ADDORDER_H
#define ADDORDER_H

#include "Preparation.h"
#include <QList>

#include <QDialog>

namespace Ui {
class AddOrder;
}

class AddOrder : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddOrder(QWidget *parent = 0);
    ~AddOrder();
    
signals:
    void preparationAdded(Preparation);
    
private slots:
    void on_pbCancel_clicked();
    
    void on_cboxPreparation_currentTextChanged(const QString &arg1);
    
    void on_spinNumber_valueChanged(int arg1);
    
    void on_pbAdd_clicked();
    
private:
    Ui::AddOrder *ui;
    
    QList<Preparation>      *inOrder;
};

#endif // ADDORDER_H
