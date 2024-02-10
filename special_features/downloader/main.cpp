#include "downloadergui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DownloaderGui dwn;
    dwn.show();
    dwn.resize(280, 100);
    return a.exec();
}
