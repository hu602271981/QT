#include "dialog3.h"
#include "ui_dialog3.h"
#include "QKeyEvent"
#include "main.h"

Dialog3::Dialog3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog3)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
     ui->pushButton1->setCheckable (false );
      ui->pushButton_2->setCheckable (false );
      ui->pushButton_3->setCheckable (false );

    QObject::connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(Dataslot1()));//发送分站保存的位移传感器数据
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(Dataslot2())); //发送分站保存的压力传感器数据
    QObject::connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(Dataslot3()));  //发送分站保存的传感器数据


}

Dialog3::~Dialog3()
{
    delete ui;
}
/*******************************************************************************
* Function Name  :  //发送分站保存的位移传感器数据
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog3:: Dataslot1()
{
     qDebug()<<"1";
}
/*******************************************************************************
* Function Name  :  //发送分站保存的压力传感器数据
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog3::Dataslot2()
{
    qDebug()<<"2";
}
/*******************************************************************************
* Function Name  : //发送分站保存的传感器数据
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog3::Dataslot3()
{
    qDebug()<<"3";

}


/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog3::keyPressEvent(QKeyEvent *event)
{

   Data_Management *kk =new Data_Management();


    switch(event->key()) {
    case Qt::Key_F1:                       //左键
         //information();
        break;
    case Qt::Key_Escape:                  //右键
        Data_Transmission()->hide();
        kk->showFullScreen();
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
