#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStringList lst;
    lst << "Linux" << "Windows" << "MacOS" << "Android";
    QStandardItemModel model(lst.size(), 1);
    for(int i = 0; i < model.rowCount(); ++i){
        QModelIndex index = model.index(i, 0);
        QString str = lst.at(i);
        model.setData(index, str, Qt::DisplayRole);
        model.setData(index, "ToolTip for" + str, Qt::ToolTipRole);
    }
    QListView listView;
    listView.setViewMode(QListView::IconMode);
    listView.setModel(&model);
    listView.show();
    return a.exec();
}
