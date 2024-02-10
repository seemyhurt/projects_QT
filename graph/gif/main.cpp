#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl;
    QMovie mov(":/proto//gif.gif");
    mov.start();
    lbl.setMovie(&mov);
    lbl.resize(mov.frameRect().size());
    lbl.show();
    return a.exec();
}
