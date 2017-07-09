#include "realtimedata.h"
#include "ui_realtimedata.h"

Realtimedata::Realtimedata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Realtimedata)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Realtimedata::~Realtimedata()
{
    delete ui;
}
