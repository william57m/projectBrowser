#ifndef FAVRIGHT_H
#define FAVRIGHT_H
#include<QWidget>
#include<QLabel>
#include<QLayout>
#include <QBoxLayout>
#include <iostream>
#include <QPainter>
#include <stdio.h>
#include <QPushButton>
//#include"favmanage.h"
#include <QWebView>
#include <QStringList>
#include <QMutex>
#include<QSettings>
#include<QButtonGroup>
#include "customwidget.h"

using namespace std;


class FavRight : public QWidget
{
    Q_OBJECT

public:
    bool tryLockMutex();
    void unLockMutex();

    explicit FavRight(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *);
    void defineFavWiget(QPoint p);
    //QPushButton *getBtnAddFav();
    void delButtonFav();

    void readFav();

    bool widgetOut;

    FavRight *getWebView(QWebView *qWv);
    //FavManage *getFavManage();

    void wichBtn(QString);

private:
    QMutex *mutex;
    QLabel *favIconImg;

    CustomWidget *favIcon;
    CustomWidget *favWidget;

    QGridLayout *mainLayout;

    QGridLayout *favsLayout;


    //QPushButton *btnAddFav;

    // QVector<QPushButton*> **btnAddFav;

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
