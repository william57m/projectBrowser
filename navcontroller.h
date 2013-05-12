#ifndef NAVCONTROLLER_H
#define NAVCONTROLLER_H

#include <QPushButton>
#include <QLineEdit>
#include "custompushbutton.h"
#include "customboxlayout.h"

#include <QPaintEvent>

class NavController : public QWidget
{
    Q_OBJECT
private:
    QPushButton *goUrl;
    QLineEdit *urlBar;
    CustomBoxLayout *mainLayout;

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
