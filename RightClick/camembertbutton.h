#ifndef CAMEMBERTBUTTON_H
#define CAMEMBERTBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QLabel>

class CamembertButton : public QWidget
{
    Q_OBJECT
public:
    // Constructor
    CamembertButton(int w, int h, int x, int y, int base, int orientation, QWidget *parent = 0);

    // Methode
    void changeImgCam45(int i);
    void enable(bool e);

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
    bool enabled;

    // Image label (For Top button to change image)
    QLabel  *label_img;

    // Others
    int i;
    
signals:
    void mouseMove();
    void click(int b);
    
public slots:

};

#endif // CAMEMBERTBUTTON_H
