#ifndef CUSTOMWEBVIEW_H
#define CUSTOMWEBVIEW_H

#include <QWidget>
#include <QWebView>
#include <QBoxLayout>
#include <QSettings>
#include <QUrl>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QWebView>
#include <QContextMenuEvent>
#include <QWebHitTestResult>
#include <QWebHistory>

#include "webviewmousetracking.h"
#include "../RightClick/rightclickmenu.h"

#include <string>

#include <iostream>
using namespace std;

class CustomWebView : public QWidget
{
    Q_OBJECT
private:
    // Attributes
    WebViewMouseTracking *webView;
    RightClickMenu *rcm;
    QWidget *realParent;
    QUrl *loadedUrl;
    int itemClick;
    QUrl *startUrl;

    // Favorites manage
    QSettings *settingFavs;
    QStringList *urlFav;
    QStringList *titleFav;
    //QStringList *nbClick;

public:
    // Constructor
    explicit CustomWebView(QWidget *parent = 0, QWidget *realParent = 0, QUrl *startUrl = 0);

    // Getter
    QWebView* getWebView();
    QUrl* getLoadedUrl();

signals:
    void survolWebView(); // Signal to real parent
    void clickNewTab(); // Signal to send to customTabWidget

public slots:
    // Open right click
    void openRCM(QContextMenuEvent *event);

    // Slot for mouse move WebView
    void mouseMoveWebView();

    // Slot for right click
    void closeRightClick();
    void clickItem(int b);
};

#endif // CUSTOMWEBVIEW_H
