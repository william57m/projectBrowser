#include "custompushbutton.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
CustomPushButton::CustomPushButton(QObject *parent) : QPushButton(parent) { }

// ###################################################################
// EVENTS
// ###################################################################
void CustomPushButton::leaveEvent (QEvent *event)
{
    // Unused
    Q_UNUSED(event);

    emit leaveEvent();
}

void CustomPushButton::enterEvent (QEvent *event)
{
    // Unused
    Q_UNUSED(event);

    emit enterEvent();
}
