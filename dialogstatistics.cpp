#include "dialogstatistics.h"
#include "ui_dialogstatistics.h"
#include "QKeyEvent"
#include "main.h"

DialogStatistics::DialogStatistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStatistics)
{
    ui->setupUi(this);
    QObject::connect(ui->dataManaButton,SIGNAL(clicked()),this,SLOT(DiastatisticsManaSlot()));
    QObject::connect(ui->weiyiCButton,SIGNAL(clicked()),this,SLOT(Diastatisticsmana1Slot()));
    QObject::connect(ui->yaliCButton,SIGNAL(clicked()),this,SLOT(Diastatisticsmana2Slot()));
    this->setWindowFlags(Qt::FramelessWindowHint);

}

DialogStatistics::~DialogStatistics()
{
    delete ui;
}
void DialogStatistics::DiastatisticsManaSlot()
{
    DiastatisticsMana *e = new DiastatisticsMana();
    DialogStatistics *f = new DialogStatistics();
    this->hide();
    e->show();
    e->exec();
    f->show();
    f->exec();
    this->show();
}
/*******************************************************************************
* Function Name  : 位移传感器数据统计界面
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void DialogStatistics::Diastatisticsmana1Slot()
{
   // Diastatisticsmana1 *ii =new Diastatisticsmana1();
   // DialogStatistics *jj = new DialogStatistics();
   // Data_Statistics()->hide();
    Data_Statistics()->close();
    WY_Statistics()->showFullScreen();
     WY_Statistics()->exec();
   //  this->showFullScreen();
    // this->exec();
}
/*******************************************************************************
* Function Name  : 压力传感器数据统计界面
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void DialogStatistics::Diastatisticsmana2Slot()
{

      Data_Statistics()->hide();
       PRESSURE_Statistics()->showFullScreen();
      PRESSURE_Statistics()->exec();


}

/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void DialogStatistics::keyPressEvent(QKeyEvent *event)
{

     //this->hide();


    switch(event->key()) {
    case Qt::Key_F1:                       //左键
         //information();
        break;
    case Qt::Key_Escape:                  //右键
                 Data_Statistics()->hide();
                Data_management()->showFullScreen();
                   Data_management()->exec();
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
