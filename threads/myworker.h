#ifndef MYWORKER_H
#define MYWORKER_H

#include <QObject>
#include <QtWidgets>
#include "verylong.h"
class MyWorker : public QObject
{
    Q_OBJECT

private:
    int m_nValue;
    verylong number;
    unsigned long fact;

public:
    MyWorker(unsigned long n, QObject *parent = nullptr);

signals:
    void valueChanged(int);
    void finished();

public slots:
    void slotDoWork();

private slots:
    void setNextValue();
};

#endif // MYWORKER_H
