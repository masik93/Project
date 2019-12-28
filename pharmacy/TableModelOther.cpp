#include "TableModelOther.h"

TableModelOther::TableModelOther()
{
    
}

QVariant TableModelOther::data(const QModelIndex &idx, int role) const
{
    // Если индекс не валидный
    if(!idx.isValid())
    {
        return QVariant();
    }
    
    switch(role)
    {
    case Qt::EditRole:
    // Роль, отвечающая за отображение данных в Item-е
    case Qt::DisplayRole:
        {
            return QSqlQueryModel::data(idx);
        }
    
    default:
        {
            return QVariant();
        }
    }
}

bool TableModelOther::setData(const QModelIndex &index, const QVariant &value, int role)
{
    
}

Qt::ItemFlags TableModelOther::flags(const QModelIndex &index) const
{
    // Если индекс не валидный
    if(!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void TableModelOther::select()
{
    if (queryClause.isEmpty() || (!queryDB.isValid()))
            return;
    
    QString query = queryClause;
    
    if (sortKeyColumn >= 0) 
    {
        QString orderClause;
        orderClause = " ORDER BY " + QString::number(sortKeyColumn + 1) + " " +
                ((sortOrder == Qt::DescendingOrder) ? "ASC" : "DESC");
        query.append(" " + orderClause);
    }
    
    QSqlQueryModel::setQuery(query, queryDB);
}

void TableModelOther::setQuery(const QString &query, const QSqlDatabase &db)
{
    queryClause = query;
    queryDB = db;
    
    sortKeyColumn = -1;
    sortOrder = Qt::DescendingOrder;
}

void TableModelOther::setSort(int column, Qt::SortOrder order)
{
    sortKeyColumn = column;
    sortOrder = order;
}

void TableModelOther::sort(int column, Qt::SortOrder order)
{
    if ((sortKeyColumn != column) || (sortOrder != order))
    {
        setSort(column, order);
        select();
    }
}
