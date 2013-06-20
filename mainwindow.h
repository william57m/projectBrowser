#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtWebKit>
#include <QVBoxLayout>
#include <QMenuBar>

#include "CustomWebView/customtabwidget.h"
#include "RightClick/rightclickmenu.h"
#include "ParamDialogBox/parametersdialogbox.h"
#include "NavController/navbar.h"
#include <QBoxLayout>
#include <iostream>
#include <QMessageBox>
#include <QGridLayout>
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    // Main Layout
    QVBoxLayout *mainLayout;

    // Menu
    QMenuBar *menuBar;
    QMenu *menuFile;
    QAction *menuParam;

    // Parameters dialog
    ParametersDialogBox *paramDialog;

    // Nav controller
    NavBar *navBar;

    // Web View
    CustomTabWidget *customTabWidget;
    

signals:
    
public slots:
    void survolNavBar();
    void survolWebView();
    void changeURL();
    void getParamDialog();

    void goURL();

    void showParamDialog();
    void slotGoUrl();
    void changeTittle(QString urlTitle);

    //ludo
    void loadFav(int idBtn);
    void delFav(int idxBtnDel);
};

#endif // MAINWINDOW_H
