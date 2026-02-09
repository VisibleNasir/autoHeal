#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AutoHeal.h"

class AutoHeal : public QMainWindow
{
    Q_OBJECT

public:
    AutoHeal(QWidget *parent = nullptr);
    ~AutoHeal();

private:
    Ui::AutoHealClass ui;
};

