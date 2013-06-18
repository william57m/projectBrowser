#include "customtabwidget.h"
#include <QDebug>
#include <iostream>

// ###################################################################
// CONSTRUCTOR
// ###################################################################
CustomTabWidget::CustomTabWidget(QWidget *parent, ParametersDialogBox *startUrl) :
    QWidget(parent)
{

    // Enable mouse tracking
    this->setMouseTracking(true);
    this->startUrl = startUrl;

    // Main Layout
    mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    //Tabs rack creation
    tabWidget = new QTabWidget;

    //Button to add tabs
    //QToolButton *toolb = new QToolButton(tabWidget);
    //toolb->setVisible(false);
    //toolb->setAutoRaise(true);
    //toolb->setText("+");
    //tabWidget->setCornerWidget(toolb, Qt::TopLeftCorner);

    //Ctrl-T shortcut to add tab
    actionNouvelOnglet = new QAction(tr("Nouvel onglet"), this);
    tabWidget->addAction(actionNouvelOnglet);
    actionNouvelOnglet->setShortcut(QKeySequence("Ctrl+T"));

    //Ctrl-W shortcut to close tab
    actionCloseOnglet = new QAction(tr("Fermer onglet"), this);
    tabWidget->addAction(actionCloseOnglet);
    actionCloseOnglet->setShortcut(QKeySequence("Ctrl+W"));

    //Creation of the first initial tab
    nouvelOnglet();

    //Click, shortcut connections to create/delete tabs
    //connect(toolb, SIGNAL(clicked()), this, SLOT(nouvelOnglet()));
    connect(actionNouvelOnglet, SIGNAL(triggered()), this, SLOT(nouvelOnglet()));
    connect(actionCloseOnglet, SIGNAL(triggered()), this, SLOT(fermerOnglet()));


    connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(fermerOnglet()));


    // To modify (Work just for the first tab)
    connect(activeCustomWebView, SIGNAL(clickNewTab()), this, SLOT(nouvelOnglet()));


}

// ############################# Nouvel Onglet #############################

void CustomTabWidget::nouvelOnglet()
{
    //You can close tabs only if there is more than 1 tab
    if(tabWidget->count()>=1)
    {
        tabWidget->setTabsClosable(true);
    }

    //CustomWebView creation and tab addition
    activeCustomWebView = new CustomWebView(this, this->parent(),(new QUrl(startUrl->getPageAccueil())));

    QString nomUrl = activeCustomWebView->getLoadedUrl()->toString();
    QIcon* iconUrl = new QIcon(nomUrl + "favicon.ico");   
    QIcon iconUrl2=QWebSettings::iconForUrl(QUrl(nomUrl));

    //QTabBar *tabBar = tabWidget->findChild<QTabBar *>(QLatin1String("qt_tabwidget_tabbar"));
    //tabBar->setTabButton(0, QTabBar::LeftSide, iconUrl2);

    int indexNouvelOnglet = tabWidget->addTab(activeCustomWebView, iconUrl2 , nomUrl);
    tabWidget->setCurrentIndex(indexNouvelOnglet);

    // Put customTabWidget in layout
    mainLayout->addWidget(tabWidget);

}


// ############################# Fermeture Onglet #############################

void CustomTabWidget::fermerOnglet()
{
    int cId = tabWidget->indexOf(tabWidget->currentWidget());
    //Delete the red cross on the tab when you delete one of the 2 remaining tabs
    if(tabWidget->count()==2)
    {
         tabWidget->setTabsClosable(false);
    }
    tabWidget->removeTab(tabWidget->currentIndex());
}



// ############################# Getter #############################

CustomWebView * CustomTabWidget::getActiveTab()
{
    return tabWidget->currentWidget();
}
