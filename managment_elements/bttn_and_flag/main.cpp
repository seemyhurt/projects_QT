#include <QtWidgets>
#include "buttons.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;
    Buttons buttons;

    QPushButton* pcmdNormal = new QPushButton("&Normal Button");

    QCheckBox* pchkNormal = new QCheckBox("&Normal Check Вох");
    pchkNormal->setChecked(true);

    QCheckBox* pchkTristate = new QCheckBox("&Tristate Check Вох");
    pchkTristate->setTristate(true);
    pchkTristate->setCheckState(Qt::PartiallyChecked);

    QPushButton* pcmdToggle = new QPushButton("&Toggle Button");
    pcmdToggle->setCheckable(true);
    pcmdToggle->setChecked(true);

    QPushButton* pcmdFlat = new QPushButton("&Flat Button");
    pcmdFlat->setFlat(true);

    QPixmap pix(":/proto/map.png");
    QPushButton* pcmdPix = new QPushButton("&Pixmap Button");
    pcmdPix->setIcon(pix);
    pcmdPix->setIconSize(pix.size() );

    QPushButton* cmd = new QPushButton("&Menu");
    QMenu* pmnu = new QMenu (cmd);
    pmnu->addAction("Item1");
    pmnu->addAction("Item2");
    pmnu->addAction("&Quit", &app, SLOT(quit()));
    cmd->setMenu(pmnu);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(&buttons);
    pvbxLayout->addStretch(3);

    pvbxLayout->addWidget(pchkNormal);
    pvbxLayout->addWidget(pchkTristate);
    pvbxLayout->addStretch(3);

    pvbxLayout->addWidget(pcmdNormal);
    pvbxLayout->addWidget(pcmdToggle);
    pvbxLayout->addWidget(pcmdFlat);
    pvbxLayout->addWidget(pcmdPix);
    pvbxLayout->addStretch(3);

    pvbxLayout->addWidget(cmd);
    wgt.setLayout(pvbxLayout);

    wgt.setWindowTitle("Элементы управления");
    wgt.resize(300,500);
    wgt.show();
    return app.exec();
}
