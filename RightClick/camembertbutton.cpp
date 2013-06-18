#include "camembertbutton.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
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

    // Init boolean enabled
    enabled = true;

    // Put initial icon
    label_img  = new QLabel(this);
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

// ###################################################################
// METHODS
// ###################################################################
void CamembertButton::changeImgCam45(int i)
{
    // Attributs
    QPixmap *pixmap_img;

    // Check target
    if(i==1) // On selected text
        pixmap_img = new QPixmap(":/ressources/icon/save.png");
    else if(i==2) // On image
        pixmap_img = new QPixmap(":/ressources/icon/cut.png");

    // Change image top button
    label_img->setPixmap(*pixmap_img);
    this->repaint();
}

void CamembertButton::enable(bool e)
{
    enabled = e;
}

// ###################################################################
// EVENTS
// ###################################################################
void CamembertButton::paintEvent(QPaintEvent *)
{
    // Init QPainter
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(Qt::black);

    if(enabled)
    {
        if(i==0)
        {
            painter.setOpacity(0.6);
            painter.drawPie(x,y,100,100,base*16,orientation*16);
        }
        else // Agrandis
        {
            painter.setOpacity(0.85);
            painter.drawPie(x-5,y-5,110,110,base*16,orientation*16);
        }
    }
    else
    {
        painter.setOpacity(0.2);
        painter.drawPie(x,y,100,100,base*16,orientation*16);
    }

}

void CamembertButton::mouseMoveEvent(QMouseEvent *)
{
    if(enabled)
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
    // Unused
    Q_UNUSED(event);

    // RAZ i
    i=0;

    // Emit to this
    emit mouseMove();
}

void CamembertButton::mousePressEvent(QMouseEvent *)
{
    // Emit to user class
    if(enabled)
        emit click(base);
}
