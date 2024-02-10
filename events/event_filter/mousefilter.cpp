#include "mousefilter.h"
#include <QtWidgets>
MouseFilter::MouseFilter(QObject *parent)
    : QObject{parent}
{

}
/*virtual*/bool MouseFilter::eventFilter(QObject* pobj, QEvent* pe){
    if (pe->type() == QEvent::MouseButtonPress) {
        if (static_cast<QMouseEvent*>(pe)->button() == Qt::LeftButton){
            QString strClassName = pobj->metaObject()->className();
            QMessageBox::information(0, "Class Name", strClassName);
            return true;
        }
    }
    return false;
}
