#include "blinklabel.h"

BlinkLabel::BlinkLabel(const QString& strText,
                       int ninterval,
                       QWidget * pwgt) : QLabel(strText, pwgt) , m_bBlink(true) , m_strText(strText)
{
    startTimer(ninterval);
}
void BlinkLabel::timerEvent(QTimerEvent*){
    m_bBlink = !m_bBlink;
    setText (m_bBlink ? m_strText : "") ;
}
