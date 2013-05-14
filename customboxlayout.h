#ifndef CUSTOMBOXLAYOUT_H
#define CUSTOMBOXLAYOUT_H

#include <QBoxLayout>
#include <QMouseEvent>

class CustomBoxLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    explicit CustomBoxLayout(QObject *parent = 0);
    void mouseMoveEvent(QMouseEvent *);

protected:

signals:
    void moveLayout();
    
};

#endif // CUSTOMBOXLAYOUT_H
