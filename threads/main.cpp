#include "myworker.h"
#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget wgt;

    //Создаем потоки и привязываем к процедуре
    QThread thread1;
    wgt.worker1->moveToThread(&thread1);
    QObject::connect(&thread1, SIGNAL(started()), wgt.worker1, SLOT(slotDoWork()));

    QThread thread2;
    wgt.worker2->moveToThread(&thread2);
    QObject::connect(&thread2, SIGNAL(started()), wgt.worker2, SLOT(slotDoWork()));

    QThread thread3;
    wgt.worker3->moveToThread(&thread3);
    QObject::connect(&thread3, SIGNAL(started()), wgt.worker3, SLOT(slotDoWork()));

    QThread thread4;
    wgt.worker4->moveToThread(&thread4);
    QObject::connect(&thread4, SIGNAL(started()), wgt.worker4, SLOT(slotDoWork()));

    wgt.show();

    //Запускаем потоки
    thread1.start();
    thread2.start();
    thread3.start();
    thread4.start();
    int nResult = app.exec();
    //Ждем завершения циклов обработки
    thread1.quit();
    thread1.wait();
    thread2.quit();
    thread2.wait();
    thread3.quit();
    thread3.wait();
    thread4.quit();
    thread4.wait();
    return nResult;
}
