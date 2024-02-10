#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "myworker.h"

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
public slots:
    void slotDone();
};

class MyWidget : public QWidget
{
    Q_OBJECT
private:
    QProgressBar* prb1;
    QProgressBar* prb2;
    QProgressBar* prb3;
    QProgressBar* prb4;

    QLabel* lblPot1;
    QLabel* lblPot2;
    QLabel* lblPot3;
    QLabel* lblPot4;
public:
    explicit MyWidget(QWidget *parent = nullptr);
    MyWorker* worker1;
    MyWorker* worker2;
    MyWorker* worker3;
    MyWorker* worker4;
};

#endif // MYWIDGET_H
