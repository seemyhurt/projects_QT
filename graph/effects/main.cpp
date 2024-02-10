#include <QtWidgets>
#include <QApplication>
QLabel* lbl(QGraphicsEffect* pge)
{
    QLabel* plbl = new QLabel;
    plbl->setPixmap(QPixmap(":/proto/picture.jpg"));
    if (pge){
        plbl->setGraphicsEffect(pge);
    }
    return plbl;
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QGraphicsBlurEffect* pBlur =  new QGraphicsBlurEffect;
    QGraphicsDropShadowEffect* pShadow = new QGraphicsDropShadowEffect;
    QGraphicsColorizeEffect* pColorize =  new QGraphicsColorizeEffect;

    //Layout Setup
    QFormLayout * pfom = new QFormLayout;
    pfom->addRow ( "NoEffects", lbl(0));
    pfom->addRow ( "Blur", lbl(pBlur));
    pfom->addRow ( "DropShadow", lbl(pShadow));
    pfom->addRow ( "Colorize", lbl(pColorize));

    w.setLayout(pfom);

    w.show();
    return a.exec();
}
