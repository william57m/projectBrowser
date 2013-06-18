#ifndef RECTBUTTON_H
#define RECTBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QLabel>

class RectButton : public QWidget
{
    Q_OBJECT
public:
    // Constructor
    explicit RectButton(int w, int h, int x, int y, QWidget *parent = 0);

    // Events
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void leaveEvent(QEvent * event);

private:
    // Property
    int i;
    int x;
    int y;

signals:
    void mouseMove();
    void click(int b);
    
public slots:
    
};

#endif // RECTBUTTON_H
