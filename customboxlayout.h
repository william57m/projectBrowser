#ifndef CUSTOMBOXLAYOUT_H
#define CUSTOMBOXLAYOUT_H

#include <QBoxLayout>

class CustomBoxLayout : public QHBoxLayout
{
    Q_OBJECT
public:
    explicit CustomBoxLayout(QObject *parent = 0);

protected:
    void leaveEvent (QEvent *event);
    void enterEvent (QEvent *event);

signals:
    void enterEvent();
    void leaveEvent();
    
};

#endif // CUSTOMBOXLAYOUT_H
