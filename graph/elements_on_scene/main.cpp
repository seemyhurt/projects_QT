
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene(QRectF(-100, -100, 300, 300));
    QGraphicsView view(&scene);
    QGraphicsRectItem* pRectitem =
    scene.addRect(QRectF(-30, -30, 120, 80),
                  QPen(Qt::black),
                  QBrush(Qt::green)
    );
    pRectitem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsPixmapItem* pPixmapitem =
    scene. addPixmap (QPixmap ("/home/seemyhurt/Изображения/images.jpeg"));
    pPixmapitem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsTextItem* pTextitem =
    scene.addText("Move us with your mouse");
    pTextitem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsLineItem* pLineitem =
    scene.addLine(QLineF(-10, -10, -80, -80), QPen(Qt::red, 2) );
    pLineitem->setFlags(QGraphicsItem::ItemIsMovable);
    QGraphicsTextItem* pTextItem = scene.addText("Shear");
    pTextItem->setTransform(QTransform().shear(1.5, 0.0), true);
    pTextItem->setFlags(QGraphicsItem::ItemIsMovable);
    view.show();
    return a.exec();
}
