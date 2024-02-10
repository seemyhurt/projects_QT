#include "progressevent.h"

ProgressEvent::ProgressEvent() : QEvent((Type)ProgressType)
{

}
void ProgressEvent::setValue(int n)
{
    m_nValue = n;
}

int ProgressEvent::value() const
{
    return m_nValue;
}
