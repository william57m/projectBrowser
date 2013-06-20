#ifndef NAVBAR_H
#define NAVBAR_H

#include <QWidget>
#include <QBoxLayout>
#include <QToolBar>
#include "navcontroller.h"
#include "favright.h"
#include "QMainWindow"
class NavBar : public QWidget
{
    Q_OBJECT
private:
    NavController *navController;
    FavRight *favRight;
    QHBoxLayout *mainLayout;

public:
    // Constructor
    explicit NavBar(QWidget *parent = 0);

    // Getters
    NavController* getNavController();
    FavRight* getFavRight();

    // Event
    void mouseMoveEvent(QMouseEvent *);

    //ludo
 //void delFavright();
  //  void createFavright();


    //TEST
    void newFavRight();
    void delFavRight();
    
signals:
    void survolNavBar();
    
    
};

#endif // NAVBAR_H
