#include "AutoHeal.h"
#include <QtWidgets/QApplication>
#include "QtWidgetsClass.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ThemeManager::applyTheme(ThemeManager::loadTheme());
    QCoreApplication::setOrganizationName("MyCompany");
    QCoreApplication::setApplicationName("FilterApp");
    QtWidgetsClass window;
    window.show();
    return app.exec();
}
