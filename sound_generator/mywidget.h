#ifndef MYWIDJET_H
#define MYWIDJET_H
#include "karplus_strong.h"
#include <QtWidgets>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    karplus_strong* generator;

    QRadioButton* prad1;
    QRadioButton* prad2;
    QRadioButton* prad3;
    QRadioButton* prad4;
    QRadioButton* prad5;
    QRadioButton* prad6;
public slots:
    void slotButtonClicked();
};

#endif // MYWIDJET_H
