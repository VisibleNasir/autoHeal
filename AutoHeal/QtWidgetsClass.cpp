#include "QtWidgetsClass.h"
#include <QMessageBox>
#include <QStyle>
QtWidgetsClass::QtWidgetsClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    QWidget* central = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(central);

    darkBtn = new QPushButton("Dark Mode");
    lightBtn = new QPushButton("Light Mode");
    clearBtn = new QPushButton("Clear Preferences");

    layout->addWidget(darkBtn);
    layout->addWidget(lightBtn);
    layout->addWidget(clearBtn);

    setCentralWidget(central);

    // Connections
    connect(darkBtn, &QPushButton::clicked, this, &QtWidgetsClass::applyDarkTheme);
    connect(lightBtn, &QPushButton::clicked, this, &QtWidgetsClass::applyLightTheme);

    connect(clearBtn, &QPushButton::clicked, [=]() {
        QSettings settings("MyCompany", "FilterApp");
        settings.clear();
        QMessageBox::information(this, "Settings", "All preferences cleared.\nRestart app.");
        });

    loadSettings();
}

QtWidgetsClass::~QtWidgetsClass()
{}

void QtWidgetsClass::applyDarkTheme()
{
    QPalette darkPalette;

    darkPalette.setColor(QPalette::Window, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(30, 30, 30));
    darkPalette.setColor(QPalette::AlternateBase, QColor(45, 45, 45));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(60, 60, 60));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Highlight, QColor(0, 120, 215));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    QSettings settings("MyCompany", "FilterApp");
    settings.setValue("theme", "dark");
}

void QtWidgetsClass::applyLightTheme()
{
    qApp->setPalette(style()->standardPalette());

    QSettings settings("MyCompany", "FilterApp");
    settings.setValue("theme", "light");
}

void QtWidgetsClass::closeEvent(QCloseEvent* event)
{
    saveSettings();
    QMainWindow::closeEvent(event);
}

void QtWidgetsClass::saveSettings()
{
    QSettings settings("MyCompany", "FilterApp");
    settings.setValue("geometry", saveGeometry());
}

void QtWidgetsClass::loadSettings()
{
    QSettings settings("MyCompany", "FilterApp");

    restoreGeometry(settings.value("geometry").toByteArray());

    QString theme = settings.value("theme", "light").toString();

    if (theme == "dark")
        applyDarkTheme();
    else
        applyLightTheme();
}