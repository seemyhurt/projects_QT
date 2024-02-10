#include "mouseobserver.h"

MouseObserver::MouseObserver(QWidget* pwgt) : QLabel(pwgt)
{
    setAlignment (Qt::AlignCenter);
    setText("Mouse interactions\n(Press а mouse button)");

}
//----------------------------------------------------------------------
/*virtual*/void MouseObserver::mousePressEvent(QMouseEvent* pe)
{dumpEvent(pe, "Mouse Pressed");}

//----------------------------------------------------------------------
/*virtual*/void MouseObserver::mouseReleaseEvent(QMouseEvent* pe)
{dumpEvent(pe, "Mouse Released");}

//----------------------------------------------------------------------
/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent* pe)
{dumpEvent(pe, "Mouse Is Moving");}

//----------------------------------------------------------------------
void MouseObserver::dumpEvent(QMouseEvent* pe, const QString& strMsg)
{
    setText(strMsg
            + "\n buttons()=" + buttonsinfo(pe)
            + "\n х()=" + QString::number(pe->x())
            + "\n у()=" + QString::number(pe->y())
            + "\n globalX()=" + QString::number(pe->globalX())
            + "\n globalY()=" + QString::number(pe->globalY())
            + "\n modifiers()=" + modifiersinfo(pe)
            );
}

//----------------------------------------------------------------------
QString MouseObserver::modifiersinfo(QMouseEvent* pe)
{
    QString strModifiers;
    if(pe->modifiers() & Qt::ShiftModifier){
        strModifiers += "Shift ";
    }
    if(pe->modifiers() & Qt::ControlModifier){
        strModifiers += "Control ";
    }
    if(pe->modifiers() & Qt::AltModifier){
        strModifiers += "Alt";
    }
    return strModifiers;
}

//----------------------------------------------------------------------
QString MouseObserver::buttonsinfo(QMouseEvent* pe)
{
    QString strButtons;
    if(pe->buttons() & Qt::LeftButton)
        strButtons += "Left ";
    if(pe->buttons() & Qt::RightButton)
        strButtons += "Right ";
    if(pe->buttons() & Qt::MiddleButton)
        strButtons += "Middle";
    return strButtons;
}
