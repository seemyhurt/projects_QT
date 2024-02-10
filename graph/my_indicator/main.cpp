#include <QtWidgets>
#include "customwidget.h"
#include "qobjectdefs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    CustomWidget* pcw = new CustomWidget;
    QScrollBar* phsb = new QScrollBar(Qt::Horizontal);

    phsb->setRange(0, 100);
    QObject::connect(phsb, SIGNAL(valueChanged(int)), pcw, SLOT(slotSetProgress(int))) ;

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcw);
    pvbxLayout->addWidget(phsb);
    w.setLayout(pvbxLayout);
    w.show();
    return a.exec();
}
