#include "rectbutton.h"
#include <QPainter>
#include <iostream>

RectButton::RectButton(int w, int h, int x, int y, QWidget *parent) :
    QWidget(parent)
{
    // Init attributes
    this->x = x;
    this->y = y;
    this->i = 0;

    // Set size
    this->setFixedSize(w, h);

    // Enable mouse tracking
    this->setMouseTracking(true);

    // Connection
    connect(this, SIGNAL(mouseMove()), this, SLOT(repaint()));
    connect(this, SIGNAL(click(int)), this->parent()->parent(), SLOT(clickItem(int)));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    //this->setAutoFillBackground(true);
    //this->setPalette(p);
}

void RectButton::paintEvent(QPaintEvent *)
{
    if(i==0)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setOpacity(0.2);
        painter.setBrush(Qt::black);
        painter.drawRect(x, y, 40, 40);
    }
    else
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setOpacity(0.4);
        painter.setBrush(Qt::black);
        painter.drawRect(x-3,y-3, 46, 46);
    }
}

void RectButton::mousePressEvent(QMouseEvent *)
{
    // Emit to user class
    emit click(0);
}

void RectButton::mouseMoveEvent(QMouseEvent *)
{
    if(this->underMouse())
    {
        i++;
        emit mouseMove();
    }
}

void RectButton::leaveEvent(QEvent * event)
{
    i=0;
    emit mouseMove();
}
