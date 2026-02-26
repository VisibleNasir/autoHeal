#pragma once

#include <QWidget>
#include "ui_ThemeManager.h"

class ThemeManager : public QWidget
{
	Q_OBJECT

public:
	ThemeManager(QWidget *parent = nullptr);
	~ThemeManager();

    public:
        enum Theme {
            Light = 0,
            Dark
        };

        static void applyTheme(Theme theme);
        static Theme loadTheme();

private:
	Ui::ThemeManager ui;
};
