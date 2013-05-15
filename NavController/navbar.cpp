#include "navbar.h"
#include <QBoxLayout>

NavBar::NavBar(QWidget *parent) :
    QWidget(parent)
{
    // Init items
    navController = new NavController(this);
    favRight = new FavRight(this);

    // Main Layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    this->setLayout(mainLayout);

    // Put items into layout
    mainLayout->addWidget(navController);
    mainLayout->addWidget(favRight);
    mainLayout->setContentsMargins(0,0,0,10);

    // Connect
    connect(this, SIGNAL(survolNavBar()), this->parent(), SLOT(survolNavBar()));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::red);
    this->setAutoFillBackground(true);
    this->setPalette(p);
}

// ############################# Events #############################
void NavBar::mouseMoveEvent(QMouseEvent *)
{
    emit survolNavBar();
}

// ############################# Getters #############################
NavController* NavBar::getNavController()
{
    return navController;
}

FavRight* NavBar::getFavRight()
{
    return favRight;
}
