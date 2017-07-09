#include "dialog1.h"
#include "ui_dialog1.h"
#include "QKeyEvent"
#include "Data_Management.h"
#include "main.h"
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->pushButton_4->setCheckable (false );
    QObject::connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(Dataslot1()));//向传感器发送一帧时间信息
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Dataslot2())); //清楚传感器历史数据指令
    QObject::connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Dataslot3()));  //发送传感器数据清零测试指令
    QObject::connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(Dataslot4())); //向上层设备发送分站本机参数信息
    QObject::connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(Dataslot5())); //向上层设备发送本机关联传感器参数信息

}

Dialog1::~Dialog1()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : //向传感器发送一帧时间信息
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog1::Dataslot1()
{
qDebug()<<"1";
}
/*******************************************************************************
* Function Name  : //清楚传感器历史数据指令
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog1::Dataslot2()
{
    qDebug()<<"2";
}
/*******************************************************************************
* Function Name  ://发送传感器数据清零测试指令
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog1::Dataslot3()
{
     qDebug()<<"3";
}
/*******************************************************************************
* Function Name  ://向上层设备发送分站本机参数信息
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog1::Dataslot4()
{
     qDebug()<<"4";
}
/*******************************************************************************
* Function Name  : //向上层设备发送本机关联传感器参数信息
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog1::Dataslot5()
{
      qDebug()<<"5";
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog1::keyPressEvent(QKeyEvent *event)
{
     Data_Management *kk =new Data_Management();

    switch(event->key()) {
    case Qt::Key_F1:                       //左键
         //information();
        break;
    case Qt::Key_Escape:                  //右键
                    Communication_Test()->hide();
                    kk->show();
                    kk->exec();
        break;
    case Qt:: Key_Left:
         //front()->hide();
             ;
        break;
    case Qt::Key_Up:                  //右键
         //front()->hide();
             ;
        break;
    case Qt::Key_Right:                  //右键
         //front()->hide();
             ;
        break;
    case Qt::Key_Down:                  //右键
         //front()->hide();
             ;
        break;
    default:
   //    fullscreenwindow::keyPressEvent(event);
        break;
    }
}
