#ifndef PENTAGONWIDGET_H
#define PENTAGONWIDGET_H

#include <QWidget>

class PentagonWidget  : public QWidget
{
    Q_OBJECT

public:
    PentagonWidget(QWidget *parent = nullptr);
    ~PentagonWidget() = default;

public:
    void rotate(float degrees);
    void move(float dx, float dy);

protected:
    void paintEvent(QPaintEvent *) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    float _xOffset = 0.f;
    float _yOffset = 0.f;
    float _angleOffset = 0.f;
};

#endif // PENTAGONWIDGET_H
