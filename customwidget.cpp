#include "customwidget.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent) { }

// ###################################################################
// EVENTS
// ###################################################################
void CustomWidget::leaveEvent (QEvent *event)
{
    // Unused
    Q_UNUSED(event);

    emit leaveEvent();
}

void CustomWidget::enterEvent (QEvent *event)
{
    // Unused
    Q_UNUSED(event);

    emit enterEvent();
}
