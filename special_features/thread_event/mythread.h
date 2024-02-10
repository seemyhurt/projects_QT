#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtWidgets>
#include <QThread>
#include "progressevent.h"
class MyThread : public QThread
{
private:
    QObject* m_pobjReceiver;
public:
    MyThread(QObject* pobjReceiver);
    void run();
};

#endif // MYTHREAD_H
