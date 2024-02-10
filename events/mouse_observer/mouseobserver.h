#ifndef MOUSEOBSERVER_H
#define MOUSEOBSERVER_H
#include <QtWidgets>

class MouseObserver : public QLabel{
public:
    MouseObserver(QWidget* pwgt = nullptr);
protected:
    virtual void mousePressEvent (QMouseEvent* pe);
    virtual void mouseReleaseEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent (QMouseEvent* pe);
    void dumpEvent (QMouseEvent* pe, const QString& strMessage);
    QString modifiersinfo (QMouseEvent* ре);
    QString buttonsinfo(QMouseEvent* pe);
};

#endif // MOUSEOBSERVER_H
