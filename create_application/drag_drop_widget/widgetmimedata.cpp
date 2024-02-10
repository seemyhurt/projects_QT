#include "widgetmimedata.h"

WidgetMimeData::WidgetMimeData(): QMimeData ()
{
}
WidgetMimeData::~WidgetMimeData()
{
}

QString WidgetMimeData::mimeType(){
    return "application/widget";
}

void WidgetMimeData::setWidget(QWidget* pwgt){
    m_pwgt = pwgt;
    setData(mimeType(), QByteArray());
}

QWidget* WidgetMimeData::widget() const {
    return m_pwgt;
}
