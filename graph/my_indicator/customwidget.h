#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H
#include <QWidget>
#include <QFrame>
#include <QPainter>
class CustomWidget : public QFrame
{
    Q_OBJECT
protected:
    int m_nProgress;
    virtual void paintEvent(QPaintEvent*);
public:
    CustomWidget(QWidget* pwgt = 0);
    virtual QSize sizeHint() const;
signals:
    void progressChanged(int);
public slots:
    void slotSetProgress(int n);
};

#endif // CUSTOMWIDGET_H
