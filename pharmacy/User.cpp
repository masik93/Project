#include "User.h"

/// Получить имя.
/// @return Имя.
QString User::getName() const
{
    return m_name;
}

/// Установить имя.
/// @param name Имя.
void User::setName(const QString &name)
{
    m_name = name;
}

/// Получить отчество.
/// @return Отчество.
QString User::getPatronymic() const
{
    return m_patronymic;
}

/// Установить отчество.
/// @param  patronymic Отчество.
void User::setPatronymic(const QString &patronymic)
{
    m_patronymic = patronymic;
}

/// Получить фамилию.
/// @return Фамилия.
QString User::getSurname() const
{
    return m_surname;
}

/// Установить фамилию.
/// @param surname Фамилия.
void User::setSurname(const QString &surname)
{
    m_surname = surname;
}

/// Получить иницалы.
/// @return Инициалы.
QString User::getInitials()
{
    if(getPatronymic().isNull() || getPatronymic().isEmpty())
        return QString("%1 %2.").arg(getSurname()).arg(getName().left(1));
    else
        return QString("%1 %2.%3.").arg(getSurname()).arg(getName().left(1)).arg(getPatronymic().left(1));
}

/// сохранить
bool User::save()
{
    QSqlQuery       querySaveToDB;
    QString         strSaveToDB = "INSERT INTO User(surname, name, patronymic, login, password) "
                                  "VALUES ('" + m_surname + "', '" + m_name + "','" + m_patronymic + "','" + m_login + "','" + m_password + "');";
    
    if(!querySaveToDB.exec(strSaveToDB))
    {
        QMessageBox::warning(0, "Error ", "Данный логин занят!");
        return false;
    }
    else
    {
        return true;
    }
}

bool User::edit(QString idUser)
{
    QSqlQuery       querySaveToDB;
    QString         strSaveToDB = "UPDATE User SET "
                                  "surname = '" + m_surname + "', "
                                  "name = '" + m_name + "', "
                                  "patronymic = '" + m_patronymic + "', "
                                  "login = '" + m_login + "', "
                                  "password = '" + m_password + "' "
                                  "where id = '" + idUser + "';";
    
    if(!querySaveToDB.exec(strSaveToDB))
    {
        QMessageBox::warning(0, "Error ", "Ошибка обновления информации о пользователе!");
        return false;
    }
    else
    {
        return true;
    }
}

/// Получить логин.
/// @return Логин.
QString User::getLogin() const
{
    return m_login;
}

/// Установить логин.
/// @param login Логин.
void User::setLogin(const QString &login)
{
    m_login = login;
}

/// Получить пароль.
/// @return Пароль.
QString User::getPassword() const
{
    return m_password;
}

/// Установить пароль.
/// @param login Пароль.
void User::setPassword(const QString &password)
{
    m_password = password;
}


