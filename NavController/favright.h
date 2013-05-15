#ifndef FAVRIGHT_H
#define FAVRIGHT_H
#include<QWidget>
#include<QLabel>
#include<QLayout>
#include<QBoxLayout>
#include<iostream>
#include<QPainter>
#include<stdio.h>
#include<QPushButton>
#include<QWebView>
#include<QStringList>
#include<QMutex>
#include<QSettings>
#include<QButtonGroup>
//#include"favmanage.h"
#include "customwidget.h"

using namespace std;

class FavRight : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit FavRight(QWidget *parent = 0);

    // Set mutex
    bool tryLockMutex();
    void unLockMutex();

    // Methods
    void mouseMoveEvent(QMouseEvent *);
    void defineFavWiget(QPoint p);
    void delButtonFav();
    void readFav();
    bool widgetOut;
    void wichBtn(QString);

    // Getters
    FavRight *getWebView(QWebView *qWv);
    //FavManage *getFavManage();
    //QPushButton *getBtnAddFav();

private:
    // Mutex
    QMutex *mutex;

    // Widget
    CustomWidget *favIcon;
    CustomWidget *favWidget;
    QLabel *favIconImg;

    // Ludo
    QGridLayout *favsLayout;
    //QPushButton *btnAddFav;
    //QVector<QPushButton*> **btnAddFav;

    QWebView *view;
    QSettings *settingFavs;

    QStringList *urlFav;
    QStringList *titleFav;
    QStringList *nbClick;

    QButtonGroup  *buttonFav;
    bool isButtonFavCreated;

signals :
    void survolFavIcon();
    void clickedAddFav();
    void leaveFavRight();

public slots :
    void writeFav();
    void loadFav(int idxFav);
    void showFavWidget();
    void hideFavWidget();

};

#endif // FAVRIGHT_H
