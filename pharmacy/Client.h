#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDebug>

#include "User.h"

class Client : public User
{
    /// Номер телефона.
    QString     m_phone;
    
public:
    /// Перегруженный конструктор.
    /// @param login Логин.
    /// @param password Пароль.
    Client(const QString &login, const QString &password) : Client(login, password, "","","", "") { }
    /// Перегруженный конструктор.
    /// @param login Логин.
    /// @param password Пароль.
    /// @param name Имя.
    /// @param surname Фамилия.
    /// @param phone Телефон.
    /// @param patronymic Отчество. По умолчанию равно null, т.к. граждане некоторых стран не имеют отчества.
    /// @param parent Родительский виджет.
    Client(const QString &login, const QString &password, const QString &name, const QString &surname, const QString &phone, const QString &patronymic = "")
    : User(login, password, name, surname, patronymic), m_phone(phone) { }
    
    /// Получить номер телефона.
    /// @return Номер телефона.
    QString getPhone() const;
    /// Установить номер телефона.
    /// @param phone Номер телефона.
    void setPhone(const QString &phone);
    
    void load();
    
    bool save();
    
    bool edit(QString idUser);
    
    static QList<Client> getClientList();
};

#endif // CLIENT_H
