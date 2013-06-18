#include "mainwindow.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
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

    // Init parameters dialog box
    paramDialog = new ParametersDialogBox(this);
    QUrl *startUrl = new QUrl(paramDialog->getPageAccueil());

    // Nav controller
    navBar = new NavBar(this);
    navBar->setMaximumHeight(50);
    navBar->setMouseTracking(true);

    // Web engine
    customTabWidget = new CustomTabWidget(this,paramDialog);

    // Add items to main layout
    mainLayout->addWidget(navBar);
    mainLayout->addWidget(customTabWidget);

    // Set central widget
    this->setCentralWidget(centralWidget);

    // Connect button to show paramDialog
    connect(menuParam, SIGNAL(triggered()), this, SLOT(showParamDialog()));

    // Connect action from navController to webView
    connect(navBar->getNavController()->getBtnGoUrl(), SIGNAL(clicked()), this, SLOT(goURL()));

    //Replace url
    connect(customTabWidget->getActiveTab()->getWebView(), SIGNAL(urlChanged(QUrl)),this,SLOT(changeURL()));
    connect(customTabWidget->getActiveTab()->getWebView(), SIGNAL(titleChanged(QString)),this,SLOT(changeTittle(QString)));

    //Connect to load bm from button
    connect(navBar->getFavRight()->getButtonFav(),SIGNAL(buttonClicked(int)),this,SLOT(loadFav(int)));
    connect(navBar->getFavRight()->getButtonFavDel(),SIGNAL(buttonClicked(int)),this,SLOT(delFav(int)));

}

// ###################################################################
// METHODS
// ###################################################################

// ###################### Show parameters dialog #####################
void MainWindow::showParamDialog()
{
    paramDialog->exec();
}

void MainWindow::getParamDialog()
{
    return paramDialog;
}

// ################## Slot to interact on web view ###################
void MainWindow::goURL()
{
    customTabWidget->getActiveTab()->getWebView()->load(navBar->getNavController()->getUrlBar()->text());
}

void MainWindow::changeURL()
{
    navBar->getNavController()->getUrlBar()->setText(customTabWidget->getActiveTab()->getWebView()->url().toString());
}

// ######################## Manage Favorites #########################
void MainWindow::loadFav(int idBtn)
{
    customTabWidget->getActiveTab()->getWebView()->load(navBar->getFavRight()->getFavFromBtn(idBtn));

}
void MainWindow::delFav(int idxBtnDel)
{
    navBar->getFavRight()->deleteFavFromBtn(idxBtnDel);


    navBar->delFavRight();
    navBar->newFavRight();



}

// ################ Detect survol for show/hide navBar ###############
void MainWindow::survolNavBar()
{


    // Show navController and favRight
    navBar->getNavController()->setHidden(false);
    navBar->getFavRight()->setHidden(false);

    // Set size
    navBar->setMinimumHeight(50);
    navBar->setMaximumHeight(50);


    if(!navBar->getFavRight()->isHidden())
    {
        navBar->delFavRight();
        navBar->newFavRight();

        //Connect to load bm from button
        connect(navBar->getFavRight()->getButtonFav(),SIGNAL(buttonClicked(int)),this,SLOT(loadFav(int)));
        connect(navBar->getFavRight()->getButtonFavDel(),SIGNAL(buttonClicked(int)),this,SLOT(delFav(int)));
    }
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


