#include "drop.h"
#include "drag.h"
#include "widget.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Drag drg;
    Drop drp;

    drp.resize(200, 100);
    drg.resize(200, 100);

    Widget wgt;
    QHBoxLayout layout;
    layout.addWidget(&drg);
    layout.addWidget(&drp);

    wgt.setLayout(&layout);
    wgt.show();

    return a.exec();
}
