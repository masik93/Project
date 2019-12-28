#include "MainWindow.h"
#include <QApplication>
#include <QDebug>

#include "LoginWindow.h"
#include "MainWindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Окно авторизации
    LoginWindow     loginWindow;
    loginWindow     .show();

    return a.exec();
}
