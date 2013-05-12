#include "parametersdialogbox.h"

ParametersDialogBox::ParametersDialogBox(QWidget *parent) :
    QDialog(parent)
{
    // Set size
    this->setFixedSize(400,200);

    // Init tabBar
    tabBar = new QTabBar(this);

    // Set title tabBar
    tabBar->addTab("General");
    tabBar->addTab("Onglet");
    tabBar->addTab("Confidentialite");
    tabBar->addTab("Personnalisation");
}
