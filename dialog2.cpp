#include "dialog2.h"
#include "ui_dialog2.h"
#include "main.h"
#include "QKeyEvent"
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    ui->yalihisButton->setCheckable (false );
     ui->weiyihisButton->setCheckable (false );


    QObject::connect(ui->yalihisButton,SIGNAL(clicked()),this,SLOT(diaSlot()));
    QObject::connect(ui->weiyihisButton,SIGNAL(clicked()),this,SLOT(dia2Slot()));
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Dialog2::~Dialog2()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 压力传感器历史数据画面
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void Dialog2::diaSlot()
{
   // Dia1 *c =new Dia1();
   // Dialog2 *d= new Dialog2();
      this->hide();
    //  Presser_history()->showFullScreen();
      //Presser_history()->exec();
    Pressure_Hd()->showFullScreen();
     Pressure_Hd()->exec();


}
/*******************************************************************************
* Function Name  : 位移传感器历史数据画面
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void Dialog2::dia2Slot()
{
   // Dia2 *cc = new Dia2(); //位移传感器类
    //Dialog2 *dd =new Dialog2();  //历史数据类


    this->hide();
    SQLmain()->showFullScreen();
    SQLmain()->exec();
    //SQLmain()->hide();

  //  cc->show();
   // cc->exec();
  //  dd->show();
   // dd->exec();
   //  this->show();
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialog2::keyPressEvent(QKeyEvent *event)
{
   Data_Management *kk =new Data_Management();

    switch(event->key()) {
    case Qt::Key_F1:                       //左键
         //information();
        break;
    case Qt::Key_Escape:                  //右键
                  Historical_data()->hide();
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
