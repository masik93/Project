#ifndef PROVIDER_H
#define PROVIDER_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QList>

#include <QDebug>


class Provider : public QWidget
{
    Q_OBJECT
    
    /// Наименование.
    QString     m_name;
    /// Адрес.
    QString     m_address;
    /// Номер телефона.
    QString     m_phone;
    /// УНН.
    QString     m_UNN;
    
public:
    /// Перегруженный конструктор.
    /// @param name Наименование.
    /// @param address Адрес.
    /// @param phone Телефон.
    /// @param UNN УНН.
    /// @param parent Родительский виджет.
    explicit Provider(const QString &name, const QString &address, const QString &phone, const QString &UNN, QWidget *parent = 0);
    /// Деструктор.
    ~Provider() {}
    
    /// Оператор присваивания
    Provider & operator = (const Provider &);
    /// Конструктор копии
    Provider(const Provider &);
    
    /// Получить наименование.
    /// @return Наименование.
    QString getName() const;
    /// Установить наименование.
    /// @param name Наименование.
    void setName(const QString &name);
    /// Получить адрес.
    /// @return Адрес.
    QString getAddress() const;
    /// Установить адрес.
    /// @param address Адрес.
    void setAddress(const QString &address);
    /// Получить номер телефона.
    /// @return Номер телефона.
    QString getPhone() const;
    /// Установить номер телефона.
    /// @param phone Номер телефона.
    void setPhone(const QString &phone);
    /// Получить УНН.
    /// @return УНН.
    QString getUNN() const;
    /// Установить УНН.
    /// @param UNN УНН.
    void setUNN(const double &UNN);
    /// загрузить
    QStringList load(QString idProvider);
    /// сохранить
    bool save();
    /// редактировать
    bool edit(QString idUser);
    /// Получение списка поставщиков
    static QList<Provider> getProviderList();
};

#endif // PROVIDER_H
