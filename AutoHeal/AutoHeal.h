#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AutoHeal.h"

class AutoHeal : public QMainWindow
{
    Q_OBJECT

public:
    AutoHeal(QWidget *parent = nullptr);
    ~AutoHeal();

protected:
    

private slots:
    
private:
    Ui::AutoHealClass ui;
};

