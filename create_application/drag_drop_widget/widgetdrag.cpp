#include "widgetdrag.h"

WidgetDrag::WidgetDrag(QWidget* pwgtDragSource) : QDrag(pwgtDragSource)
{

}
void WidgetDrag::setWidget(QWidget* pwgt){
    WidgetMimeData* pmd = new WidgetMimeData;
    pmd->setWidget(pwgt);
    setMimeData(pmd);
}
