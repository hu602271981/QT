#include "storeinformation2.h"
#include "ui_storeinformation2.h"

Storeinformation2::Storeinformation2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Storeinformation2)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Storeinformation2::~Storeinformation2()
{
    delete ui;
}
