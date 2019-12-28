#-------------------------------------------------
#
# Project created by QtCreator 2018-10-14T10:15:46
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pharmacy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    User.cpp \
    Client.cpp \
    Employee.cpp \
    Provider.cpp \
    LoginWindow.cpp \
    Adduser.cpp \
    AddProvider.cpp \
    AddPreparation.cpp \
    Preparation.cpp \
    AddOrder.cpp \
    CheckWindow.cpp \
    TableModelPreparation.cpp \
    TableModelOther.cpp \
    TableItemModel.cpp

HEADERS += \
        MainWindow.h \
    User.h \
    Client.h \
    Employee.h \
    Provider.h \
    LoginWindow.h \
    Adduser.h \
    AddProvider.h \
    AddPreparation.h \
    Preparation.h \
    AddOrder.h \
    CheckWindow.h \
    TableModelPreparation.h \
    TableModelOther.h \
    TableItemModel.h

FORMS += \
        MainWindow.ui \
    LoginWindow.ui \
    Clients.ui \
    Adduser.ui \
    AddProvider.ui \
    AddPreparation.ui \
    AddOrder.ui \
    CheckWindow.ui

RESOURCES += \
    resources.qrc
