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
#include "../CustomWebView/customwebview.h"
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

    QButtonGroup *getButtonFav();

    // Getters
    FavRight *getWebView(QWebView *qWv);
    QUrl getUrl();

private:
    // Mutex
    QMutex *mutex;

    CustomWebView *webView;

    QUrl passedUrl;

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
    QUrl getFavFromBtn(int idxFav);
    void showFavWidget();
    void hideFavWidget();
};

#endif // FAVRIGHT_H
