#include "rectbutton.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
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

    // Put icon
    QLabel  *label_img  = new QLabel(this);
    QPixmap *pixmap_img = new QPixmap(":/ressources/icon/plus.png");
    label_img->setPixmap(*pixmap_img);
    label_img->setGeometry(25,25,30,30);

    // Connection
    connect(this, SIGNAL(mouseMove()), this, SLOT(repaint()));
    connect(this, SIGNAL(click(int)), this->parent()->parent(), SLOT(clickItem(int)));
}

// ###################################################################
// EVENTS
// ###################################################################
void RectButton::paintEvent(QPaintEvent *)
{
    // Init QPainter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::black);

    if(i==0)
    {
        painter.setOpacity(0.5);
        painter.drawRect(x, y, 40, 40);
    }
    else
    {
        painter.setOpacity(0.7);
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
    // Unused
    Q_UNUSED(event);

    // Set i
    i=0;

    // Emit signal
    emit mouseMove();
}
