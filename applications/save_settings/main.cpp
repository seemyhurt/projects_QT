#include "myprogram.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyProgram myProgram;
    myProgram.show();
    return a.exec();
}
