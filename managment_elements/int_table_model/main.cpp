#include "tablemodel.h"
#include <QApplication>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TableModel model(200, 200);
    QTableView tableView;

    tableView.setModel(&model);
    tableView.show();
    return a.exec();
}
