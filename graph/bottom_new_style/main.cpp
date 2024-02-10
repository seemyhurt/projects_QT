#include <QtWidgets>
#include "customstyle.h"
int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;
    QSize size(200,100);
    QPushButton* pcmdA = new QPushButton ();
    pcmdA->setMinimumSize(size);

    //Layout setup
    wgt.resize(300, 150);
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcmdA);
    wgt.setLayout(pvbxLayout);

    app.setStyle(new CustomStyle);
    wgt.show();

    return app.exec();
}
