#include "customwebview.h"
#include <iostream>
#include <QBoxLayout>
#include <string>

using namespace std;

CustomWebView::CustomWebView(QWidget *parent, QWidget *realParent) :
    QWidget(parent)
{
    // Get real parent
    this->realParent = realParent;

    // Enable mouse tracking
    this->setMouseTracking(true);

    // Main Layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    // Init web view
    webView = new WebViewMouseTracking(this);
    webView->load(QUrl("http://www.google.com/"));
    webView->setMinimumSize(500,300);

    // Put webView in layout
    mainLayout->addWidget(webView);

    // Init right click menu
    rcm = new RightClickMenu(this);
    rcm->setHidden(true);

    // SIGNAL righClick on webView
    connect(webView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(openRCM(QPoint)));
    webView->setContextMenuPolicy(Qt::CustomContextMenu);

    // SIGNAL survol webView to real parent
    connect(this, SIGNAL(survolWebView()), this->parent(), SLOT(survolWebView()));
}

// ############################# Survol webView #############################

void CustomWebView::mouseMoveWebView()
{
    emit survolWebView();
}

// ############################ Open right click ############################

void CustomWebView::openRCM(QPoint pp)
{
    // Get cursor position from mainWindow
    //QPoint p = this->mapFromGlobal(QCursor::pos());
    //std::cout << "Right Click : " << pp.x() << " - " << pp.y() << std::endl;

    // Calculate position for widget
    int x = pp.x();// - this->pos().x();
    int y = pp.y();// - this->pos().y();

    if(x < 100) x = 100;
    if(y < 100) y = 100;

    if(x > this->width() - 100) x = this->width() - 100;
    if(y > this->height() - 100) y = this->height() - 100;

    // Set position right click menu
    rcm->setGeometry(x-100, y-100, 200, 200);
    rcm->setHidden(false);
}


// ############################ Slot right click ############################

void CustomWebView::closeRightClick()
{
    // Close right click
    rcm->setHidden(true);
    std::cout << "Passage fermeture" << std::endl;
}

void CustomWebView::clickItem(int b)
{
    // Close right click
    rcm->setHidden(true);

    // Action button
    switch(b)
    {
    case 0:
        std::cout << "Center button" << std::endl;
        std::cout << "Text: " << webView->selectedText().toStdString().c_str() << std::endl;
        webView->pageAction(QWebPage::Copy);
        break;
    case 45:
        std::cout << "Top button" << std::endl;
        break;
    case 135:
        std::cout << "Left button" << std::endl;
        webView->back();
        break;
    case 225:
        std::cout << "Bottom button" << std::endl;
        break;
    case 315:
        std::cout << "Right button" << std::endl;
        webView->forward();
        break;
    }
}

// ################################# Getters ################################

QWebView* CustomWebView::getWebView()
{
    return webView;
}
