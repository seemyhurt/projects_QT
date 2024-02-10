#include "myapplication.h"
#include <QtGui>
#include <QtWidgets>
MyApplication::MyApplication(QWidget *parent)
    : QWidget{parent}
{
    QComboBox* pcbo = new QComboBox;
    QSpinBox* pspb = new QSpinBox;
    QSlider* psld = new QSlider(Qt::Horizontal);
    QRadioButton* prad = new QRadioButton("&Radio Button");
    QCheckBox* pchk = new QCheckBox ( "&Check Вох") ;
    QPushButton* pcmd = new QPushButton("&Push Button");

    pcbo->addItems(QStringList(QStyleFactory::keys()));
    connect(pcbo, &QComboBox::currentTextChanged, this,  &MyApplication::slotChangeStyle);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pcbo);
    pvbxLayout->addWidget(pspb);
    pvbxLayout->addWidget(psld);
    pvbxLayout->addWidget(prad);
    pvbxLayout->addWidget(pchk);
    pvbxLayout->addWidget(pcmd);
    setLayout(pvbxLayout);
}
void MyApplication::slotChangeStyle(const QString& str)
{
    QStyle* pstyle = QStyleFactory::create(str);
    QApplication::setStyle(pstyle);
}
