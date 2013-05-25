#ifndef CUSTOMWEBVIEW_H
#define CUSTOMWEBVIEW_H

#include <QWidget>
#include <QWebView>
#include "../RightClick/rightclickmenu.h"
#include "webviewmousetracking.h"
#include <QSettings>
#include <QUrl>
#include <iostream>
#include <QBoxLayout>
#include <string>

using namespace std;

class CustomWebView : public QWidget
{
    Q_OBJECT
private:
    WebViewMouseTracking *webView;
    RightClickMenu *rcm;
    QWidget *realParent;
    QUrl *loadedUrl;
    int itemClick;

    //LUDO
    QSettings *settingFavs;
    QStringList *urlFav;
    QStringList *titleFav;
    //QStringList *nbClick;

public:
    // Constructor
    explicit CustomWebView(QWidget *parent = 0, QWidget *realParent = 0);

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
