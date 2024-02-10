#include <QApplication>
#include <QStringListModel>
#include <QTreeView>
#include <QHBoxLayout>
#include <QTableView>
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QStringListModel model;
    model.setStringList(QStringList() << "Item1" << "Item2" << "ItemЗ");

    QTreeView* pTreeView = new QTreeView;
    pTreeView->setModel(&model);

    QListView* pListView = new QListView;
    pListView->setModel(&model);

    QTableView* pTableView = new QTableView;
    pTableView->setModel(&model);

    QItemSelectionModel selection(&model);
    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(pTreeView);
    phbxLayout->addWidget(pListView);
    phbxLayout->addWidget(pTableView);
    w.setLayout(phbxLayout);

    w.show();
    return a.exec();
}
