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
    emit leaveEvent();
}

void CustomWidget::enterEvent (QEvent *event)
{
    emit enterEvent();
}
