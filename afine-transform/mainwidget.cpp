#include "mainwidget.h"
#include "pentagonwidget.h"

#include <QLayout>
#include <QPushButton>

MainWidget::MainWidget(QWidget * parent)
    : QWidget(parent),
    _pentagon(new PentagonWidget(this))
{
    auto rotateLayout = new QHBoxLayout();
    auto moveLayout = new QHBoxLayout();
    auto mainLayout = new QVBoxLayout();

    auto clockwiseButton = new QPushButton("Повернуть по часовой (E)");
    auto counterclockwiseButton = new QPushButton("Повернуть против часовой (Q)");

    auto upButton = new QPushButton("Переместить вверх (W)");
    auto leftButton = new QPushButton("Повернуть влево (A)");
    auto downButton = new QPushButton("Переместить вниз (S)");
    auto rightButton = new QPushButton("Переместить вправо (D)");

    connect(clockwiseButton, &QPushButton::clicked, this, [this]{
        return _pentagon->rotate(10.f);
    });

    connect(counterclockwiseButton, &QPushButton::clicked, this, [this]{
        return _pentagon->rotate(-10.f);
    });

    connect(upButton, &QPushButton::clicked, this, [this]{
        return _pentagon->move(0, -10.f);
    });

    connect(downButton, &QPushButton::clicked, this, [this]{
        return _pentagon->move(0, 10.f);
    });

    connect(leftButton, &QPushButton::clicked, this, [this]{
        return _pentagon->move(-10.f, 0);
    });

    connect(rightButton, &QPushButton::clicked, this, [this]{
        return _pentagon->move(10.f, 0);
    });

    rotateLayout->addWidget(clockwiseButton);
    rotateLayout->addWidget(counterclockwiseButton);

    moveLayout->addWidget(upButton);
    moveLayout->addWidget(downButton);
    moveLayout->addWidget(leftButton);
    moveLayout->addWidget(rightButton);

    mainLayout->addLayout(rotateLayout);
    mainLayout->addLayout(moveLayout);
    mainLayout->addWidget(_pentagon);

    setLayout(mainLayout);
}
