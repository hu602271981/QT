#include "Displacement_HD.h"
#include "ui_Displacement_HD.h"
#include "QKeyEvent"
#include "dialog2.h"
#include "main.h"
Dia2::Dia2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dia2)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Dia2::~Dia2()
{
    delete ui;
}
