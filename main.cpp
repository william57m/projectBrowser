#include <QApplication>
#include <mainwindow.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set application property
    QCoreApplication::setApplicationName("NavUTBM");
    QCoreApplication::setApplicationVersion("1.0");
    QCoreApplication::setOrganizationName("UTBM");

    // Show main window
    MainWindow mw;
    mw.showNormal();

    // Execute app
    return app.exec();
}


