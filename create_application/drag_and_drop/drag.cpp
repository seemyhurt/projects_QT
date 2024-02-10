#include "drag.h"

Drag::Drag(QWidget* pwgt): QLabel ( "This is а draggable text", pwgt)
{

}
void Drag::startDrag(){
    QMimeData* pMimeData = new QMimeData;
    pMimeData->setText(text());

    QDrag* pDrag = new QDrag(this);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(QPixmap("/home/seemyhurt/Изображения/icon.png"));
    pDrag->exec();
}
void Drag::mousePressEvent(QMouseEvent* pe){
    if (pe->button() == Qt::LeftButton)
    {
        m_ptDragPos = pe->pos();
    }
    QWidget::mousePressEvent(pe);
}
void Drag::mouseMoveEvent(QMouseEvent* pe){
    if (pe->buttons() & Qt::LeftButton){
        int distance = (pe->pos() - m_ptDragPos) .manhattanLength();
        if (distance > QApplication::startDragDistance()) {
            startDrag () ;
        }
    }
    QWidget::mouseMoveEvent(pe);
    }
