#include "TableModelPreparation.h"

TableModelPreparation::TableModelPreparation()
{
    
}

QVariant TableModelPreparation::data(const QModelIndex &idx, int role) const
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
        
    // Роль, отвечающая за цвет заднего фона Item-а
    case Qt::BackgroundColorRole: 
        {
            if((QSqlQueryModel::data(this->index(idx.row(), 2)) < 10) && (QSqlQueryModel::data(this->index(idx.row(), 2)) > 5))
            {
                return QColor(Qt::yellow);
            }
            if(QSqlQueryModel::data(this->index(idx.row(), 2)) <= 5)
            {
                return QColor(Qt::red);
            }
        }
    
    default:
        {
            return QVariant();
        }
    }
}

bool TableModelPreparation::setData(const QModelIndex &index, const QVariant &value, int role)
{
    
}

Qt::ItemFlags TableModelPreparation::flags(const QModelIndex &index) const
{
    // Если индекс не валидный
    if(!index.isValid())
    {
        return Qt::NoItemFlags;
    }
    
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void TableModelPreparation::select()
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

void TableModelPreparation::setQuery(const QString &query, const QSqlDatabase &db)
{
    queryClause = query;
    queryDB = db;
    
    sortKeyColumn = -1;
    sortOrder = Qt::DescendingOrder;
}

void TableModelPreparation::setSort(int column, Qt::SortOrder order)
{
    sortKeyColumn = column;
    sortOrder = order;
}

void TableModelPreparation::sort(int column, Qt::SortOrder order)
{
    if ((sortKeyColumn != column) || (sortOrder != order))
    {
        setSort(column, order);
        select();
    }
}
