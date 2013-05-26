#ifndef WEBVIEWMOUSETRACKING_H
#define WEBVIEWMOUSETRACKING_H

#include <QWebView>

class WebViewMouseTracking : public QWebView
{
    Q_OBJECT
public:
    // Constructor
    explicit WebViewMouseTracking(QWidget *parent = 0);

    // Event
    void enterEvent (QEvent *event);
    
signals:
    void mouseMoveWebView();
    void rightClick(QContextMenuEvent *event);
    
private slots:
    void contextMenuEvent(QContextMenuEvent * event);
    
};

#endif // WEBVIEWMOUSETRACKING_H
