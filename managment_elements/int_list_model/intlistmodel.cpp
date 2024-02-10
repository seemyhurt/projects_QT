#include "intlistmodel.h"

IntListModel::IntListModel(const QList<int>& list, QObject* pobj) : QAbstractListModel(pobj), m_list(list)
{

}
//возвращает интересующую представление информацию об элементе в объекте класса
QVariant IntListModel::data(const QModelIndex& index, int nRole) const{
    if (!index.isValid())
        return QVariant();
    if (index.row() <0 || index.row() >= m_list.size())
        return QVariant();
    return (nRole == Qt::DisplayRole || nRole ==Qt::EditRole)
                ? m_list.at(index.row())
                : QVariant();
    }
//установка значений
bool IntListModel::setData(const QModelIndex& index,
                           const QVariant& value,
                           int nRole) {
    if (index.isValid() && nRole == Qt::EditRole) {
        m_list.replace(index.row(), value.value<int>() );
        emit dataChanged(index, index);
        return true;
    }
    return false;
}
//количество строк
int IntListModel::rowCount(const QModelIndex& parent/*=QModelindex()*/) const
{
    if (parent.isValid())
        return 0;
    return m_list.size();
}
//возможность подписывать горизонтальные и вертикальные секции
QVariant IntListModel::headerData(int nSection, Qt::Orientation orientation, int nRole/*=DisplayRole*/) const
{
    if (nRole != Qt::DisplayRole)
        return QVariant();
    return (orientation == Qt::Horizontal) ? QString("Number")
                                           : QString::number(nSection);
}
//предоставить возможность редактирования элементов
Qt::ItemFlags IntListModel::flags(const QModelIndex& index) const
{
Qt::ItemFlags flags = QAbstractListModel::flags(index);
return index.isValid() ? (flags | Qt::ItemIsEditable)
                       : flags;
}
//вставка элементов
bool IntListModel::insertRows(int nRow, int nCount, const QModelIndex& parent/*=QModelindex()*/)
{
    if (parent.isValid())
        return false;
    beginInsertRows(QModelIndex(), nRow, nRow + nCount - 1);
    for (int i = 0; i < nCount; ++i)
        m_list.insert(nRow, 0);
    endInsertRows();
    return true;
}
//удаление элементов
bool IntListModel::removeRows(int nRow, int nCount, const QModelIndex& parent/*=QModelindex()*/)
{
    if (parent.isValid())
        return false;
    beginRemoveRows(QModelIndex(), nRow, nRow + nCount - 1);
    for (int i = 0; i < nCount; ++i)
        m_list.removeAt(nRow);
    endRemoveRows();
    return true;
}


