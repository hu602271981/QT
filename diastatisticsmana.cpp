#include "diastatisticsmana.h"
#include "ui_diastatisticsmana.h"
#include "QDebug"

DiastatisticsMana::DiastatisticsMana(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiastatisticsMana)
{
     ui->setupUi(this);
     this->setWindowFlags(Qt::FramelessWindowHint);
     ui->close->setCheckable (false );
     ui->open->setCheckable (false );
     ui->clear->setCheckable (false );
    QObject::connect(ui->close,SIGNAL(clicked()),this,SLOT(close_data_slots())); //数据统计功能关闭
    QObject::connect(ui->open,SIGNAL(clicked()),this,SLOT(open_data_slots()));//数据统计功能开启
    QObject::connect(ui->clear,SIGNAL(clicked()),this,SLOT(clear_data_slots())); //数据统计功能清除

}

DiastatisticsMana::~DiastatisticsMana()
{
    delete ui;
}
/*******************************************************************************
* Function Name  ://数据统计功能开启
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void DiastatisticsMana::open_data_slots(void)
{
    qDebug()<<"open";
}
/*******************************************************************************
* Function Name  : //数据统计功能关闭
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
 void DiastatisticsMana::close_data_slots(void)
 {
      qDebug()<<"close";
 }
 /*******************************************************************************
 * Function Name  : //数据统计功能清除
 * Description    :
 * Input          :
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
  void DiastatisticsMana::clear_data_slots(void)
  {
  qDebug()<<"clear";

  }
