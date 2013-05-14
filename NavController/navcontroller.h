#ifndef NAVCONTROLLER_H
#define NAVCONTROLLER_H

#include <QPushButton>
#include <QLineEdit>
#include "custompushbutton.h"
#include "customboxlayout.h"

#include <QPaintEvent>
#include <QLabel>
#include <QGridLayout>
#include <QBoxLayout>

#include "favright.h"


class NavController : public QWidget
{
    Q_OBJECT
private:
    // Main Layout
    QGridLayout  *mainLayout;

    // Layout URL Bar
    CustomBoxLayout *urlLayout;

    // Items
    QPushButton *goUrl;
    QLineEdit *urlBar;
    FavRight *favRight;


public:
    // Constructor
    explicit NavController(QWidget *parent = 0);

    // Getters
    QPushButton* getBtnRefresh();
    QPushButton* getBtnGoUrl();
    QLineEdit* getUrlBar();

    // Event
    void mouseMoveEvent(QMouseEvent *);

    // Show/Hide FavRight
    void hideFavRight();
    void showFavRight();

signals:
    void survolNavController();

public slots:
    void survolFavIcon();
    void hideFavRight2();
    
};

#endif // NAVCONTROLLER_H
