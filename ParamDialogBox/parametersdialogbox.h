#ifndef PARAMETERSDIALOGBOX_H
#define PARAMETERSDIALOGBOX_H

#include <QDialog>
#include <QTabWidget>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>

class ParametersDialogBox : public QDialog
{
    Q_OBJECT
private:
    // Tab widget
    QTabWidget *tabWidget;

    // Widget
    QWidget *generalWidget;
    QWidget *persoWidget;

    // Buttons
    QPushButton *btnApply;
    QPushButton *btnValide;
    QPushButton *btnCancel;

public:
    explicit ParametersDialogBox(QWidget *parent = 0);

signals:
    
public slots:
    
};

#endif // PARAMETERSDIALOGBOX_H
