#include "favright.h"

FavRight::FavRight(QWidget *parent) : QWidget(parent)
{

    /*Open QSetting*/
    settingFavs = new QSettings("UTBMGL40", "BrowserGL");
    std::cout<<"ouverture QSetting"<<std::endl;
    /*-------------*/

    /*add fav icon */
    QString favS;
    favS= QChar(0x05,0x26);
    favIcon = new QLabel();
    favIcon->setText(favS);
    QFont police("calibri");
    police.setPointSize (26);
    favIcon->setFont(police);
    /*-------------*/

    /*Init layout*/
    mainLayout = new QGridLayout();
    this->setLayout(mainLayout);
    /*--------------*/

    //WILL
    this->setFixedSize(50,50);
    //this->setStyleSheet("background-color: #800000");

    // Color
    QPalette p(palette());
    p.setColor(QPalette::Background, Qt::yellow);
    this->setAutoFillBackground(true);
    this->setPalette(p);

    /*Init widget*/
    favWidget = new QWidget();
    mainLayout->addWidget(favIcon,0,0);
    /*-----------*/

    buttonFav = new QButtonGroup(favWidget);
    isButtonFavCreated = true;

    mutex = new QMutex();

    connect(this, SIGNAL(survolFavIcon()), this->parent(), SLOT(survolFavIcon()));
    connect(buttonFav,SIGNAL(buttonClicked(int)),this,SLOT(loadFav(int)));
}

void FavRight::mouseMoveEvent(QMouseEvent *)
{
    emit survolFavIcon();
}

QLabel *FavRight::getFavIcon()
{
    return favIcon;
}

QWidget *FavRight::getFavWidget()
{
    return favWidget;
}

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

// Event

void FavRight::leaveEvent (QEvent *event)
{
    this->setHidden(true);
    this->setMaximumSize(9999,10);
    this->unLockMutex();
    //emit leaveFavRight();
}
