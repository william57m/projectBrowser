#include "customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent) { }

void CustomWidget::leaveEvent (QEvent *event)
{
    emit leaveEvent();
}

void CustomWidget::enterEvent (QEvent *event)
{
    emit enterEvent();
}

