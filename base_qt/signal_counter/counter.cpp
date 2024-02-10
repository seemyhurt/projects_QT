#include "counter.h"

Counter::Counter(QObject *parent)
    : QObject{parent}, m_Value(0)
{

}
void Counter::slotInc()
{
    emit counterChanged(++m_Value);
    if (m_Value == 5)
    {
        emit goodbye();
    }
}
