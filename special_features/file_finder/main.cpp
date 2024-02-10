#include "filefinder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileFinder finder;
    finder.show();
    return a.exec();
}
