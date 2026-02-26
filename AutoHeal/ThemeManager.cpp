#include "thememanager.h"
#include <QApplication>
#include <QPalette>
#include <QStyleFactory>
#include <QSettings>

void ThemeManager::applyTheme(Theme theme)
{
    QPalette palette;

    // Use Fusion for consistent behavior
    qApp->setStyle(QStyleFactory::create("Fusion"));

    if (theme == Dark)
    {
        QColor windowColor(37, 37, 38);
        QColor baseColor(30, 30, 30);
        QColor alternateColor(45, 45, 45);
        QColor textColor(220, 220, 220);
        QColor buttonColor(53, 53, 53);
        QColor highlightColor(0, 120, 215);

        palette.setColor(QPalette::Window, windowColor);
        palette.setColor(QPalette::WindowText, textColor);

        palette.setColor(QPalette::Base, baseColor);
        palette.setColor(QPalette::AlternateBase, alternateColor);

        palette.setColor(QPalette::ToolTipBase, textColor);
        palette.setColor(QPalette::ToolTipText, textColor);

        palette.setColor(QPalette::Text, textColor);
        palette.setColor(QPalette::Button, buttonColor);
        palette.setColor(QPalette::ButtonText, textColor);

        palette.setColor(QPalette::BrightText, Qt::red);

        palette.setColor(QPalette::Highlight, highlightColor);
        palette.setColor(QPalette::HighlightedText, Qt::white);

        // Disabled state colors
        palette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
        palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(127, 127, 127));
    }
    else
    {
        palette = QApplication::style()->standardPalette();
    }

    qApp->setPalette(palette);

    QSettings settings;
    settings.setValue("theme", theme);
}

ThemeManager::Theme ThemeManager::loadTheme()
{
    QSettings settings;
    return static_cast<Theme>(
        settings.value("theme", Light).toInt()
        );
}