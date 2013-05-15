#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = 0);

protected:
    void leaveEvent (QEvent *event);
    void enterEvent (QEvent *event);

signals:
    void enterEvent();
    void leaveEvent();
    
};

#endif // CUSTOMWIDGET_H
