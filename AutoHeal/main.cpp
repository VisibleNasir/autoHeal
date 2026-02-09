#include "AutoHeal.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    AutoHeal window;
    window.show();
    return app.exec();
}
