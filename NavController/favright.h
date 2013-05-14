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
using namespace std;


class FavRight : public QWidget
{
    Q_OBJECT

public:
    bool tryLockMutex();
    void unLockMutex();
    //FavRight();
    explicit FavRight(QWidget *parent = 0);
    QLabel *getFavIcon();
    QWidget *getFavWidget();
    void mouseMoveEvent(QMouseEvent *);
    void defineFavWiget(QPoint p);
    //QPushButton *getBtnAddFav();
    void delButtonFav();

    void readFav();

    FavRight *getWebView(QWebView *qWv);
    //FavManage *getFavManage();

    void wichBtn(QString);


    void leaveEvent (QEvent *event);

private:
    QMutex *mutex;
    QLabel *favIcon;
    QWidget *favWidget;
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


};

#endif // FAVRIGHT_H
