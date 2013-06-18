#ifndef FAVRIGHT_H
#define FAVRIGHT_H
#include<QWidget>
#include<QLayout>
#include<QBoxLayout>
#include<stdio.h>
#include<QPushButton>
#include<QStringList>
#include<QSettings>
#include<QButtonGroup>
#include "../CustomWebView/customwebview.h"
#include "customwidget.h"
#include<QDebug>
#include <iostream>
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



    void deleButton();

private:

    CustomWebView *webView;

    QUrl passedUrl;

    // Widget
    CustomWidget *favIcon;
    CustomWidget *favWidget;
    QLabel *favIconImg;

    bool etatLayoutFav;
    int nbFav;

    QGridLayout *favsLayout;


    QWebView *view;
    QSettings *settingFavs;

    QStringList *urlFav;
    QStringList *titleFav;
    QStringList *nbClick;

    //buttons
    QButtonGroup  *grpButtonFav;
    QButtonGroup  *grpButtonFavDel;
    QButtonGroup *pushBtnInstanciedFavDel;
    QButtonGroup *pushBtnInstanciedFav;

    //QList<QPushButton>pushBtnInstancied;

signals :

public slots :
    QUrl getFavFromBtn(int idxFav);
    //void showFavWidget();
    void hideFavWidget();
};

#endif // FAVRIGHT_H
