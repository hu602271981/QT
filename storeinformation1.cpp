#include "storeinformation1.h"
#include "ui_storeinformation1.h"

StoreInformation1::StoreInformation1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreInformation1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

StoreInformation1::~StoreInformation1()
{
    delete ui;
}
