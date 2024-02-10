#include "myview.h"

MyView::MyView(QGraphicsScene* pScene, QWidget* pwgt) : QGraphicsView(pScene, pwgt)
{}
void MyView::slotZoomin(){
    scale(1.1, 1.1) ;
}
void MyView::slotZoomOut(){
    scale(1/1.1, 1/1.1);
}
void MyView::slotRotateLeft(){
    rotate(-5);
}
void MyView::slotRotateRight(){
    rotate (5);
}
