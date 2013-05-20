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
#include<QVector>
#include "../CustomWebView/customwebview.h"
#include "customwidget.h"
#include<QScrollArea>

using namespace std;

class FavRight : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit FavRight(QWidget *parent = 0);

    // Methods
    void mouseMoveEvent(QMouseEvent *);
    void defineFavWiget();
    void delButtonFav();
    void readFav();
    bool widgetOut;
    void wichBtn(QString);
    void deleteFavFromBtn(int idxBtn);

    // Getters
    FavRight *getWebView(QWebView *qWv);
    QUrl getUrl();
    QButtonGroup *getButtonFavDel();
    QButtonGroup *getButtonFav();


private:
    // Mutex
    QMutex *mutex;

    CustomWebView *webView;

    QUrl passedUrl;

    // Widget
    CustomWidget *favIcon;
    CustomWidget *favWidget;
    QLabel *favIconImg;

    bool etatLayoutFav;

    // Ludo
    QGridLayout *favsLayout;
    QScrollArea *scrollFav;

    QRect dimBar;

    QWebView *view;
    QSettings *settingFavs;

    QStringList *urlFav;
    QStringList *titleFav;
    QStringList *nbClick;

    QButtonGroup  *grpButtonFav;
    QButtonGroup  *grpButtonFavDel;

    QButtonGroup *pushBtnInstanciedFavDel;
    QButtonGroup *pushBtnInstanciedFav;

    //QList<QPushButton>pushBtnInstancied;

signals :
    //void survolFavIcon();
    //void clickedAddFav();
    //void leaveFavRight();
    //void doubleClicked();


public slots :
    QUrl getFavFromBtn(int idxFav);
    //void showFavWidget();
    void hideFavWidget();
};

#endif // FAVRIGHT_H
