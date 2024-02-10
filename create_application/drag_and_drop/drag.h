#ifndef DRAG_H
#define DRAG_H
#include <QtWidgets>

class Drag : public QLabel
{
    Q_OBJECT
private:
    QPoint m_ptDragPos;
    void startDrag();
protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent (QMouseEvent* pe);
public:
    Drag(QWidget* pwgt = 0);
};

#endif // DRAG_H
