#include "favright.h"
#include <iostream>

FavRight::FavRight(QWidget *parent) : QWidget(parent)
{
    /* Open QSetting */
    //settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    //std::cout<<"ouverture QSetting"<<std::endl;

    etatLayoutFav=false;
    // Init widget
    favIcon = new CustomWidget(this);
    favIcon->setFixedSize(50,50);

    favWidget = new CustomWidget(this);
    favIcon->setMouseTracking(true);

    // Init this
    this->setMouseTracking(true);
    this->setFixedSize(50,50);

    /* Init fav icon */
    QString favS;
    favS= QChar(0x05,0x26);
    favIconImg = new QLabel(favIcon);
    favIconImg->setText(favS);
    favIconImg->setMouseTracking(true);
    QFont police("calibri");
    police.setPointSize (18);
    favIconImg->setFont(police);
    /*-------------*/

    // Button
    grpButtonFav = new QButtonGroup(this);
    grpButtonFavDel = new QButtonGroup(this);
    //   pushBtnInstanciedFavDel = new QButtonGroup(this);
    //  pushBtnInstanciedFav = new QButtonGroup(this);

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::yellow);
    this->setAutoFillBackground(true);
    this->setPalette(p);
    p.setColor(QPalette::Background, Qt::blue);
    favIcon->setAutoFillBackground(true);
    favIcon->setPalette(p);

    // Connection
    //connect(buttonFav,SIGNAL(buttonClicked(int)),this,SLOT(loadFav(int)));
    connect(favWidget, SIGNAL(leaveEvent()), this, SLOT(hideFavWidget()));
    //connect(favWidget, SIGNAL(leaveEvent()), this, SLOT(hideFavWidget()));
    //connect(buttonFav,SIGNAL(buttonClicked(int)),this,SLOT(loadFav(int)));
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
    // Hide favWidget
    this->favWidget->setHidden(true);
}

// ############################# Others #############################
void FavRight::defineFavWiget()
{
    QPoint mappedPoint;
    mappedPoint = mapToGlobal(QPoint(0,0));
    int mx = mappedPoint.x();
    int my = mappedPoint.y();
    favWidget->setGeometry(mx-275,my+25,300,500);
    favWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
    favWidget->show();
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
        /*  for (int i=0; i<urlFav->size();++i)
        {
            std::cout<<"add dans grpButton "<<i<<std::endl;
            grpButtonFav->removeButton(pushBtnInstanciedFav->button(i));
            grpButtonFavDel->removeButton(pushBtnInstanciedFavDel->button(i));
        }*/

        favsLayout->removeWidget(favWidget);
        favsLayout->deleteLater();
        std::cout<<"delete "<<std::endl;
        etatLayoutFav=false;

        delete favsLayout;
        delete settingFavs;
        delete urlFav;
        delete titleFav;

        /* delete pushBtnInstanciedFav;
        delete pushBtnInstanciedFavDel;
        pushBtnInstanciedFavDel = new QButtonGroup(this);
        pushBtnInstanciedFav = new QButtonGroup(this);*/
    }
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    urlFav = new QStringList(settingFavs->value("Favoris/url").value<QStringList>());
    titleFav =  new QStringList(settingFavs->value("Favoris/titre").value<QStringList>());
    favsLayout = new QGridLayout();

    favWidget->setLayout(favsLayout);
    std::cout<<"Dans readFav : "<<urlFav->size()<<std::endl;


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
        favsLayout->addWidget(grpButtonFav->buttons().at(i),i,0,0,4);
        favsLayout->addWidget(grpButtonFavDel->buttons().at(i),i,5,0,1);

        /*pushBtnInstanciedFav->addButton(btnAddFav[i],i);
        pushBtnInstanciedFavDel->addButton(btnDel[i],i);*/
        std::cout<<"push ok "<<std::endl;
    }
}

QUrl FavRight::getFavFromBtn(int idxBtn)
{
    QStringList *nbC =  new QStringList(settingFavs->value("Favoris/nbClick").value<QStringList>());
    QString iNbC=nbC->at(idxBtn);
    int cTmp = iNbC.toInt();
    cTmp++;
    nbC->replace(idxBtn,QString::number(cTmp));
    settingFavs->setValue("Favoris/nbClick", *nbC);
    std::cout<<"nb clique : "<<cTmp<<std::endl;
    return urlFav->at(idxBtn);
}

void FavRight::deleteFavFromBtn(int idxBtn)
{

    std::cout<<"CLICK ON : "<<idxBtn<<std::endl;
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

