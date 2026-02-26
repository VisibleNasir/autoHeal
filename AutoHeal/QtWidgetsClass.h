#pragma once
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSettings>
#include <QPalette>
#include <QCloseEvent>

#include <QMainWindow>
#include "ui_QtWidgetsClass.h"

class QtWidgetsClass : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgetsClass(QWidget *parent = nullptr);
	~QtWidgetsClass();
protected:
    void closeEvent(QCloseEvent* event) override;

private:
    void applyDarkTheme();
    void applyLightTheme();
    void loadSettings();
    void saveSettings();

    QPushButton* darkBtn;
    QPushButton* lightBtn;
    QPushButton* clearBtn;

private:
	Ui::QtWidgetsClassClass ui;
};

