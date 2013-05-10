#ifndef CUSTOMWEBVIEW_H
#define CUSTOMWEBVIEW_H

#include <QWidget>
#include <QWebView>
#include "../RightClick/rightclickmenu.h"
#include "webviewmousetracking.h"

class CustomWebView : public QWidget
{
    Q_OBJECT
private:
    WebViewMouseTracking *webView;
    RightClickMenu *rcm;
    QWidget *realParent;

public:
    // Constructor
    explicit CustomWebView(QWidget *parent = 0, QWidget *realParent = 0);

    // Getter
    QWebView* getWebView();

signals:
    void survolWebView(); // Signal to real parent

public slots:
    // Open right click
    void openRCM(QPoint p);

    // Slot for mouse move WebView
    void mouseMoveWebView();

    // Slot for right click
    void closeRightClick();
    void clickItem(int b);
};

#endif // CUSTOMWEBVIEW_H
