#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget wgt1;
    Widget wgt2;

    wgt1.setWindowTitle("Widget1");
    wgt1.setObjectName("Widget1");
    wgt1.resize(200, 200);
    wgt1.show();

    wgt2.setWindowTitle("Widget2");
    wgt2.setObjectName("Widget2");
    wgt2.resize(200, 200);
    wgt2.show();
    return a.exec();
}
