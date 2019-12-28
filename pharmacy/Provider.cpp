#include "Provider.h"

/// Перегруженный конструктор.
/// @param name Наименование.
/// @param address Адрес.
/// @param phone Телефон.
/// @param UNN УНН.
/// @param parent Родительский виджет.
Provider::Provider(const QString &name, const QString &address, const QString &phone, const QString &UNN, QWidget *parent) :
    QWidget(parent), m_name(name), m_address(address), m_phone(phone), m_UNN(UNN)
{
    
}

/// Оператор присваивания
Provider &Provider::operator =(const Provider &arg)
{
    this->m_name    = arg.m_name;
    this->m_address = arg.m_address;
    this->m_phone   = arg.m_phone;
    this->m_UNN     = arg.m_UNN;
    
    return (*this);
}

/// Конструктор копии
Provider::Provider(const Provider & arg) :
    m_name(arg.m_name), m_address(arg.m_address), m_phone(arg.m_phone), m_UNN(arg.m_UNN)
{
    
}

/// Получить наименование.
/// @return Наименование.
QString Provider::getName() const
{
    return m_name;
}

/// Установить наименование.
/// @param name Наименование.
void Provider::setName(const QString &name)
{
    m_name = name;
}

/// Получить адрес.
/// @return Адрес.
QString Provider::getAddress() const
{
    return m_address;
}

/// Установить адрес.
/// @param address Адрес.
void Provider::setAddress(const QString &address)
{
    m_address = address;
}

/// Получить номер телефона.
/// @return Номер телефона.
QString Provider::getPhone() const
{
    return m_phone;
}

/// Установить номер телефона.
/// @param phone Номер телефона.
void Provider::setPhone(const QString &phone)
{
    m_phone = phone;
}

/// Получить УНН.
/// @return УНН.
QString Provider::getUNN() const
{
    return m_UNN;
}

/// Установить УНН.
/// @param UNN УНН.
void Provider::setUNN(const double &UNN)
{
    m_UNN = UNN;
}

QStringList Provider::load(QString idProvider)
{
    QStringList retList;
    
    /// Запрос основных данных о пользователе
    QSqlQuery       queryGetProviderInfo;
    QString         strGetProviderInfo = "SELECT name, address, phone, UNN FROM provider where id = '" + idProvider + "';";
    
    if(!queryGetProviderInfo.exec(strGetProviderInfo))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения данных о поставщике!");
    }
    
    QSqlRecord      recordGetProviderInfo = queryGetProviderInfo.record();      
    
    while (queryGetProviderInfo.next())
    {
        retList << queryGetProviderInfo.value(recordGetProviderInfo.indexOf("name")).toString();
        retList << queryGetProviderInfo.value(recordGetProviderInfo.indexOf("address")).toString();
        retList << queryGetProviderInfo.value(recordGetProviderInfo.indexOf("phone")).toString();
        retList << queryGetProviderInfo.value(recordGetProviderInfo.indexOf("UNN")).toString();
    }
    
    return retList;
}

bool Provider::save()
{
    QSqlQuery       querySaveToDB;
    QString         strSaveToDB = "INSERT INTO provider(name, address, phone, UNN) VALUES ('" + m_name + "', '" + m_address + "', '" + m_phone + "', " + m_UNN + ");";
    
    if(!querySaveToDB.exec(strSaveToDB))
    {
        QMessageBox::warning(0, "Error ", "Ошибка сохранения информации о поставщике!");
    }
    else
    {
        QMessageBox::information(0, "Information ", "Поставщик добавлен!");
    }
}

bool Provider::edit(QString idUser)
{
    QSqlQuery       queryUpdateDB;
    QString         strUpdateDB = "UPDATE "
                                  "provider "
                                  "SET "
                                  "name = '" + m_name + "', "
                                  "address = '" + m_address + "', "
                                  "phone = '" + m_phone + "', "
                                  "UNN = " + m_UNN + " "
                                  "where "
                                  "id = " + idUser + ";";
    
    if(!queryUpdateDB.exec(strUpdateDB))
    {
        QMessageBox::warning(0, "Error ", "Ошибка обновления информации о поставщике!");
    }
    else
    {
        QMessageBox::information(0, "Information ", "Поставщик обновлен!");
    }
}

QList<Provider> Provider::getProviderList()
{
    QList<Provider> retProviderList;
    
    /// Запрос основных данных о пользователе
    QSqlQuery       queryGetProviderList;
    QString         strGetProviderList = "SELECT id, name, address, phone, UNN FROM provider;";
    
    if(!queryGetProviderList.exec(strGetProviderList))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения списка поставщиков!");
    }
    
    QSqlRecord      recordGetProviderList = queryGetProviderList.record();      
    
    while (queryGetProviderList.next())
    {
        Provider  tmpProvider(queryGetProviderList.value(recordGetProviderList.indexOf("name")).toString(),
                              queryGetProviderList.value(recordGetProviderList.indexOf("address")).toString(),
                              queryGetProviderList.value(recordGetProviderList.indexOf("phone")).toString(),
                              queryGetProviderList.value(recordGetProviderList.indexOf("UNN")).toString());
        retProviderList.append(tmpProvider);
    }
    
    return retProviderList;
}
