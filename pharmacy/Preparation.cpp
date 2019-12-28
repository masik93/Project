#include "Preparation.h"

Preparation::Preparation(const QString &name, const QString &number, const QString &price, const QString &info, const QString &provider_name) : 
    m_name(name), m_number(number), m_price(price), m_info(info), m_providerName(provider_name)
{
    
}

Preparation::~Preparation()
{
    
}

/// Получить id препарата по его наименованию.
/// @return  id препарата по его наименованию.
QString Preparation::getId_preparation(const QString &name)
{
    QString strIdPreparation;
    
    QSqlQuery       queryGetIdPreparation;
    QString         strGetIdPreparation = "SELECT id FROM preparation WHERE name = '" + name + "';";

    if(!queryGetIdPreparation.exec(strGetIdPreparation))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения id препарата!");
    }
    
    QSqlRecord      recordGetIdPreparation = queryGetIdPreparation.record();      
    
    while (queryGetIdPreparation.next())
    {
        strIdPreparation = queryGetIdPreparation.value(recordGetIdPreparation.indexOf("id")).toString();
    }
    
    return strIdPreparation;
}

/// Получить наименование препарата.
/// @return Наименование препарата.
QString Preparation::getName() const
{
    return m_name;
}

/// Задать наименование препарата.
/// @param name Наименование препарата.
void Preparation::setName(const QString &name)
{
    m_name = name;
}

/// Получить количество препарата.
/// @return Количество препарата.
QString Preparation::getNumber() const
{
    return m_number;
}

/// Задать количество препарата.
/// @param number Количество препарата.
void Preparation::setNumber(const QString &number)
{
    m_number = number;
}

/// Получить цену.
/// @return Цена.
QString Preparation::getPrice() const
{
    return m_price;
}

/// Установить цену.
/// @param price Цена.
void Preparation::setPrice(const QString &price)
{
    m_price = price;
}

/// Получить информацию о препарате.
/// @return  Информация о препарате.
QString Preparation::getInfo() const
{
    return m_info;
}

/// Задать информацию о препарате.
/// @param info Информация о препарате.
void Preparation::setInfo(const QString &info)
{
    m_info = info;
}

/// Получить id поставщика.
/// @return  id поставщика.
QString Preparation::getId_provider() const
{
    return m_providerName;
}

/// Задать id поставщика.
/// @param id_provider id поставщика.
void Preparation::setId_provider(const QString &provider_name)
{
    m_providerName = provider_name;
}

/// загрузить
QStringList Preparation::load(QString idPreparation)
{
    QStringList lstPreparationInfo;
    /// Запрос основных данных о препарате
    QSqlQuery       queryGetPreparationInfo;
    QString         strGetPreparationInfo = "SELECT prep.name, prep.number, prep.price, prep.info, prov.name as pName FROM preparation prep, provider prov WHERE prep.id_provider = prov.id and prep.id = '" + idPreparation + "';";

    if(!queryGetPreparationInfo.exec(strGetPreparationInfo))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения данных о препарате!");
    }
    
    QSqlRecord      recordGetPreparationInfo = queryGetPreparationInfo.record();      
    
    while (queryGetPreparationInfo.next())
    {
        lstPreparationInfo << queryGetPreparationInfo.value(recordGetPreparationInfo.indexOf("name")).toString();
        lstPreparationInfo << queryGetPreparationInfo.value(recordGetPreparationInfo.indexOf("number")).toString();
        lstPreparationInfo << queryGetPreparationInfo.value(recordGetPreparationInfo.indexOf("price")).toString();
        lstPreparationInfo << queryGetPreparationInfo.value(recordGetPreparationInfo.indexOf("info")).toString();
        lstPreparationInfo << queryGetPreparationInfo.value(recordGetPreparationInfo.indexOf("pName")).toString();
    }
    
    return lstPreparationInfo;
}

/// сохранить
bool Preparation::save()
{
    QSqlQuery       querySaveToDB;
    QString         strSaveToDB = "INSERT INTO "
                                  "preparation(name, number, price, info, id_provider) "
                                  "VALUES ('" + m_name + "', " + m_number + ", " + m_price + ", '" + m_info + "', (SELECT pr.id FROM provider pr WHERE pr.name = '" + m_providerName + "'));";
    
    if(!querySaveToDB.exec(strSaveToDB))
    {
        QMessageBox::warning(0, "Error ", m_name + " уже есть в базе!");
    }
    else
    {
        QMessageBox::information(0, "Информация ", "Информации о препарате добавлена!");
    }
}

/// редактировать
bool Preparation::edit(QString idPreparation)
{
    QSqlQuery       queryUpdateDB;
    QString         strUpdateDB = "UPDATE "
                                  "preparation "
                                  "SET "
                                  "name = '" + m_name + "', "
                                  "number = " + m_number + ", "
                                  "price = '" + m_price + "', "
                                  "info = '" + m_info + "' "
                                  "where "
                                  "id = " + idPreparation + ";";
    
    if(!queryUpdateDB.exec(strUpdateDB))
    {
        QMessageBox::warning(0, "Error ", m_name + " уже есть в базе!");
    }
    else
    {
        QMessageBox::information(0, "Information ", "Информация о препарате обновлена!");
        
        
    }
}

QList<Preparation> Preparation::getPreparationList()
{
    QList<Preparation> retPreparationList;
    
    /// Запрос основных данных о пользователе
    QSqlQuery       queryGetPreparationList;
    QString         strGetPreparationList = "SELECT name, number, price, info, id_provider FROM preparation;";
    
    if(!queryGetPreparationList.exec(strGetPreparationList))
    {
        QMessageBox::warning(nullptr, "Error ", "Ошибка получения списка препаратов!");
    }
    
    QSqlRecord      recordGetPreparationList = queryGetPreparationList.record();      
    
    while (queryGetPreparationList.next())
    {
        Preparation  tmpPreparation(queryGetPreparationList.value(recordGetPreparationList.indexOf("name")).toString(),
                              queryGetPreparationList.value(recordGetPreparationList.indexOf("number")).toString(),
                              queryGetPreparationList.value(recordGetPreparationList.indexOf("price")).toString(),
                              queryGetPreparationList.value(recordGetPreparationList.indexOf("info")).toString(),
                              queryGetPreparationList.value(recordGetPreparationList.indexOf("id_provider")).toString());
        retPreparationList.append(tmpPreparation);
    }
    
    return retPreparationList;
}
