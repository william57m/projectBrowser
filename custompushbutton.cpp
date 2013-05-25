#include "custompushbutton.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
CustomPushButton::CustomPushButton(QObject *parent) : QPushButton() { }

// ###################################################################
// EVENTS
// ###################################################################
void CustomPushButton::leaveEvent (QEvent *event)
{
    emit leaveEvent();
}

void CustomPushButton::enterEvent (QEvent *event)
{
    emit enterEvent();
}
