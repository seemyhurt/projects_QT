#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
//======================================================================
class MyView: public QGraphicsView {
Q_OBJECT
public:
    MyView(QGraphicsScene* pScene, QWidget* pwgt = 0);
public slots:
    void slotZoomin();
    void slotZoomOut();
    void slotRotateLeft();
    void slotRotateRight();
};


#endif // MYVIEW_H
