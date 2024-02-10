#include "mywidget.h"

//Класс для отображения метки завершения
MyLabel::MyLabel(QWidget *parent): QLabel{parent}
{
    QPixmap pix;
    pix.load(":/proto/done.png");
    setPixmap(pix);
    hide();
}
void MyLabel::slotDone(){
    show();
}

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{
    //Шапка таблицы
    QLabel* lblID = new QLabel("Thread-ID");
    QLabel* lblPr = new QLabel("Progress");
    QLabel* lblDn = new QLabel("Done");

    //Индикатор завершения
    MyLabel* done1 = new  MyLabel;
    MyLabel* done2 = new  MyLabel;
    MyLabel* done3 = new  MyLabel;
    MyLabel* done4 = new  MyLabel;

    //Шкалы
    prb1 = new QProgressBar;
    prb2 = new QProgressBar;
    prb3 = new QProgressBar;
    prb4 = new QProgressBar;

    //Ресурсоемкий процесс
    worker1 = new MyWorker(5000, nullptr);
    worker2 = new MyWorker(6000, nullptr);
    worker3 = new MyWorker(7000, nullptr);
    worker4 = new MyWorker(8000, nullptr);

    //ID процесса
    lblPot1 = new QLabel("Thread 1");
    lblPot2 = new QLabel("Thread 2");
    lblPot3 = new QLabel("Thread 3");
    lblPot4 = new QLabel("Thread 4");

    //Изменение шкалы
    QObject::connect(worker1, SIGNAL(valueChanged(int)), prb1, SLOT(setValue(int)));
    QObject::connect(worker2, SIGNAL(valueChanged(int)), prb2, SLOT(setValue(int)));
    QObject::connect(worker3, SIGNAL(valueChanged(int)), prb3, SLOT(setValue(int)));
    QObject::connect(worker4, SIGNAL(valueChanged(int)), prb4, SLOT(setValue(int)));

    //Индикатор завершения
    QObject::connect(worker1, SIGNAL(finished()), done1, SLOT(slotDone()));
    QObject::connect(worker2, SIGNAL(finished()), done2, SLOT(slotDone()));
    QObject::connect(worker3, SIGNAL(finished()), done3, SLOT(slotDone()));
    QObject::connect(worker4, SIGNAL(finished()), done4, SLOT(slotDone()));

    //Табличное размещение
    QGridLayout* pgrdLayout = new QGridLayout;

    pgrdLayout->addWidget(lblID, 0, 0, Qt::AlignCenter);
    pgrdLayout->addWidget(lblPr, 0, 1, 1, 4, Qt::AlignCenter);
    pgrdLayout->addWidget(lblDn, 0, 5, Qt::AlignCenter);

    pgrdLayout->addWidget(lblPot1, 1, 0, Qt::AlignCenter);
    pgrdLayout->addWidget(prb1, 1, 1, 1 , 4) ;
    pgrdLayout->addWidget(done1, 1, 5, Qt::AlignCenter);

    pgrdLayout->addWidget(lblPot2, 2, 0, Qt::AlignCenter);
    pgrdLayout->addWidget(prb2, 2, 1, 1, 4) ;
    pgrdLayout->addWidget(done2, 2, 5, Qt::AlignCenter);

    pgrdLayout->addWidget(lblPot3, 3, 0, Qt::AlignCenter);
    pgrdLayout->addWidget(prb3, 3, 1, 1, 4) ;
    pgrdLayout->addWidget(done3, 3, 5, Qt::AlignCenter);

    pgrdLayout->addWidget(lblPot4, 4, 0, Qt::AlignCenter);
    pgrdLayout->addWidget(prb4, 4, 1, 1, 4) ;
    pgrdLayout->addWidget(done4, 4, 5, Qt::AlignCenter);

    resize(400,170);
    setLayout(pgrdLayout);

};
