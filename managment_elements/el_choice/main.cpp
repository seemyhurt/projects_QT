#include "qboxlayout.h"
#include <QApplication>
#include <QStringList>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QComboBox>
#include <QToolBox>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wgt;
    QHBoxLayout layout;

    QStringList lst;
    QListWidget lwg;

    QListWidgetItem* pitem =0;
    lwg.setIconSize(QSize(48, 48));
    lwg.setSelectionMode(QAbstractItemView::MultiSelection); //выделять несколько
    lwg.setViewMode(QListView::IconMode);  //режим пиктограмм
    lst << "Linux" << "Windows" << "MacOS" << "Android";

    foreach(QString str, lst) {
        pitem = new QListWidgetItem(str, &lwg);
        pitem->setIcon(QPixmap("/home/seemyhurt/Изображения/" + str + ".png") );
        pitem->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled |
                        Qt::ItemIsDragEnabled | Qt::ItemIsSelectable); //модификации
    }
    lwg.resize(180, 210);
    layout.addWidget(&lwg);

    QTreeWidget twg;
    QStringList lst2;
    lst2 << "Folders" << "Used Space";
    twg.setHeaderLabels(lst2);
    twg.setSortingEnabled(true);

    QTreeWidgetItem* ptwgitem = new QTreeWidgetItem(&twg);
    ptwgitem->setText(0, "Local Disk(C)");
    ptwgitem->setIcon(0, QPixmap("/home/seemyhurt/Изображения/drive.png") );

    QTreeWidgetItem* ptwgitemDir = 0;
    for (int i = 1; i < 20; ++i) {
        ptwgitemDir = new QTreeWidgetItem(ptwgitem);
        ptwgitemDir->setText(0, "Directory " + QString::number(i));
        ptwgitemDir->setText (1, QString::number(i) + " МВ");
    }
    layout.addWidget(&twg);

    const int n = 3;
    QTableWidget tbl(n, n);
    QTableWidgetItem* ptwi = 0;

    QStringList lst3;
    lst3 << "First" << "Second" << "Third";
    tbl.setHorizontalHeaderLabels(lst3);
    tbl.setVerticalHeaderLabels(lst3);
    for (int i = 0; i < n; ++i) {
        for (int j=0; j < n; ++j){
            ptwi = new QTableWidgetItem(QString("%1,%2").arg(i).arg(j));
            tbl.setItem(i,j, ptwi);
        }
    }
    tbl.resize(370,170);
    layout.addWidget(&tbl);

    QComboBox cbo;
    QStringList lst4;
    lst4 << "John" << "Paul" << "George" << "Ringo";
    cbo.addItems(lst4);
    cbo.setEditable(true);
    layout.addWidget(&cbo);

    QTabWidget tab;
    QStringList lst5;
    lst5 << "Linux" << "Windows" << "MacOS" << "Android";
    foreach(QString str, lst5) {
        tab.addTab(new QLabel(str, &tab), QPixmap("/home/seemyhurt/Изображения/" + str + ".png"), str);
    }
    tab.resize(420, 100);
    layout.addWidget(&tab);

    QToolBox tbx;
    QStringList lst6;
    lst6 << "Linux" << "Windows" << "MacOS" << "Android";
    foreach(QString str, lst6) {
        tbx.addItem(new QLabel(str, &tbx), QPixmap("/home/seemyhurt/Изображения/" + str + ".png"), str);
    }
    tbx.resize(420, 100);
    layout.addWidget(&tbx);

    wgt.setLayout(&layout);
    wgt.show();

    return a.exec();
}
