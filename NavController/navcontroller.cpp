#include "navcontroller.h"
#include <iostream>

NavController::NavController(QWidget *parent) :
    QWidget(parent)
{
    // Init object
    goUrl = new QPushButton("Go");
    urlBar = new QLineEdit;

    // Set property items
    urlBar->setText("http://");

    // Main layout
    mainLayout = new QGridLayout;
    this->setLayout(mainLayout);

    // URL Layout
    urlLayout = new CustomBoxLayout(this);
    urlLayout->addWidget(urlBar);
    urlLayout->addWidget(goUrl);

    // Init favRight
    favRight = new FavRight(this);
    favRight->setMouseTracking(true);

    // Add items to mainLayout
    mainLayout->addLayout(urlLayout,0,0);
    mainLayout->addWidget(favRight,0,1);

    // Connexion
    connect(this, SIGNAL(survolNavController()), this->parent(), SLOT(survolNavController()));
    connect(urlLayout, SIGNAL(moveLayout()), this, SLOT(hideFavRight2()));

    connect(favRight, SIGNAL(leaveFavRight()), this, SLOT(hideFavRight2()));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(p);
}

void NavController::mouseMoveEvent(QMouseEvent *)
{
    emit survolNavController();
}

// ############################# Getters #############################
QPushButton* NavController::getBtnGoUrl()
{
    return goUrl;
}

QLineEdit* NavController::getUrlBar()
{
    return urlBar;
}

// ############################ favRight ############################
void NavController::survolFavIcon()
{
    favRight->getFavWidget()->setHidden(false);

    favRight->setMaximumSize(9999,60);

    QPoint pPara;
    QPoint p = QCursor::pos();

    // Calculate position
    pPara.setX( p.x());
    pPara.setY( p.y());

    favRight->defineFavWiget(pPara);
    favRight->readFav();
}

void NavController::hideFavRight()
{
    favRight->setHidden(true);
    favRight->getFavWidget()->setHidden(true);
    favRight->setMaximumSize(9999,10);
    favRight->unLockMutex();
}

void NavController::hideFavRight2()
{
    std::cout << "Passage hideFavRight" << std::endl;

    favRight->setHidden(true);
    favRight->getFavWidget()->setHidden(true);
    favRight->setMaximumSize(9999,10);
    favRight->unLockMutex();
}

void NavController::showFavRight()
{
    favRight->setHidden(false);
}
