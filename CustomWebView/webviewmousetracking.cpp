#include "webviewmousetracking.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
WebViewMouseTracking::WebViewMouseTracking(QWidget *parent) :
    QWebView(parent)
{
    connect(this, SIGNAL(mouseMoveWebView()), this->parent(), SLOT(mouseMoveWebView()));

    QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DnsPrefetchEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavaEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PrintElementBackgrounds, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
}

// ###################################################################
// EVENTS
// ###################################################################

void WebViewMouseTracking::enterEvent (QEvent *event)
{
    Q_UNUSED(event);
    emit mouseMoveWebView();
}

void WebViewMouseTracking::contextMenuEvent(QContextMenuEvent * event)
{
    emit rightClick(event);
}
