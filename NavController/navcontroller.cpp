#include "navcontroller.h"
#include <QAction>
#include <iostream>

// ###################################################################
// CONSTRUCTOR
// ###################################################################
NavController::NavController(QWidget *parent) :
    QWidget(parent)
{
    // Init object
    goUrl = new QPushButton("Go");
    urlBar = new QLineEdit;

    // TEST
    QAction *actionGoUrl = new QAction(tr("Go"), this);
    actionGoUrl->setShortcut(Qt::Key_Return);
    urlBar->addAction(actionGoUrl);

    // CODE
    connect(actionGoUrl, SIGNAL(triggered()), this->parent()->parent(), SLOT(slotGoUrl()));

    // Set property items
    urlBar->setText("http://");

    // Main layout
    mainLayout = new QHBoxLayout(this);
    this->setLayout(mainLayout);

    // Add items to mainLayout
    mainLayout->addWidget(urlBar);
    //mainLayout->addWidget(goUrl);

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    //this->setAutoFillBackground(true);
    //this->setPalette(p);
}

// ###################################################################
// GETTERS
// ###################################################################
QPushButton* NavController::getBtnGoUrl()
{
    return goUrl;
}

QLineEdit* NavController::getUrlBar()
{
    return urlBar;
}
