#include "mainwindow.h"
#include <QBoxLayout>
#include <iostream>
#include <QMessageBox>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Declare centralWidget
    QWidget *centralWidget = new QWidget;

    // Nav controller
    navController = new NavController(this);
    navController->setMaximumHeight(50);
    navController->setMouseTracking(true);

    // Web engine
    webView = new CustomWebView(this, this);

    // Init main layout
    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    // Add items to main layout
    mainLayout->addWidget(navController);
    mainLayout->addWidget(webView);

    // Set central widget
    this->setCentralWidget(centralWidget);

    // Connect action from navController to webView
    connect(navController->getBtnGoUrl(), SIGNAL(clicked()), this, SLOT(goURL()));

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::yellow);

    //this->setAutoFillBackground(true);
    //this->setPalette(p);
}

void MainWindow::survolNavController()
{
     navController->getUrlBar()->setHidden(false);
     navController->getBtnGoUrl()->setHidden(false);
     navController->setMaximumHeight(50);
}

void MainWindow::survolWebView()
{
    navController->getUrlBar()->setHidden(true);
    navController->getBtnGoUrl()->setHidden(true);
    navController->setMaximumHeight(20);
}

// ##################### Slot to interact on web view #####################
void MainWindow::goURL()
{
    webView->getWebView()->load(navController->getUrlBar()->text());
}

