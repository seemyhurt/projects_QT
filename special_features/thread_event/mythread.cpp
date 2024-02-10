#include "mythread.h"

MyThread::MyThread(QObject *pobjReceiver) : m_pobjReceiver(pobjReceiver)
{

}
void MyThread::run(){
    for (int i = 0; i <= 100; ++i)
    {
        usleep(100000);
        ProgressEvent* pe = new ProgressEvent;
        pe->setValue(i);
        QApplication::postEvent(m_pobjReceiver, pe);
    }
}
