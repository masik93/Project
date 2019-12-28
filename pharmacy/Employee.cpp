#include "Employee.h"

/// Получить должность.
/// @return Должность.
QString Employee::getPost() const
{
    return m_post;
}

/// Установить должность.
/// @param post Должность.
void Employee::setPost(const QString &post)
{
    m_post = post;
}

void Employee::load() 
{
    
}

bool Employee::save()
{
    if(User::save())
    {
        QSqlQuery       querySaveToDB;
        QString         strSaveToDB = "INSERT INTO employee(post, id_user) VALUES ('" + m_post + "', last_insert_rowid());";
        
        if(!querySaveToDB.exec(strSaveToDB))
        {
            QMessageBox::warning(0, "Error ", "Ошибка сохранения информации о пользователе!");
        }
        else
        {
            QMessageBox::information(0, "Information ", "Пользователь добавлен!");
        }
    }
}

bool Employee::edit(QString idUser)
{
    if(User::edit(idUser))
    {
        QSqlQuery       queryUpdateDB;
        QString         strUpdateDB = "UPDATE employee SET post = '" + m_post + "' where id_user = " + idUser + ";";
                
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
