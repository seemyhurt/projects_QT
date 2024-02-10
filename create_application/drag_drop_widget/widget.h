#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include "widgetdrag.h"
class Widget : public QLabel
{
    Q_OBJECT
private:
    QPoint m_ptDragPos;
    void startDrag();
public:
    Widget(QWidget *parent = nullptr);
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent (QMouseEvent* pe);
    virtual void dragEnterEvent (QDragEnterEvent* pe);
    virtual void dropEvent(QDropEvent* pe);
};
#endif // WIDGET_H
