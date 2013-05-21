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
    webView = new CustomWebView(this, this);

    // Add items to main layout
    mainLayout->addWidget(navBar);
    mainLayout->addWidget(webView);

    // Set central widget
    this->setCentralWidget(centralWidget);

    // Connect action from navController to webView
    connect(navBar->getNavController()->getBtnGoUrl(), SIGNAL(clicked()), this, SLOT(goURL()));

    //Replace url
    connect(webView->getWebView(), SIGNAL(urlChanged(QUrl)),this,SLOT(changeURL()));
    connect(webView->getWebView(), SIGNAL(titleChanged(QString)),this,SLOT(changeTittle(QString)));


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
    webView->getWebView()->load(navBar->getNavController()->getUrlBar()->text());
}

void MainWindow::changeURL()
{
    navBar->getNavController()->getUrlBar()->setText(webView->getWebView()->url().toString());
}

//LUDO
void MainWindow::loadFav(int idBtn)
{
    webView->getWebView()->load(navBar->getFavRight()->getFavFromBtn(idBtn));
}
void MainWindow::delFav(int idxBtnDel)
{
    navBar->getFavRight()->deleteFavFromBtn(idxBtnDel);

}

// ################## Detect survol for show/hide navBar ##################
void MainWindow::survolNavBar()
{
    // Show navController
    //navBar->getNavController()->setHidden(false);
    navBar->getNavController()->getUrlBar()->setHidden(false);
    navBar->getNavController()->getBtnGoUrl()->setHidden(false);
    navBar->getNavController()->setMaximumHeight(50);

    navBar->getFavRight()->setHidden(false);

    navBar->setMaximumHeight(50);
}

void MainWindow::survolWebView()
{

    // Hide navController
    //navBar->getNavController()->setHidden(true);
    navBar->getNavController()->getUrlBar()->setHidden(true);
    navBar->getNavController()->getBtnGoUrl()->setHidden(true);
    navBar->getNavController()->setMaximumHeight(0);

    //navBar->getFavRight()->setHidden(true);

    navBar->setMaximumHeight(20);
}

void MainWindow::changeTittle(QString url)
{
    this->setWindowTitle(url);
}

