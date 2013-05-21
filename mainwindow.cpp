#include "mainwindow.h"
#include <QBoxLayout>
#include <iostream>
#include <QMessageBox>
#include <QGridLayout>
#include "NavController/navbar.h"

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
    paramDialog = new ParametersDialogBox(this);

    // Nav controller
    navBar = new NavBar(this);
    navBar->setMaximumHeight(50);
    navBar->setMouseTracking(true);

    // Web engine
    customTabWidget = new CustomTabWidget(this);

    // Add items to main layout
    mainLayout->addWidget(navBar);
    mainLayout->addWidget(customTabWidget);

    // Set central widget
    this->setCentralWidget(centralWidget);

    // Connect action from navController to webView
    connect(navBar->getNavController()->getBtnGoUrl(), SIGNAL(clicked()), this, SLOT(goURL()));

    //Replace url

    connect(customTabWidget->getActiveTab()->getWebView(), SIGNAL(urlChanged(QUrl)),this,SLOT(changeURL()));
    connect(customTabWidget->getActiveTab()->getWebView(), SIGNAL(titleChanged(QString)),this,SLOT(changeTittle(QString)));

    //Connect to load bm from button
    connect(navBar->getFavRight()->getButtonFav(),SIGNAL(buttonClicked(int)),this,SLOT(loadFav(int)));
    connect(navBar->getFavRight()->getButtonFavDel(),SIGNAL(buttonClicked(int)),this,SLOT(delFav(int)));

}

// ######################## Show parameters dialog #######################
void MainWindow::showParamDialog()
{
    std::cout << "Show param dialog" << std::endl;
    paramDialog->exec();
}

// ##################### Slot to interact on web view #####################
void MainWindow::goURL()
{
    customTabWidget->getActiveTab()->getWebView()->load(navBar->getNavController()->getUrlBar()->text());
}

void MainWindow::changeURL()
{
    navBar->getNavController()->getUrlBar()->setText(customTabWidget->getActiveTab()->getWebView()->url().toString());
}

//LUDO
void MainWindow::loadFav(int idBtn)
{
    customTabWidget->getActiveTab()->getWebView()->load(navBar->getFavRight()->getFavFromBtn(idBtn));
}
void MainWindow::delFav(int idxBtnDel)
{
    navBar->getFavRight()->deleteFavFromBtn(idxBtnDel);

}

// ################## Detect survol for show/hide navBar ##################
void MainWindow::survolNavBar()
{
    // Show navController and favRight
    navBar->getNavController()->setHidden(false);
    navBar->getFavRight()->setHidden(false);

    // Set size
    navBar->setMinimumHeight(50);
    navBar->setMaximumHeight(50);
}

void MainWindow::survolWebView()
{
    // Hide navController and favRight
    navBar->getNavController()->setHidden(true);
    navBar->getFavRight()->setHidden(true);

    // Set size
    navBar->setMinimumHeight(20);
    navBar->setMaximumHeight(20);
}

void MainWindow::changeTittle(QString url)
{
    this->setWindowTitle(url);
}
