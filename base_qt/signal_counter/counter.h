#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    explicit Counter(QObject *parent = nullptr);

public slots:
    void slotInc();

signals:
    void goodbye();
    void counterChanged(int);

private:
    int m_Value;
};

#endif // COUNTER_H
