#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class PentagonWidget;

class MainWidget : public QWidget
{
public:
    MainWidget(QWidget * parent = nullptr);
    ~MainWidget() = default;

private:
    PentagonWidget * _pentagon;
};

#endif // MAINWIDGET_H
