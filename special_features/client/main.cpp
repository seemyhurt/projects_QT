#include "myclient.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient w("127.0.0.1", 2323);
    w.show();
    return a.exec();
}
