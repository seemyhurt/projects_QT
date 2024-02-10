#ifndef GRABWIDGET_H
#define GRABWIDGET_H

#include <QWidget>
#include <QtWidgets>
class GrabWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel* m_plbl;
public:
    explicit GrabWidget(QWidget *parent = nullptr);

public slots:
    void slotGrabScreen();

};

#endif // GRABWIDGET_H
