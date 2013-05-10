#include "customboxlayout.h"

CustomBoxLayout::CustomBoxLayout(QObject *parent) : QHBoxLayout() { }

void CustomBoxLayout::leaveEvent (QEvent *event)
{
    emit leaveEvent();
}

void CustomBoxLayout::enterEvent (QEvent *event)
{
    emit enterEvent();
}
