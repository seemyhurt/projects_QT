
#include <QApplication>
#include "myprogressbar.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyProgressBar prb;
    MyThread thread(&prb);

    prb.show();

    thread.start();

    return a.exec();
}
