
#include "printer.h"
#include <QApplication>
#include <QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    Printer* pprinter = new Printer;;
    QPushButton* pcmd = new QPushButton( "&Print");

    QObject::connect(pcmd, SIGNAL(clicked()), pprinter, SLOT(slotPrint()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->setContentsMargins(0, 0, 0, 0);
    pvbxLayout->setSpacing(0);
    pvbxLayout->addWidget(pprinter);
    pvbxLayout->addWidget(pcmd);
    wgt.setLayout(pvbxLayout);
    wgt.resize(250, 320);
    wgt. show ();
    return a.exec();
}
