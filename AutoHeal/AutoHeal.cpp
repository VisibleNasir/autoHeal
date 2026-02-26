#include "AutoHeal.h"
#include <QShortcut>
#include <QKeyEvent>
#include <QSettings>

AutoHeal::AutoHeal(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    
}

AutoHeal::~AutoHeal()
{}


void AutoHeal::keyPressEvent(QKeyEvent * event)
{
    
}




void AutoHeal::closeEvent(QCloseEvent* event)
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}

void AutoHeal::loadSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
}