#include "simpleitem.h"

QRectF SimpleItem::boundingRect() const{
    QPointF ptPosition(-10 - nPenWidth, -10 - nPenWidth);
    QSizeF size(20 + nPenWidth * 2, 20 + nPenWidth * 2);
    return QRectF(ptPosition, size);
};
void SimpleItem::paint(QPainter* ppainter, const QStyleOptionGraphicsItem*, QWidget*){
    ppainter->save();
    ppainter->setPen(QPen(Qt::blue, nPenWidth));
    ppainter->drawEllipse(-10, -10, 20, 20);
    ppainter->restore();
}
void SimpleItem::mousePressEvent(QGraphicsSceneMouseEvent*  pe){
    QApplication::setOverrideCursor(Qt::PointingHandCursor);
    QGraphicsItem::mousePressEvent(pe);
}
