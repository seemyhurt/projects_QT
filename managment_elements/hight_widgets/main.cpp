#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QScrollArea sa;

    QWidget* pwgt1 = new QWidget (&wgt);
    QPalette pal1;
    pal1.setColor(pwgt1->backgroundRole( ), Qt ::blue);
    pwgt1->setPalette(pal1);
    pwgt1->resize(100, 100);
    pwgt1->move (25, 25);
    pwgt1->setAutoFillBackground (true ) ;

    QWidget* pwgt2 = new QWidget (&wgt ) ;
    QPixmap pix2 (":/proto/picture.jpg") ;
    pal1.setBrush(pwgt1->backgroundRole(), QBrush(pix2) );
    pwgt2->setPalette(pal1);
    pwgt2->move(75, 75);
    pwgt2->setAutoFillBackground(true);
    pwgt2->setFixedSize(pix2.width(), pix2.height() ) ;

    QPixmap pix1 (":/proto/map.jpg") ;
    QCursor cur (pix1);
    sa.setCursor(cur);

    sa.setWidget(pwgt2);
    sa.resize(252, 142);
    sa.show();
    return a.exec();
}
