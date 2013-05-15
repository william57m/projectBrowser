#ifndef NAVCONTROLLER_H
#define NAVCONTROLLER_H

#include <QPushButton>
#include <QLineEdit>
#include <QBoxLayout>
#include "custompushbutton.h"
#include "favright.h"

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
};

#endif // NAVCONTROLLER_H
