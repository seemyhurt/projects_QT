#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H

#include <QtWidgets>
#include "mythread.h"
class MyProgressBar : public QProgressBar
{
public:
    MyProgressBar(QWidget* pwgt = 0);
    void customEvent(QEvent* ре);
};

#endif // MYPROGRESSBAR_H
