#include "Client.h"

/// Получить номер телефона.
/// @return Номер телефона.
QString Client::getPhone() const
{
    return m_phone;
}

/// Установить номер телефона.
/// @param phone Номер телефона.
void Client::setPhone(const QString &phone)
{
    m_phone = phone;
}

void Client::load() 
{
    
}

bool Client::save()
{
    if(User::save())
    {
        QSqlQuery       querySaveToDB;
        QString         strSaveToDB = "INSERT INTO clients(phone, id_user) VALUES ('" + m_phone + "', last_insert_rowid());";
        
        if(!querySaveToDB.exec(strSaveToDB))
        {
            QMessageBox::warning(0, "Error ", "Ошибка сохранения информации о пользователе!");
        }
        else
        {
            QMessageBox::information(0, "Information ", "Пользователь добавлен!");
        }
    };
}

bool Client::edit(QString idUser)
{
    if(User::edit(idUser))
    {
        QSqlQuery       queryUpdateDB;
        QString         strUpdateDB = "UPDATE clients SET phone = '" + m_phone + "' where id_user = " + idUser + ";";
                
        if(!queryUpdateDB.exec(strUpdateDB))
        {
            QMessageBox::warning(0, "Error ", "Ошибка обновления информации о пользователе!");
        }
        else
        {
            QMessageBox::information(0, "Information ", "Пользователь обновлен!");
        }
    }
}

//(const QString &login, const QString &password, const QString &name, const QString &surname, const QString &phone, const QString &patronymic = "")

QList<Client> Client::getClientList()
{
    QList<Client> retClientList;
    
    /// Запрос списка клиентов
    QSqlQuery       queryGetClientList;
    QString         strGetClientList = "SELECT u.surname, u.name, u.patronymic, u.login, u.password, c.phone FROM User u, clients c WHERE c.id_user = u.id;";
    
    if(!queryGetClientList.exec(strGetClientList))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения списка клиентов!");
    }
    
    QSqlRecord      recordGetClientList = queryGetClientList.record();      
    
    while (queryGetClientList.next())
    {
        Client  tmpClient(queryGetClientList.value(recordGetClientList.indexOf("login")).toString(),
                              queryGetClientList.value(recordGetClientList.indexOf("password")).toString(),
                              queryGetClientList.value(recordGetClientList.indexOf("name")).toString(),
                              queryGetClientList.value(recordGetClientList.indexOf("surname")).toString(),
                              queryGetClientList.value(recordGetClientList.indexOf("phone")).toString(),
                              queryGetClientList.value(recordGetClientList.indexOf("patronymic")).toString());
        retClientList.append(tmpClient);
    }
    
    return retClientList;
}
