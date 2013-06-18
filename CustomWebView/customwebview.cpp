#include "customwebview.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
CustomWebView::CustomWebView(QWidget *parent, QWidget *realParent, QUrl *startUrl) :
    QWidget(parent)
{
    // Get real parent
    this->realParent = realParent;
    this->startUrl = startUrl;

    // Enable mouse tracking
    this->setMouseTracking(true);

    // Main Layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);

    // Init web view
    webView = new WebViewMouseTracking(this);

    //QUrl startUrl = parent->getParamDialog.getPageAccueil();
    loadedUrl = startUrl;
    webView->load(*loadedUrl);
    webView->setMinimumSize(500,300);

    // Put webView in layout
    mainLayout->addWidget(webView);

    // Init right click menu
    rcm = new RightClickMenu(this);
    rcm->setHidden(true);

    // # Connect ###############################
    // Right click
    connect(webView,SIGNAL(rightClick(QContextMenuEvent*)), this, SLOT(openRCM(QContextMenuEvent*)));

    // Signal survol webView to real parent
    connect(this, SIGNAL(survolWebView()), this->realParent, SLOT(survolWebView()));

    //LUDO
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    //Load Fav from QSetting
    urlFav = new QStringList(settingFavs->value("Favoris/url").value<QStringList>());
    titleFav =  new QStringList(settingFavs->value("Favoris/titre").value<QStringList>());
    //nbClick =  new QStringList(settingFavs->value("Favoris/nbClick").value<QStringList>());

}

// ############################# Survol webView #############################

void CustomWebView::mouseMoveWebView()
{
    emit survolWebView();
}

// ############################ Open right click ############################

void CustomWebView::openRCM(QContextMenuEvent *event)
{
    // ################# Get data on target clicked ################

    QWebHitTestResult test = webView->page()->mainFrame()->hitTestContent(event->pos());
    QUrl url = test.linkUrl();

    // ############### Set camembert button / Target ###############

    itemClick = -1;
    rcm->getBtn(1)->enable(false);

    if(!url.isEmpty()) // Click on anything
    {
        itemClick = 0;
    }
    if(!test.imageUrl().isEmpty()) // Click on image
    {
        itemClick = 1;
        rcm->getBtn(1)->changeImgCam45(1);
        rcm->getBtn(1)->enable(true);
    }
    if(test.isContentSelected()) // Click on selected text
    {
        itemClick = 2;
        rcm->getBtn(1)->changeImgCam45(2);
        rcm->getBtn(1)->enable(true);
    }

    // ############## Enable/Disable back/next buttons #############

    if(webView->page()->history()->backItems(10).length() > 0) // Back possible
        rcm->getBtn(2)->enable(true);
    else // Back impossible
        rcm->getBtn(2)->enable(false);

    if(webView->page()->history()->forwardItems(10).length() > 0) // Next possible
        rcm->getBtn(4)->enable(true);
    else // Next impossible
        rcm->getBtn(4)->enable(false);

    // ################ Put right click under mouse ################

    // Get cursor position from event right click
    QPoint pp = event->pos();

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
}

void CustomWebView::clickItem(int b)
{
    // Close right click
    rcm->setHidden(true);

    // Action button
    switch(b)
    {
    case 0:

        emit clickNewTab();
        break;

    case 45:

        if(itemClick == 1) // Save image
        {
            QString chemin = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QDir::homePath(), "Fichiers HTML (*.html);;Fichiers PHP (*.php);;Fichiers CSS (*.css);;Fichiers JavaScript (*.js);;Fichiers texte (*.txt);;Tous les fichiers (*)");

            if (!chemin.isEmpty())
            {
                QFile fichierAEnregistrer(chemin);

                if (fichierAEnregistrer.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    QTextStream flux(&fichierAEnregistrer);
                    flux << webView->page()->mainFrame()->toHtml();
                    fichierAEnregistrer.close();
                }
            }
            webView->setFocus();
        }
        else if(itemClick == 2) // Copy on clipboard
        {
            webView->page()->triggerAction(QWebPage::Copy);
        }

        break;

    case 135:

        webView->back();
        break;

    case 225:

        settingFavs->setValue("Favoris/titre",*titleFav<<getWebView()->title().toStdString().c_str());
        settingFavs->setValue("Favoris/url", *urlFav<<getWebView()->url().toString());
        break;

    case 315:

        webView->forward();
        break;
    }
}

// ###################################################################
// GETTERS
// ###################################################################
QWebView* CustomWebView::getWebView()
{
    return webView;
}

QUrl* CustomWebView::getLoadedUrl()
{
    return loadedUrl;
}
