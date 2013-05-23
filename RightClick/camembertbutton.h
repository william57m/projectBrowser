#ifndef CAMEMBERTBUTTON_H
#define CAMEMBERTBUTTON_H

#include <QWidget>
#include <QPainter>
#include <iostream>
#include <QLabel>

class CamembertButton : public QWidget
{
    Q_OBJECT
public:
    // Constructor
    CamembertButton(int w, int h, int x, int y, int base, int orientation, QWidget *parent = 0);

    // Events
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void leaveEvent(QEvent * event);

private:
    // Property
    int x;
    int y;
    int base;
    int orientation;

    // Others
    int i;
    
signals:
    void mouseMove();
    void click(int b);
    
public slots:

};

#endif // CAMEMBERTBUTTON_H
