#ifndef TABLEMODELOTHER_H
#define TABLEMODELOTHER_H

#include <QSqlQueryModel>
#include <QColor>
#include <QSize>

class TableModelOther : public QSqlQueryModel
{
private:
    int sortKeyColumn;
    Qt::SortOrder sortOrder;
    QSqlDatabase queryDB;
    QString queryClause;
    
public:
    TableModelOther();
    QVariant data(const QModelIndex &idx, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    
    void select();
    void setQuery(const QString & query, const QSqlDatabase & db = QSqlDatabase::database() );
    virtual void setSort (int column, Qt::SortOrder order);
    virtual void sort (int column, Qt::SortOrder order);
};

#endif // TABLEMODELOTHER_H
