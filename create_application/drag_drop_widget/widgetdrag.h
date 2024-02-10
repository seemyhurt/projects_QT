#ifndef WIDGETDRAG_H
#define WIDGETDRAG_H

#include <QDrag>
#include "widgetmimedata.h"
class WidgetDrag : public QDrag
{
public:
    WidgetDrag(QWidget* pwgtDragSource = 0);
    void setWidget(QWidget* pwgt);
};

#endif // WIDGETDRAG_H
