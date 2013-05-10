#ifndef WEBVIEWMOUSETRACKING_H
#define WEBVIEWMOUSETRACKING_H

#include <QWebView>

class WebViewMouseTracking : public QWebView
{
    Q_OBJECT
public:
    explicit WebViewMouseTracking(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *);
    
signals:
    void mouseMoveWebView();
    
public slots:
    
};

#endif // WEBVIEWMOUSETRACKING_H
