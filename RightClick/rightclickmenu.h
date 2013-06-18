#ifndef RIGHTCLICKMENU_H
#define RIGHTCLICKMENU_H

#include <QWidget>
#include <QPainter>
#include <QGridLayout>
#include "camembertbutton.h"
#include "rectbutton.h"

class RightClickMenu : public QWidget
{
    Q_OBJECT
public:
    // Constructor
    explicit RightClickMenu(QWidget *parent = 0);

    // Event
    void leaveEvent(QEvent * event);

    // Getters
    CamembertButton* getBtn(int b);

private:
    // Camembert buttons
    CamembertButton *btn1;
    CamembertButton *btn2;
    CamembertButton *btn3;
    CamembertButton *btn4;

signals:
    void closeRightClick();
    
public slots:
};

#endif // RIGHTCLICKMENU_H
