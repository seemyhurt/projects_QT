
#include "widget.h"
#include <QApplication>
#include <QtWidgets/QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QPushButton* psbA = new QPushButton("A");
    QPushButton* psbB = new QPushButton("B");
    QPushButton* psbC = new QPushButton("C");
    QPushButton* psbD = new QPushButton("D");

    QHBoxLayout* phbxLayout = new QHBoxLayout;
    //phbxLayout->setContentsMargins(10, 10, 10, 10);
    phbxLayout->setSpacing(20);
    phbxLayout->addWidget(psbC,3);
    //phbxLayout->addStretch(2);
    phbxLayout->addWidget(psbD, 3);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->setContentsMargins(15, 15, 15, 15);
    pvbxLayout->setSpacing(20);
    pvbxLayout->addWidget(psbA,3);
    //phbxLayout->addStretch(2);
    pvbxLayout->addWidget(psbB, 3);
    pvbxLayout->addLayout(phbxLayout);

    w.setLayout(pvbxLayout);
    w.resize(600, 40);
    w.show();
    return a.exec();
}
