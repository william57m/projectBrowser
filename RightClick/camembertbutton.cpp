#include "camembertbutton.h"


CamembertButton::CamembertButton(int w, int h, int x, int y, int base, int orientation, QWidget *parent) :
    QWidget(parent), x(x), y(y), base(base), orientation(orientation), i(0)
{
    // Set size
    this->setFixedSize(w,h);

    // Enable mouse tracking
    this->setMouseTracking(true);

    // Connexion
    connect(this, SIGNAL(mouseMove()), this, SLOT(repaint()));
    connect(this, SIGNAL(click(int)), this->parent()->parent(), SLOT(clickItem(int)));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::blue);
    //this->setAutoFillBackground(true);
    //this->setPalette(p);


    // Put icon
    QLabel  *label_img  = new QLabel(this);
    QPixmap *pixmap_img;

    switch(base)
    {
    case 45:
        pixmap_img = new QPixmap(":/ressources/icon/save.png");
        label_img->setGeometry(30,15,20,20); // x - y
        break;
    case 135:
        pixmap_img = new QPixmap(":/ressources/icon/back.png");
        label_img->setGeometry(15,30,20,20); // x - y
        break;
    case 225:
        pixmap_img = new QPixmap(":/ressources/icon/favoris.png");
        label_img->setGeometry(30,5,20,20); // x - y
        break;
    case 315:
        pixmap_img = new QPixmap(":/ressources/icon/next.png");
        label_img->setGeometry(5,30,20,20); // x - y
        break;
    }

    label_img->setPixmap(*pixmap_img);
}

void CamembertButton::paintEvent(QPaintEvent *)
{
    if(i==0)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setOpacity(0.5);
        painter.setBrush(Qt::black);
        painter.drawPie(x,y,100,100,base*16,orientation*16);
    }
    else
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setOpacity(0.7);
        painter.setBrush(Qt::black);
        painter.drawPie(x-5,y-5,110,110,base*16,orientation*16);
    }
}

void CamembertButton::mouseMoveEvent(QMouseEvent *)
{
    if(this->underMouse())
    {
        // Increment i
        i++;

        // Emit to this
        emit mouseMove();
    }
}

void CamembertButton::leaveEvent(QEvent * event)
{
    // RAZ i
    i=0;

    // Emit to this
    emit mouseMove();
}

void CamembertButton::mousePressEvent(QMouseEvent *)
{
    // Emit to user class
    emit click(base);
}
