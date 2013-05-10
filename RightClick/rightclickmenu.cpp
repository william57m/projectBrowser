#include "rightclickmenu.h"
#include <QPainter>
#include <QGridLayout>
#include <iostream>
#include "camembertbutton.h"
#include "rectbutton.h"

/* ##### Documentation right click #####
 *
 * SLOT TO IMPLEMENT IN USER CLASS
 *
 * +void clickItem(int) : When any button is pushed, a SIGNAL is send with button number.
 *        0 : Central button
 *       45 : Top button
 *      135 : Left button
 *      225 : Bottom button
 *      315 : Right button
 *
 * +void closeRightClick() : When mouse move outdoor area right click, a SIGNAL is send to hide the widget.
 *
 */

RightClickMenu::RightClickMenu(QWidget *parent) :
    QWidget(parent)
{
    // Set size
    this->setFixedSize(200,200);

    //QLayout *lay = new QLayout(this);
    // Main Layout - Grid
    QGridLayout *mainL = new QGridLayout(this);

    // Init Buttons

    /* Old disposition
    RectButton *btnCentral = new RectButton(30, 30, this);
    CamembertButton *btn1 = new CamembertButton(100,100, 0, 70, 45,90, this); // Haut
    CamembertButton *btn3 = new CamembertButton(100,100, 0,-70, 225,90, this); // Bas
    CamembertButton *btn4 = new CamembertButton(100,100, -70,0, 315,90, this); // Droite
    CamembertButton *btn2 = new CamembertButton(100,100, 70, 0, 135,90, this); // Gauche
    */

    RectButton *btnCentral = new RectButton(80, 80, 20, 20, this);
    CamembertButton *btn1 = new CamembertButton(80,40, -10, 10, 45,90, this); // Haut
    CamembertButton *btn3 = new CamembertButton(80,40, -10,-70, 225,90, this); // Bas
    CamembertButton *btn4 = new CamembertButton(40,80, -70,-10, 315,90, this); // Droite
    CamembertButton *btn2 = new CamembertButton(40,80, 10, -10, 135,90, this); // Gauche

    // Put buttons in main layout
    mainL->addWidget(btn1, 0, 1);
    mainL->addWidget(btn2, 1, 0);
    mainL->addWidget(btn3, 2, 1);
    mainL->addWidget(btn4, 1, 2);
    mainL->addWidget(btnCentral, 1, 1);

    // Connection
    connect(this, SIGNAL(closeRightClick()), this->parent(), SLOT(closeRightClick()));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::yellow);
    //this->setAutoFillBackground(true);
    //this->setPalette(p);
}

void RightClickMenu::leaveEvent(QEvent * event)
{
    // Emit to user class
    emit closeRightClick();
}
