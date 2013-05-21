#include "navcontroller.h"

NavController::NavController(QWidget *parent) :
    QWidget(parent)
{
    // Init object
    goUrl = new QPushButton("Go");
    urlBar = new QLineEdit;

    // Set property items
    urlBar->setText("http://");

    // Main layout
    mainLayout = new QHBoxLayout(this);
    this->setLayout(mainLayout);

    // Add items to mainLayout
    mainLayout->addWidget(urlBar);
    mainLayout->addWidget(goUrl);

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::gray);
    //this->setAutoFillBackground(true);
    //this->setPalette(p);
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
