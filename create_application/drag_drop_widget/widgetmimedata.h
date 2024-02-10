#ifndef WIDGETMIMEDATA_H
#define WIDGETMIMEDATA_H

#include <QMimeData>
#include <QWidget>
class WidgetMimeData : public QMimeData {
private:
    QWidget* m_pwgt;
public:
    WidgetMimeData ();
    virtual ~WidgetMimeData();
    static QString mimeType();
    void setWidget(QWidget* pwgt);
    QWidget* widget() const;

};


#endif // WIDGETMIMEDATA_H
