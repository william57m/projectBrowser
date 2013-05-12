#ifndef PARAMETERSDIALOGBOX_H
#define PARAMETERSDIALOGBOX_H

#include <QDialog>
#include <QTabBar>

class ParametersDialogBox : public QDialog
{
    Q_OBJECT
private:
    QTabBar *tabBar;

public:
    explicit ParametersDialogBox(QWidget *parent = 0);

signals:
    
public slots:
    
};

#endif // PARAMETERSDIALOGBOX_H
