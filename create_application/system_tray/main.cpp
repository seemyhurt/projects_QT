#include "systemtray.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemTray st;
    QApplication::setQuitOnLastWindowClosed(false);
    return a.exec();
}
