#ifndef USER_H
#define USER_H

#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>

class User
{

protected:
    /// Логин.
    QString     m_login;

    /// Пароль.
    QString     m_password;
    /// Имя.
    QString     m_name;
    /// Отчество.
    QString     m_patronymic;
    /// Фамилия.
    QString     m_surname;
    
public:

    /// Перегруженный конструктор.
    /// @param login Логин.
    /// @param password Пароль.
    /// @param name Имя.
    /// @param surname Фамилия.
    /// @param patronymic Отчество. По умолчанию равно null, т.к. граждане некоторых стран не имеют отчества.
    User(const QString &login, const QString &password, const QString &name, const QString &surname, const QString &patronymic = "") 
        : m_login(login), m_password(password), m_name(name), m_patronymic(patronymic), m_surname(surname) { }
    /// Перегруженный конструктор.
    /// @param login Логин.
    /// @param password Пароль.
    User(const QString &login, const QString &password) 
        : User(login, password, "", "", "") { }

    /// Получить имя.
    /// @return Имя.
    QString getName() const;
    /// Установить имя.
    /// @param name Имя.
    void setName(const QString &name);
    /// Получить отчество.
    /// @return Отчество.
    QString getPatronymic() const;
    /// Установить отчество.
    /// @param  patronymic Отчество.
    void setPatronymic(const QString &patronymic);
    /// Получить фамилию.
    /// @return Фамилия.
    QString getSurname() const;
    /// Установить фамилию.
    /// @param surname Фамилия.
    void setSurname(const QString &surname);
    /// Получить иницалы.
    /// @return Инициалы.
    QString getInitials();
    /// загрузить
    virtual void load() = 0;
    /// сохранить
    virtual bool save();
    /// редактировать
    virtual bool edit(QString idUser);
    /// Получить логин.
    /// @return Логин.
    QString getLogin() const;
    /// Установить логин.
    /// @param login Логин.
    void setLogin(const QString &login);
    /// Получить пароль.
    /// @return Пароль.
    QString getPassword() const;
    /// Установить пароль.
    /// @param login Пароль.
    void setPassword(const QString &password);
};

#endif // USER_H
