#include "mouseobserver.h"
#include <QApplication>
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MouseObserver w;
    w.resize(250, 130);
    w.show ( ) ;
    w.show();
    return a.exec();
}
