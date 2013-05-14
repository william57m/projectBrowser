#include "customboxlayout.h"

CustomBoxLayout::CustomBoxLayout(QObject *parent) : QHBoxLayout() {}

void CustomBoxLayout::mouseMoveEvent(QMouseEvent *)
{
    emit moveLayout();
}
