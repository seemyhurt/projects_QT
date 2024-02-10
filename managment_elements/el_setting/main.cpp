#include <QtWidgets>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QSlider* psld= new QSlider(Qt::Horizontal);
    QLabel * рlbl = new QLabel( "3") ;
    psld->setRange(0, 9);
    psld->setPageStep(2);
    psld->setValue(3);
    psld->setTickInterval(2);
    psld->setTickPosition(QSlider::TicksBelow);
    QObject::connect(psld, SIGNAL(valueChanged(int)),рlbl, SLOT(setNum(int)));

    QLCDNumber * plcd = new QLCDNumber(4);
    QScrollBar* phsb = new QScrollBar(Qt::Horizontal);
    QObject::connect(phsb, SIGNAL(valueChanged(int)), plcd, SLOT(display(int)));

    QDial* pdia=new QDial;
    QProgressBar* pprb =new QProgressBar;
    pdia->setRange(0, 100);
    pdia->setNotchTarget(5);
    pdia->setNotchesVisible(true);
    QObject::connect(pdia, SIGNAL(valueChanged(int)), pprb, SLOT(setValue(int)));

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(psld);
    phbxLayout->addWidget(рlbl);

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addLayout(phbxLayout);
    //pvbxLayout->addStretch(1);
    pvbxLayout->addWidget(plcd);
    pvbxLayout->addWidget(phsb);
    //pvbxLayout->addStretch(1);
    pvbxLayout->addWidget(pdia);
    pvbxLayout->addWidget(pprb);

    w.setLayout(pvbxLayout);
    w.resize(250, 500);
    w.show();
    return a.exec();
}
