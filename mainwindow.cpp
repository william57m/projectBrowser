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

    // Init main layout
    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    // Menu Bar
    menuBar = new QMenuBar(this);
    menuFile = new QMenu("Fichier", this);
    menuParam = new QAction("Parametres", this);

    this->setMenuBar(menuBar);
    menuBar->addMenu(menuFile);
    menuFile->addAction(menuParam);

    connect(menuParam, SIGNAL(triggered()), this, SLOT(showParamDialog()));

    // Init parameters dialog box
    paramDialog = new ParametersDialogBox;

    // Nav controller
    navController = new NavController(this);
    navController->setMaximumHeight(50);
    navController->setMouseTracking(true);

    // Web engine
    webView = new CustomWebView(this, this);

    // Add items to main layout
    mainLayout->addWidget(navController);
    mainLayout->addWidget(webView);

    // Set central widget
    this->setCentralWidget(centralWidget);

    // Connect action from navController to webView
    connect(navController->getBtnGoUrl(), SIGNAL(clicked()), this, SLOT(goURL()));
}

// ######################## Show parameters dialog #######################
void MainWindow::showParamDialog()
{
    std::cout << "Show param dialog" << std::endl;
    paramDialog->exec();
}

// ############## Detect survol for show/hide navController ##############
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

