#include "rightclickmenu.h"

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

// ###################################################################
// CONSTRUCTOR
// ###################################################################
RightClickMenu::RightClickMenu(QWidget *parent) :
    QWidget(parent)
{
    // Set size
    this->setFixedSize(200,200);

    // Main Layout
    QGridLayout *mainL = new QGridLayout(this);

    // Init Buttons
    RectButton *btnCentral = new RectButton(80, 80, 20, 20, this);
    btn1 = new CamembertButton(80,40, -10, 10, 45,90, this); // Haut
    btn3 = new CamembertButton(80,40, -10,-70, 225,90, this); // Bas
    btn4 = new CamembertButton(40,80, -70,-10, 315,90, this); // Droite
    btn2 = new CamembertButton(40,80, 10, -10, 135,90, this); // Gauche

    // Put buttons in main layout
    mainL->addWidget(btn1, 0, 1);
    mainL->addWidget(btn2, 1, 0);
    mainL->addWidget(btn3, 2, 1);
    mainL->addWidget(btn4, 1, 2);
    mainL->addWidget(btnCentral, 1, 1);

    // Connection
    connect(this, SIGNAL(closeRightClick()), this->parent(), SLOT(closeRightClick()));
}

// ###################################################################
// EVENT
// ###################################################################
void RightClickMenu::leaveEvent(QEvent * event)
{
    // Unused
    Q_UNUSED(event);

    // Emit to user class
    emit closeRightClick();
}

// ###################################################################
// GETTER
// ###################################################################
CamembertButton* RightClickMenu::getBtn(int b)
{
    switch(b)
    {
        case 1: return btn1;
        case 2: return btn2;
        case 3: return btn3;
        default: return btn4;
    }
}
