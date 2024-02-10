#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QAbstractTableModel>

class TableModel: public QAbstractTableModel{
Q_OBJECT
private:
    int m_nRows;
    int m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;
public:
    TableModel(int nRows, int nColumns, QObject* pobj = 0);

    QVariant data(const QModelIndex& index,
                 int nRole) const;

    bool setData(const QModelIndex& index,
                const QVariant& value,
                int nRole);

    int rowCount(const QModelIndex&) const;

    int columnCount(const QModelIndex&) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    /*QVariant headerData(int nSection,
                        Qt::Orientation orientation,
                        int nRole = Qt::DisplayRole) const;
    */
    };


#endif // TABLEMODEL_H
