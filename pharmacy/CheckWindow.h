#ifndef CHECKWINDOW_H
#define CHECKWINDOW_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include "Preparation.h"
#include <QStandardItemModel>
#include <QList>

namespace Ui {
class CheckWindow;
}

class CheckWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit CheckWindow(double sum, QString checlId, QList<Preparation> *, QWidget *parent = 0);
    ~CheckWindow();
    
private:
    Ui::CheckWindow *ui;
    
    QStandardItemModel      *model;
};

#endif // CHECKWINDOW_H
