#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{
    generator = new karplus_strong;


    QGroupBox * gbx1 = new QGroupBox("&Частота сигнала: ");
    QSpinBox* psbx = new QSpinBox;
    QLCDNumber* plcd = new QLCDNumber(4);

    psbx->setRange(50,2000);
    QObject::connect(psbx, SIGNAL(valueChanged(int)), plcd, SLOT(display(int)));
    QObject::connect(psbx, SIGNAL(valueChanged(int)), generator, SLOT(slotSetFreq(int)));
    psbx->setValue(100);
    plcd->display(100);
    QVBoxLayout* pvbx1Layout = new QVBoxLayout;
    pvbx1Layout->addWidget(plcd);
    pvbx1Layout->addWidget(psbx);
    gbx1->setLayout(pvbx1Layout);


    QGroupBox * gbx2 = new QGroupBox("&Частота дискретизации: ");
    QVBoxLayout* pvbx2Layout = new QVBoxLayout;

    prad1 = new QRadioButton("8000 Гц");
    pvbx2Layout->addWidget(prad1);
    connect(prad1, SIGNAL(clicked()),this, SLOT(slotButtonClicked()) );

    prad2 = new QRadioButton("11025 Гц");
    pvbx2Layout->addWidget(prad2);
    connect(prad2, SIGNAL(clicked()),this, SLOT(slotButtonClicked()) );

    prad3 = new QRadioButton("16000 Гц");
    pvbx2Layout->addWidget(prad3);
    connect(prad3, SIGNAL(clicked()),this, SLOT(slotButtonClicked()) );

    prad4 = new QRadioButton("22050 Гц");
    pvbx2Layout->addWidget(prad4);
    connect(prad4, SIGNAL(clicked()),this, SLOT(slotButtonClicked()) );

    prad5 = new QRadioButton("32000 Гц");
    pvbx2Layout->addWidget(prad5);
    connect(prad5, SIGNAL(clicked()),this, SLOT(slotButtonClicked()) );

    prad6 = new QRadioButton("44100 Гц");
    pvbx2Layout->addWidget(prad6);
    connect(prad6, SIGNAL(clicked()),this, SLOT(slotButtonClicked()) );
    prad6->setChecked(true);

    gbx2->setLayout(pvbx2Layout);

    QGroupBox * gbx3 = new QGroupBox("&Длительность: ");
    QDial* pdial = new QDial;
    QLCDNumber* plcd2 = new QLCDNumber(4);

    pdial->setRange(1,10);
    QObject::connect(pdial, SIGNAL(valueChanged(int)), plcd2, SLOT(display(int)));
    QObject::connect(pdial, SIGNAL(valueChanged(int)), generator, SLOT(slotSetDur(int)));
    plcd2->display(3);
    pdial->setValue(3);
    QVBoxLayout* pvbx3Layout = new QVBoxLayout;
    pvbx3Layout->addWidget(plcd2);
    pvbx3Layout->addWidget(pdial);
    gbx3->setLayout(pvbx3Layout);

    QGroupBox * gbx4 = new QGroupBox("&Название файла: ");
    QLineEdit* ptxt = new QLineEdit;
    QObject::connect(ptxt, SIGNAL(textChanged(const QString&)), generator, SLOT(slotSetName(const QString&)));
    QPushButton *btn = new QPushButton("&Сохранить");
    QObject::connect(btn, SIGNAL(clicked()), generator, SLOT(slotSave()));
    QPushButton *btn1 = new QPushButton("&Воспроизвести");
    QObject::connect(btn1, SIGNAL(clicked()), generator, SLOT(slotPlay()));
    QHBoxLayout* phbx1Layout = new QHBoxLayout;
    phbx1Layout->addWidget(ptxt);
    phbx1Layout->addWidget(btn);
    phbx1Layout->addWidget(btn1);
    gbx4->setLayout(phbx1Layout);

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(gbx1);
    phbxLayout->addWidget(gbx2);
    phbxLayout->addWidget(gbx3);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(phbxLayout);
    mainLayout->addWidget(gbx4);

    setLayout(mainLayout);
}

void MyWidget::slotButtonClicked(){
    if(prad1->isChecked())
        generator->slotSetRate(8000);
    if(prad2->isChecked())
        generator->slotSetRate(11025);
    if(prad3->isChecked())
        generator->slotSetRate(16000);
    if(prad4->isChecked())
        generator->slotSetRate(22050);
    if(prad5->isChecked())
        generator->slotSetRate(32000);
    if(prad6->isChecked())
        generator->slotSetRate(44100);
}
