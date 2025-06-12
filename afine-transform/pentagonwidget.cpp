#include "pentagonwidget.h"

#include <cmath>
#include <QPainter>
#include <QKeyEvent>

PentagonWidget::PentagonWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 300);
    setFocusPolicy(Qt::WheelFocus);
}

void PentagonWidget::rotate(float degrees)
{
    _angleOffset += degrees * M_PI / 180.f;
    update();
}

void PentagonWidget::move(float dx, float dy)
{
    const auto wdh = width();
    const auto hgt = height();
    const auto radius = std::min(wdh, hgt) * 0.3;

    const auto start = QPointF(wdh / 2, hgt / 2);
    const auto center = QPointF(
        _xOffset < 0 ? std::max(start.x() + _xOffset, radius)
                     : std::min(start.x() + _xOffset, wdh - radius),
        _yOffset < 0 ? std::max(start.y() + _yOffset, radius)
                     : std::min(start.y() + _yOffset, hgt - radius)
    );

    if ((dx < 0 && center.x() - radius + dx > 0) ||
        (dx > 0 && center.x() + radius + dx < wdh))
        _xOffset += dx;

    if ((dy < 0 && center.y() - radius + dy > 0) ||
        (dy > 0 && center.y() + radius + dy < hgt))
        _yOffset += dy;

    update();
}

void PentagonWidget::paintEvent(QPaintEvent * event)
{
    const auto angles = 5;
    const auto wdh = width();
    const auto hgt = height();
    const auto radius = std::min(wdh, hgt) * 0.3;

    const auto start = QPointF(wdh / 2, hgt / 2);
    const auto center = QPointF(
        _xOffset < 0 ? std::max(start.x() + _xOffset, radius)
                     : std::min(start.x() + _xOffset, wdh - radius),
        _yOffset < 0 ? std::max(start.y() + _yOffset, radius)
                     : std::min(start.y() + _yOffset, hgt - radius)
    );

    QPolygonF polygon;
    polygon.reserve(angles);
    for (int i = 0; i < angles; ++i)
    {
        const auto angle = _angleOffset + 2 * M_PI * i / angles;
        polygon.append(QPointF (
            center.x() + radius * std::sin(angle),
            center.y() - radius * std::cos(angle)
        ));
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    ///< Сoordinate axes
    painter.setPen(Qt::gray);
    painter.drawLine(0, hgt / 2, wdh, hgt / 2);
    painter.drawLine(wdh / 2, 0, wdh / 2, hgt);

    ///< Polygon
    painter.setPen(QPen(Qt::blue, 2));
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawPolygon(polygon);

    ///< Center
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawEllipse(center, 3, 3);

    return QWidget::paintEvent(event);
}

void PentagonWidget::keyPressEvent(QKeyEvent *event)
{
    const auto step = 10.f;
    const auto angle = 10.f;

    switch (event->key()) {
        // Поворот по часовой стрелке
    case Qt::Key_E: rotate(angle); break;
        // Поворот против часовой стрелки
    case Qt::Key_Q: rotate(-angle); break;
        // Перенос влево
    case Qt::Key_A: move(-step, 0); break;
        // Перенос вправо
    case Qt::Key_D: move(step, 0); break;
        // Перенос вверх
    case Qt::Key_W: move(0, -step); break;
        // Перенос вниз
    case Qt::Key_S: move(0, step); break;
    }

    return QWidget::keyPressEvent(event);;
}
