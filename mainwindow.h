#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "navcontroller.h"
#include <QtWebKit>
#include "CustomWebView/customwebview.h"
#include "RightClick/rightclickmenu.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <ParamDialogBox/parametersdialogbox.h>

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
    NavController *navController;

    // Web View
    CustomWebView *webView;
    
signals:
    
public slots:
    void survolNavController();
    void survolWebView();

    void goURL();


    void showParamDialog();


    //void clickRightWebView(QPoint p);

};

#endif // MAINWINDOW_H
