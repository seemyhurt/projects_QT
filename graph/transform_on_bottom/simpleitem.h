#ifndef SIMPLEITEM_H
#define SIMPLEITEM_H
#include <QGraphicsItem>
#include <QtWidgets>
#include <QGraphicsView>
class SimpleItem : public QGraphicsItem
{
private:
    enum {nPenWidth = 3};
public:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter* ppainter, const QStyleOptionGraphicsItem*, QWidget*);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pe);
};

#endif // SIMPLEITEM_H
