#ifndef NAVBAR_H
#define NAVBAR_H

#include <QWidget>
#include <QBoxLayout>
#include "navcontroller.h"
#include "favright.h"

class NavBar : public QWidget
{
    Q_OBJECT
private:
    NavController *navController;
    FavRight *favRight;

public:
    // Constructor
    explicit NavBar(QWidget *parent = 0);

    // Getters
    NavController* getNavController();
    FavRight* getFavRight();

    // Event
    void mouseMoveEvent(QMouseEvent *);
    
signals:
    void survolNavBar();
    
    
};

#endif // NAVBAR_H
