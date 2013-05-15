#include "favright.h"
#include <iostream>

FavRight::FavRight(QWidget *parent) : QWidget(parent)
{
    /* Open QSetting */
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    //std::cout<<"ouverture QSetting"<<std::endl;

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
    police.setPointSize (26);
    favIconImg->setFont(police);
    /*-------------*/

    // Button
    buttonFav = new QButtonGroup(favWidget);
    isButtonFavCreated = true;

    // Mutex
    mutex = new QMutex();

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
}

// ############################# Events #############################
void FavRight::mouseMoveEvent(QMouseEvent *)
{
    //std::cout << "Mouse move event" << std::endl;

    // Show favWidget
    this->favWidget->setHidden(false);

    // Get cursor position
    QPoint pPara(QCursor::pos().x(), QCursor::pos().y());

    this->defineFavWiget(pPara);
    //this->readFav();
}

void FavRight::showFavWidget()
{
    //std::cout << "Enter favIcon" << std::endl;
}

void FavRight::hideFavWidget()
{
    //std::cout << "Leave favIcon" << std::endl;

    // Hide favWidget
    this->favWidget->setHidden(true);

    // Unlock Mutex
    this->unLockMutex();
}

// ############################# Others #############################
void FavRight::defineFavWiget(QPoint p)
{
    favWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
    favWidget->setGeometry(p.x()-300,p.y(),300,500);
}

FavRight *FavRight::getWebView(QWebView *qWv)
{
    view = qWv;
    return this;
}

void FavRight::writeFav()
{

    //Load Fav from QSetting
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    urlFav = new QStringList(settingFavs->value("Favoris/url").value<QStringList>());
    titleFav =  new QStringList(settingFavs->value("Favoris/titre").value<QStringList>());
    nbClick =  new QStringList(settingFavs->value("Favoris/nbClick").value<QStringList>());

    std::cout<<"Taille favoris : "<<urlFav->size()<<std::endl;

    //Si favoris non définis
    if (!titleFav->contains(view->title().toStdString().c_str(), Qt::CaseInsensitive))
    {
        std::cout<<"Ecriture de favoris"<<std::endl;

        std::cout<<view->title().toStdString()<<std::endl;
        std::cout<<view->url().toString().toStdString()<<std::endl;

        settingFavs->setValue("Favoris/titre",*titleFav<<view->title().toStdString().c_str());
        settingFavs->setValue("Favoris/url", *urlFav<<view->url().toString());
        settingFavs->setValue("Favoris/nbClick", *nbClick<<0);

    }
    else
        std::cout<<"Deja en favoris"<<std::endl;
}

void FavRight::readFav()
{
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    urlFav = new QStringList(settingFavs->value("Favoris/url").value<QStringList>());
    titleFav =  new QStringList(settingFavs->value("Favoris/titre").value<QStringList>());
    std::cout<<"Dans readFav : "<<urlFav->size()<<std::endl;

    if (mutex->tryLock())
    {

        favsLayout = new QGridLayout();
        favWidget->setLayout(favsLayout);
        for(int i=0; i<urlFav->size();i++)
        {
            std::cout<<urlFav->size()<<std::endl;
            QPushButton *btnAddFav[urlFav->size()];
            btnAddFav[i] = new QPushButton(titleFav->at(i));

            QPainter painter(this);
            painter.setRenderHint(QPainter::Antialiasing, true);
            //painter.setOpacity(0.5);
            painter.setBrush(Qt::black);
            //btnAddFav[i]->pa

            buttonFav->addButton(btnAddFav[i],i);
            favsLayout->addWidget(buttonFav->buttons().at(i));
            std::cout<<"id1 : "<<buttonFav->id(btnAddFav[i])<<std::endl;

            for(int j=0; j<urlFav->size();++j)
                std::cout<<"id : "<<buttonFav->id(btnAddFav[j])<<std::endl;
        }
    }

    else
    {
        if(isButtonFavCreated==true)
        {
            isButtonFavCreated=false;
            favsLayout->removeWidget(favWidget);
            favsLayout->deleteLater();
            delete favsLayout;
            std::cout<<"delete "<<std::endl;
        }
    }
}

bool FavRight::tryLockMutex()
{
    return mutex->tryLock();
}

void FavRight::unLockMutex()
{
    mutex->unlock();
}

void FavRight::loadFav(int idxBtn)
{

    view->load(urlFav->at(idxBtn));
    QStringList *nbC =  new QStringList(settingFavs->value("Favoris/nbClick").value<QStringList>());
    QString iNbC=nbC->at(idxBtn);
    int cTmp = iNbC.toInt();
    cTmp++;
    nbC->replace(idxBtn,QString::number(cTmp));
    settingFavs->setValue("Favoris/nbClick", *nbC);
    std::cout<<"nb clique : "<<cTmp<<std::endl;

    // nbClick->at(idxBtn)=nbClick->at(idxBtn)+1;
    //settingFavs->setValue("Favoris/nbClick", *nbClick->at(idxBtn));
}
