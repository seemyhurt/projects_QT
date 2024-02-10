#include "tablemodel.h"

TableModel::TableModel(int nRows, int nColumns, QObject* pobj):
    QAbstractTableModel(pobj)
    , m_nRows(nRows)
    , m_nColumns(nColumns)
{

}
//возвращает интересующую представление информацию об элементе в объекте класса
QVariant TableModel::data(const QModelIndex& index, int nRole) const{
    if (!index.isValid())
        return QVariant();
    QString str = QString("%1, %2").arg (index.row() + 1).arg (index.column () + 1);
    return (nRole == Qt::DisplayRole || nRole ==Qt::EditRole)
                ? m_hash.value(index, QVariant(str))
                : QVariant();
    }

//установка значений
bool TableModel::setData(const QModelIndex& index,
                           const QVariant& value,
                           int nRole) {
    if (index.isValid() && nRole == Qt::EditRole) {
        m_hash[index] = value;
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

int TableModel::rowCount(const QModelIndex&) const
{return m_nRows;}

int TableModel::columnCount(const QModelIndex&) const
{return m_nColumns;}

Qt::ItemFlags TableModel::flags(const QModelIndex& index) const
{
Qt::ItemFlags flags = QAbstractTableModel::flags(index);
return index.isValid() ? (flags | Qt::ItemIsEditable)
                       : flags;
}


/*возможность подписывать горизонтальные и вертикальные секции
QVariant TableModel::headerData(int nSection, Qt::Orientation orientation, int nRole const
{
    if (nRole != Qt::DisplayRole)
        return QVariant();
    return (orientation == Qt::Horizontal) ? QString("Number")
                                           : QString::number(nSection);
}*/
