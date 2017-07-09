#include "Data_Management.h"
#include "ui_Data_Management.h"
#include <QPushButton>
#include "main.h"
#include "golobe.h"
#include "QKeyEvent"
Data_Management::Data_Management(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
       ui->communicationButton->setCheckable (false );
       ui->historyButton->setCheckable (false );
       ui->dataTransmassionButton->setCheckable (false );
       ui->dataClearButton->setCheckable (false );
      ui->dataStatixticsButton->setCheckable (false );


    QObject::connect(ui->communicationButton,SIGNAL(clicked()),this,SLOT(dialog1slot()));  //通信测试
    QObject::connect(ui->historyButton,SIGNAL(clicked()),this,SLOT(dialog2slot())); //历史数据
    QObject::connect(ui->dataTransmassionButton,SIGNAL(clicked()),this,SLOT(dialog3slot())); // 数据发送
    QObject::connect(ui->dataClearButton,SIGNAL(clicked()),this,SLOT(dialog4slot())); //数据清除
    QObject::connect(ui->dataStatixticsButton,SIGNAL(clicked()),this,SLOT(dialog5slot())); //数据统计
    this->setWindowFlags(Qt::FramelessWindowHint);

}

Data_Management::~Data_Management()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 通信测试
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void Data_Management::dialog1slot()
{
   // Dialog1 *k = new Dialog1();
  //  Data_Management *kk =new Data_Management();
       Data_management()->hide();
        Communication_Test()->showFullScreen();
          Communication_Test()->exec();
   // k->exec();
  //  kk->show();
  //  kk->hide();
     //  this->show();

}
/*******************************************************************************
* Function Name  : 历史数据
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void Data_Management::dialog2slot()
{
    //Dialog2 *l = new  Dialog2();
    //Data_Management *kk =new Data_Management();
     Data_management()->hide();
     Historical_data()->showFullScreen();
      Historical_data()->exec();
    //l->show();
  //  l->exec();

  //  kk->show();
 //   kk->hide();
   // this->show();
}
/*******************************************************************************
* Function Name  : 数据发送
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void Data_Management::dialog3slot()
{
   // Data_Management *kk =new Data_Management();
   // Dialog3 *m = new Dialog3();
    Data_management()->hide();
    Data_Transmission()->showFullScreen();
    Data_Transmission()->exec();
  //  m->show();
   // m->exec();
  //  kk->show();
   // kk->hide();
  //  this->show();
}
/*******************************************************************************
* Function Name  : 数据清除
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void Data_Management::dialog4slot()
{
   // Dialogclear *n =new Dialogclear();
    //Data_Management *kk =new Data_Management();
     Data_management()->hide();
    Data_Delete()->showFullScreen();
    Data_Delete()->exec();

}
/*******************************************************************************
* Function Name  : 数据统计
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void Data_Management::dialog5slot()
{
    //DialogStatistics *o =new DialogStatistics();
   // Data_Management *kk =new Data_Management();
   // Data_management()->hide();
    Data_management()->close();
     Data_Statistics()->showFullScreen();
     Data_Statistics()->exec();

  //  kk->hide();
  //  this->show();
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Data_Management::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()) {
    case Qt::Key_F1:                       //左键
      //   information();
        break;
    case Qt::Key_Escape:                  //右键
          //Data_management()->hide();
         Data_management()->close();
          Qman()->showFullScreen();


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
     //  fullscreenwindow::keyPressEvent(event);
        break;
    }
}
