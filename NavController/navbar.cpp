#include "navbar.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
NavBar::NavBar(QWidget *parent) :
    QWidget(parent)
{
    // Init items
    navController = new NavController(this);
    favRight = new FavRight(this);

    // Main Layout
    mainLayout = new QHBoxLayout(this);
    this->setLayout(mainLayout);

    // Put items into layout
    //this->addWidget(navController);
    //this->addWidget(favRight);
    //this->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(navController);
    mainLayout->addWidget(favRight);
    mainLayout->setContentsMargins(0,0,0,0);

    // Connect
    connect(this, SIGNAL(survolNavBar()), this->parent(), SLOT(survolNavBar()));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::red);
    //this->setAutoFillBackground(true);
    //this->setPalette(p);
}

// ###################################################################
// EVENT
// ###################################################################
void NavBar::mouseMoveEvent(QMouseEvent *)
{
    emit survolNavBar();
}

// ###################################################################
// GETTERS
// ###################################################################
NavController* NavBar::getNavController()
{
    return navController;
}

FavRight* NavBar::getFavRight()
{
    return favRight;
}


void NavBar::newFavRight()
{
    favRight = new FavRight(this);
    favRight->defineFavWiget();
    favRight->readFav();
    mainLayout->addWidget(favRight);
}

void NavBar::delFavRight()
{
    mainLayout->removeWidget(favRight);
    delete favRight;
}
