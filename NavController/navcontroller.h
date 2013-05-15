#ifndef NAVCONTROLLER_H
#define NAVCONTROLLER_H

#include <QPushButton>
#include <QLineEdit>

#include "custompushbutton.h"
#include "favright.h"
#include <QPaintEvent>
#include <QLabel>
#include <QGridLayout>
#include <QBoxLayout>


class NavController : public QWidget
{
    Q_OBJECT
private:
    // Main Layout
    QHBoxLayout  *mainLayout;

    // Items
    QPushButton *goUrl;
    QLineEdit *urlBar;

public:
    // Constructor
    explicit NavController(QWidget *parent = 0);

    // Getters
    QPushButton* getBtnRefresh();
    QPushButton* getBtnGoUrl();
    QLineEdit* getUrlBar();

    // Event
    void mouseMoveEvent(QMouseEvent *);

signals:
    void survolNavController();

public slots:
    
};

#endif // NAVCONTROLLER_H
