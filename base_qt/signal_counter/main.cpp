#include <QApplication>
#include "counter.h"
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel lbl("0");
    QPushButton cmd("add");
    Counter counter;

    QWidget wgt;
    QHBoxLayout layout;
    layout.addWidget(&lbl);
    layout.addWidget(&cmd);

    QObject::connect(&cmd, SIGNAL(clicked()),
                     &counter, SLOT(slotInc()));

    QObject::connect(&counter, SIGNAL(counterChanged(int)),
                     &lbl, SLOT(setNum(int)));

    QObject::connect(&counter, SIGNAL(goodbye()),
                     &app, SLOT(quit()));

    wgt.setLayout(&layout);
    wgt.show();

    return app.exec();
}
