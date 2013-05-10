#include "webviewmousetracking.h"

WebViewMouseTracking::WebViewMouseTracking(QWidget *parent) :
    QWebView(parent)
{
    connect(this, SIGNAL(mouseMoveWebView()), this->parent(), SLOT(mouseMoveWebView()));
}

void WebViewMouseTracking::mouseMoveEvent(QMouseEvent *)
{
    emit mouseMoveWebView();
}
