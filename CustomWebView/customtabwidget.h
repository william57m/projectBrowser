#ifndef CUSTOMTABWIDGET_H
#define CUSTOMTABWIDGET_H

#include "CustomWebView/customwebview.h"
#include <QBoxLayout>
#include <QWidget>
#include <QToolButton>
#include <QAction>
#include <QPushButton>
#include <QTabBar>
#include <QTabWidget>
#include <iostream>

using namespace std;

class CustomTabWidget : public QWidget
{
    Q_OBJECT
public:
    // Constructor
    explicit CustomTabWidget(QWidget *parent = 0);

    //Getter
    CustomWebView *getActiveTab();

private:
    CustomWebView *activeCustomWebView;
    QHBoxLayout *mainLayout;
    QTabWidget *tabWidget;
    QAction *actionNouvelOnglet;
    
signals:

private slots:

    //Create new tab
    void nouvelOnglet();

    //Delete selected tab
    void fermerOnglet();
    
};

#endif // CUSTOMTABWIDGET_H
