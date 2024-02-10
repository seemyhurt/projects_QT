#include "qgraphicsscene.h"
#include "myview.h"
#include "simpleitem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    QGraphicsScene scene(QRectF(-100, -100, 640, 480));
    MyView* pView = new MyView(&scene);

    QPushButton* pcmdZoomin = new QPushButton("&Zoom In");
    QPushButton* pcmdZoomOut = new QPushButton("Z&oom Out");
    QPushButton* pcmdRotateLeft = new QPushButton ( "&Rotate Left");
    QPushButton* pcmdRotateRight = new QPushButton ("Ro&tate Right");

    pView->setRenderHint (QPainter::Antialiasing, true );
    SimpleItem* pSimpleitem = new SimpleItem;
    scene .addItem(pSimpleitem);
    pSimpleitem->setPos(0, 0);
    pSimpleitem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* pPixmapitem = scene.addPixmap(QPixmap("/home/seemyhurt/Изображения/images.jpeg"));
    pPixmapitem->setParentItem(pSimpleitem);
    pPixmapitem->setFlags(QGraphicsItem::ItemIsMovable);

    QObject::connect(pcmdZoomin, SIGNAL(clicked()), pView,SLOT(slotZoomin()));
    QObject::connect(pcmdZoomOut, SIGNAL(clicked()), pView, SLOT(slotZoomOut()));
    QObject::connect(pcmdRotateLeft, SIGNAL(clicked()), pView,SLOT(slotRotateLeft()));
    QObject::connect(pcmdRotateRight, SIGNAL(clicked()), pView, SLOT (slotRotateRight()));

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pView);
    pvbxLayout->addWidget(pcmdZoomin);
    pvbxLayout->addWidget(pcmdZoomOut);
    pvbxLayout->addWidget(pcmdRotateLeft);
    pvbxLayout->addWidget(pcmdRotateRight);
    w.setLayout(pvbxLayout);
    w.show();
    return a.exec();
}
