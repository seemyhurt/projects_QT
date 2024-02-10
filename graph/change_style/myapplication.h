#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QWidget>

class MyApplication : public QWidget
{
    Q_OBJECT
public:
   explicit MyApplication(QWidget *parent = nullptr);

public slots:
    void slotChangeStyle(const QString& str);
};

#endif // MYAPPLICATION_H
