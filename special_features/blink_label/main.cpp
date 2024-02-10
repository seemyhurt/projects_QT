#include "blinklabel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlinkLabel lbl("<FONT COLOR = RED><CENTER>Blink</CENTER></FONT>");
    lbl.resize(100, 100);
    lbl.show();
    return a.exec();
}
