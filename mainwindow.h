#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navcontroller.h"
#include <QtWebKit>
#include <QStack>
#include <QString>
#include "CustomWebView/customwebview.h"
#include "RightClick/rightclickmenu.h"
#include <QVBoxLayout>
#include <QGridLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    NavController *navController;

    QUrl *currentUrl;

    QVBoxLayout *mainLayout;
    QGridLayout *gridL;

    QWidget *widget;
    CustomWebView *webView;
    
signals:
    
public slots:
    void survolNavController();
    void survolWebView();

    void goURL();



    //void clickRightWebView(QPoint p);

};

#endif // MAINWINDOW_H
