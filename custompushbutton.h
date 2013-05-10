#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QPushButton>

class CustomPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CustomPushButton(QObject *parent = 0);

protected:
    void leaveEvent (QEvent *event);
    void enterEvent (QEvent *event);

signals:
    void enterEvent();
    void leaveEvent();

};

#endif // CUSTOMPUSHBUTTON_H
