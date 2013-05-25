#include "parametersdialogbox.h"

// ###################################################################
// CONSTRUCTOR
// ###################################################################
ParametersDialogBox::ParametersDialogBox(QWidget *parent) :
    QDialog(parent)
{
    // Set size
    this->setFixedSize(500,300);

    // Init tabWidet
    tabWidget = new QTabWidget(this);
    tabWidget->setGeometry(20,20,460,260);

    // Init widget
    generalWidget = new QWidget(this);
    generalWidget->setFixedSize(460,260);

    persoWidget = new QWidget(this);
    persoWidget->setFixedSize(660,260);

    // Init buttons
    btnApply = new QPushButton("Appliquer");
    btnValide = new QPushButton("OK");
    btnCancel = new QPushButton("Annuler");

    // Main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Layout button
    QHBoxLayout *layoutButton = new QHBoxLayout;
    layoutButton->addWidget(btnApply);
    layoutButton->addWidget(new QWidget);
    layoutButton->addWidget(new QWidget);
    layoutButton->addWidget(btnCancel);
    layoutButton->addWidget(btnValide);

    mainLayout->addWidget(tabWidget);
    mainLayout->addLayout(layoutButton);

    // Add widget to tabWidget
    tabWidget->addTab(generalWidget, "General");
    tabWidget->addTab(persoWidget, "Personnalisation");
}
