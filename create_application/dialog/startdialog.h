#ifndef STARTDIALOG_H
#define STARTDIALOG_H
#include "inputdialog.h"
#include <QPushButton>

class StartDialog : public QPushButton
{
    Q_OBJECT
public:
    StartDialog(QWidget* pwgt = 0);
public slots:
    void slotButtonClicked ();
};

#endif // STARTDIALOG_H
