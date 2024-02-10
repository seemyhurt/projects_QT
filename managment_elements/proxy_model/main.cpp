#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QStringListModel model;
    model.setStringList(QStringList() << "Xandria" << "Epica"
              << "Therion" << "Evanescence" << "Nightwish");

    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel(&model);
    proxyModel. setFilterWildcard ( "E*");

    QListView* pListViewl = new QListView;
    pListViewl->setModel(&model);
    QListView* pListView2 = new QListView;
    pListView2->setModel(&proxyModel);

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pListViewl);
    phbxLayout->addWidget(pListView2);

    w.setLayout(phbxLayout);
    w.show();
    return a.exec();
}
