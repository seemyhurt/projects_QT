#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl;
    lbl.setPixmap(QPixmap(":/proto/picture.jpg"));
    QGraphicsColorizeEffect effect;
    lbl.setGraphicsEffect(&effect);
    QPropertyAnimation anim(&effect, "color");
    anim.setStartValue(QColor(Qt::gray));
    anim.setKeyValueAt(0.25f, QColor(Qt::green));
    anim.setKeyValueAt(0.5f, QColor(Qt::blue) );
    anim.setKeyValueAt(0.75f, QColor(Qt::red) );
    anim.setEndValue(QColor(Qt::black));
    anim.setDuration(10000);
    anim.setLoopCount(-1);
    anim. start();
    lbl.show();
    return a.exec();
}
