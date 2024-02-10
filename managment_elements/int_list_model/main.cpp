#include "intlistmodel.h"
#include "widget.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget wgt;
    QHBoxLayout layout;

    IntListModel model(QList<int>() << 123 << 2341 << 32 << 5342 << 723);
    QListView list;
    list.setModel(&model);
    layout.addWidget(&list);

    QTableView table;
    table.setModel(&model);
    layout.addWidget(&table);

    wgt.setLayout(&layout);
    wgt.show();

    return a.exec();
}
