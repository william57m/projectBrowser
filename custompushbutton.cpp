#include "custompushbutton.h"

CustomPushButton::CustomPushButton(QObject *parent) : QPushButton() { }

void CustomPushButton::leaveEvent (QEvent *event)
{
    emit leaveEvent();
}

void CustomPushButton::enterEvent (QEvent *event)
{
    emit enterEvent();
}
