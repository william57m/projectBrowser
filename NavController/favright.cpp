#include "favright.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
FavRight::FavRight(QWidget *parent) : QWidget(parent)
{

    // Init widget
    favIcon = new CustomWidget(this);
    favIcon->setFixedSize(50,50);
    favWidget = new CustomWidget(this);
    favIcon->setMouseTracking(true);

    //to check layout stat
    etatLayoutFav=false;

    // Init this
    this->setMouseTracking(true);
    this->setFixedSize(50,50);

    /* Init fav icon */
    QString favS;
    favS= QChar(0x05,0x26);
    favIconImg = new QLabel(favIcon);
    favIconImg->setGeometry(0,10,30,30);
    favIconImg->setText(favS);
    favIconImg->setMouseTracking(true);
    favIcon->setGeometry(0,10,30, 30);
    QFont police("calibri");
    police.setPointSize (30);
    favIconImg->setFont(police);
    /*-------------*/

    // Button
    grpButtonFav = new QButtonGroup(this);
    grpButtonFavDel = new QButtonGroup(this);

    // Connection
    connect(favWidget, SIGNAL(leaveEvent()), this, SLOT(hideFavWidget()));
}

// ############################# Events #############################
void FavRight::mouseMoveEvent(QMouseEvent *)
{
    this->favWidget->setHidden(false);
    this->defineFavWiget();
}

void FavRight::hideFavWidget()
{
    this->readFav();
    this->favWidget->setHidden(true);
}

// ############################# Others #############################
void FavRight::defineFavWiget()
{
    int length;
    if(nbFav!=0)
        length=nbFav*20;
    else
        length = 10;
    QPoint mappedPoint;
    mappedPoint = mapToGlobal(QPoint(0,0));
    int mx = mappedPoint.x();
    int my = mappedPoint.y();
    favWidget->setGeometry(mx-275,my+25,300,length);
    favWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
}

FavRight *FavRight::getWebView(QWebView *qWv)
{
    view = qWv;
    return this;
}

void FavRight::readFav()
{
    if(etatLayoutFav==true)
    {
        favsLayout->removeWidget(favWidget);
        favsLayout->deleteLater();
        etatLayoutFav=false;
        delete favsLayout;
        delete settingFavs;
        delete urlFav;
        delete titleFav;
    }
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    urlFav = new QStringList(settingFavs->value("Favoris/url").value<QStringList>());
    titleFav =  new QStringList(settingFavs->value("Favoris/titre").value<QStringList>());
    favsLayout = new QGridLayout(this);
    nbFav = favsLayout->columnCount();
    favWidget->setLayout(favsLayout);
    etatLayoutFav=true;
    /* Init fav icon */
    QString favS;
    favS= QChar(0x17,0x27);
    /*-------------*/

    for(int i=0; i<urlFav->size();++i)
    {
        QPushButton *btnAddFav[urlFav->size()];
        QPushButton *btnDel[urlFav->size()];

        btnAddFav[i] = new QPushButton(titleFav->at(i));

        btnDel[i]=new QPushButton(favS);

        btnAddFav[i]->setStyleSheet("background-color:#c5b3bd ; border-radius: 2");
        btnDel[i]->setStyleSheet("background-color:#c5b3bd ; border-radius: 2");

        grpButtonFav->addButton(btnAddFav[i],i);
        grpButtonFavDel->addButton(btnDel[i],i);

        favsLayout->addWidget(grpButtonFav->buttons().at(i),i,0,1,5);
        favsLayout->addWidget(grpButtonFavDel->buttons().at(i),i,6,1,1);

    }
}


QUrl FavRight::getFavFromBtn(int idxBtn)
{
    return urlFav->at(idxBtn);
}

void FavRight::deleteFavFromBtn(int idxBtn)
{
    //Open QSettings
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    urlFav = new QStringList(settingFavs->value("Favoris/url").value<QStringList>());
    titleFav =  new QStringList(settingFavs->value("Favoris/titre").value<QStringList>());

    urlFav->removeAt(idxBtn);
    titleFav->removeAt(idxBtn);
    settingFavs->setValue("Favoris/url", *urlFav);
    settingFavs->setValue("Favoris/titre", *titleFav);
}

QButtonGroup *FavRight::getButtonFav()
{
    return grpButtonFav;
}

QButtonGroup *FavRight::getButtonFavDel()
{
    return grpButtonFavDel;
}


