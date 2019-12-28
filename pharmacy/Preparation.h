#ifndef PREPARATION_H
#define PREPARATION_H

#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QList>

#include <QDebug>

class Preparation
{
public:
    Preparation(const QString &name, const QString &number, const QString &price, const QString &info, const QString &provider_name);
    Preparation() = default;
    
    ~Preparation();
    
    /// Получить id препарата по его наименованию.
    /// @return  id препарата по его наименованию.
    static QString getId_preparation(const QString &name);
    
    /// Получить наименование препарата.
    /// @return Наименование препарата.
    QString getName() const;
    /// Задать наименование препарата.
    /// @param name Наименование препарата.
    void setName(const QString &name);
    
    /// Получить количество препарата.
    /// @return Количество препарата.
    QString getNumber() const;
    /// Задать количество препарата.
    /// @param number Количество препарата.
    void setNumber(const QString &number);
    
    /// Получить цену.
    /// @return Цена.
    QString getPrice() const;
    /// Задать цену.
    /// @param price Цена.
    void setPrice(const QString &price);
    
    /// Получить информацию о препарате.
    /// @return  Информация о препарате.
    QString getInfo() const;
    /// Задать информацию о препарате.
    /// @param info Информация о препарате.
    void setInfo(const QString &info);
    
    /// Получить id поставщика.
    /// @return  id поставщика.
    QString getId_provider() const;
    /// Задать id поставщика.
    /// @param id_provider id поставщика.
    void setId_provider(const QString &id_provider);
    
    /// загрузить
    QStringList load(QString idPreparation);
    
    /// сохранить
    bool save();
    
    /// редактировать
    bool edit(QString idPreparation);
    
    /// Получение списка препаратов
    static QList<Preparation> getPreparationList();
    
private:
    QString     m_name;
    QString     m_number;
    QString     m_price;
    QString     m_info;
    QString     m_providerName;
};

#endif // PREPARATION_H
