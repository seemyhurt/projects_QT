#include "myprogressbar.h"

MyProgressBar::MyProgressBar(QWidget* pwgt) : QProgressBar{pwgt}
{

}

void MyProgressBar::customEvent(QEvent* pe)
{
    if ((int)pe->type() == ProgressEvent::ProgressType)
    {
        setValue(((ProgressEvent*)(pe))->value());
    }
    QWidget::customEvent(pe);
}
