#include "mousefilter.h"
#include "widget.h"
#include <QApplication>
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget wgt;
    QVBoxLayout layout;

    QLineEdit txt("QLineEdit");
    txt.installEventFilter(new MouseFilter(&txt));

    QLabel lbl("QLabel");
    lbl.installEventFilter(new MouseFilter(&lbl));

    QPushButton cmd ("QPushButton") ;
    cmd.installEventFilter(new MouseFilter(&cmd));

    layout.addWidget(&txt);
    layout.addWidget(&lbl);
    layout.addWidget(&cmd);

    wgt.setLayout(&layout);
    wgt.show();

    return a.exec();
}
