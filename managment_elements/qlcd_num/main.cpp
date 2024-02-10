#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QLCDNumber* plcd = new QLCDNumber;
    QSpinBox*   pspb = new QSpinBox;

    plcd->setSegmentStyle(QLCDNumber::Filled);
    plcd->setMode(QLCDNumber::Hex);
    pspb->setFixedHeight(30);

    QObject::connect(pspb, SIGNAL(valueChanged(int)), plcd, SLOT(display(int)));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(plcd);
    pvbxLayout->addWidget(pspb);
    w.setLayout(pvbxLayout);

    w.resize(250, 150);
    w.show();
    return a.exec();
}
