#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDebug>

#include "User.h"

class Employee : public User
{
    /// Должность.
    QString     m_post;
    
public:
    Employee() = default;
    /// Перегруженный конструктор.
    /// @param login Логин.
    /// @param password Пароль.
    Employee(const QString &login, const QString &password) : Employee(login, password, "","","", "") { }
    /// Перегруженный конструктор.
    /// @param login Логин.
    /// @param password Пароль.
    /// @param name Имя.
    /// @param surname Фамилия.
    /// @param post Должность.
    /// @param patronymic Отчество. По умолчанию равно null, т.к. граждане некоторых стран не имеют отчества.
    /// @param parent Родительский виджет.
    Employee(const QString &login, const QString &password, const QString &name, const QString &surname, const QString &post, const QString &patronymic = "") 
        : User(login, password, name, surname, patronymic), m_post(post) { }
    /// Получить должность.
    /// @return Должность.
    QString getPost() const;
    /// Установить должность.
    /// @param post Должность.
    void setPost(const QString &post);
    
    void load();
    
    bool save();
    
    bool edit(QString idUser);
};

#endif // EMPLOYEE_H
