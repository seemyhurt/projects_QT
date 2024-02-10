#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
class MyMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMainWindow(QWidget *parent = nullptr);
private:
    QLabel* m_plblX;
    QLabel* m_plblY;
protected:
    virtual void mouseMoveEvent(QMouseEvent* pe);
};

#endif // MYMAINWINDOW_H
