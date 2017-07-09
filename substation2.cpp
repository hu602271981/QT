//----------------关联传感器参数设定
#include "substation2.h"
#include "ui_substation2.h"
#include <QString>
#include <QLineEdit>
#include <QValidator>
#include "QKeyEvent"
#include "parametersetting.h"
#include "main.h"
Substation2::Substation2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Substation2)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    //分站关联传感器总数
    ui->sensor_total_Number_SHI->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    ui->sensor_total_Number_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
   //位移传感器
    ui->displacement_Number_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器\

   //压力传感器数量
    ui->pressure_Number_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    ui->pressure_Number_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    //位移传感器存储容量
    ui->displacement_Store_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->displacement_Store_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
   //超限警示值
     ui->displacement_Store_UP_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->displacement_Store_UP_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
   //位移传感器总离层报警值
     ui->displacement_Tolat_Separation_bai->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->displacement_Tolat_Separation_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->displacement_Tolat_Separation_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
   //位移传感器离层变化率报警值
     ui->displacement_Separation_Rate_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->displacement_Separation_Rate_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
    //压力传感器存储容量
     ui->pressure_Store_ge->installEventFilter(this);
     ui->pressure_Store_zero->installEventFilter(this);
    //超限报警值
      ui->pressure_Store_UP->installEventFilter(this);
       ui->displacement_Number_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器

  //qDebug()<<ui->sensor_total_Number_SHI->currentText().toInt()*10+ui->sensor_total_Number_ge->currentText().toInt();

}

Substation2::~Substation2()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Substation2::keyPressEvent(QKeyEvent *event)
{
      ParameterSetting *window1=new ParameterSetting();  //参数设定主界面

     switch(event->key()) {
    case Qt::Key_F1:                       //左键
        // information();
        break;
    case Qt::Key_Escape:                  //右键
          //  h->hide();
         GC_Set()->Correlation_sensor_Save_sql();
           GC_Set()->close();
           window1->showFullScreen();
            window1->exec();
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
/*******************************************************************************
* Function Name  : //界面显示
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
int Substation2::Correlation_sensor_UI_SHOW(void)
{


}
/*******************************************************************************
* Function Name  : //分站本机参数更新
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
 void Substation2::Correlation_sensor_UPdate(void)
 {




 }
 /*******************************************************************************
 * Function Name  : //对话框判断是否写入数据库
 * Description    :
 * Input          :
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
 void Substation2::Correlation_sensor_Save_sql(void)
 {

     QMessageBox message(QMessageBox::Warning,"Information","Really to save setting?",QMessageBox::Yes|QMessageBox::No,NULL);
     if (message.exec()==QMessageBox::Yes)
     { //写书数据库
           //emit Update_Signal(1);
           qDebug()<<"clicked yes\n";
           GC_Set()->Correlation_sensor_Save_Date(SQLmain()->db_TEST,"Really to save setting?");
     }
     else
     { //不写入数据库
         qDebug()<<"clicked no\n";
     }


 }
 /*******************************************************************************
 * Function Name  :  //写入数据库
 * Description    :                a[0] 分站关联传感器总数 a[1] 位移传感器数量 a[2]压力传感器数量
 *                                          a[3]  位移传感器存储容量a[4]  位移传感器存储容量超限警示值
 *                                          a[5]  位移传感器总离层报警值  a[6] 离层变化率报警值
 * Input          :
 *                                            b[0]  压力传感器存储容量 b[1]   压力传感器存储容量超限值
 * Return         : None.
 *******************************************************************************/
 int Substation2::Correlation_sensor_Save_Date(QSqlDatabase db,QString Which_Table)
 {
     //--------------------------------------------------------------------------------------------------------

         int a[8],temp[5]; //用来存放界面输入的值
         QString String_temp[5];
         QString b[2];
       // a[0] 分站关联传感器总数

          a[0]=(ui->sensor_total_Number_SHI->currentText().toInt())*10+ui->sensor_total_Number_ge->currentText().toInt();

              // a[1] 位移传感器数量
          a[1]=(ui->displacement_Number_shi->currentText().toInt())*10+ui->displacement_Number_ge->currentText().toInt();

          // a[2]压力传感器数量
           a[2]=(ui->pressure_Number_shi->currentText().toInt())*10+ui->pressure_Number_ge->currentText().toInt();

           //  a[3]  位移传感器存储容量
            a[3]=(ui->displacement_Store_shi->currentText().toInt())*10+ui->displacement_Store_ge->currentText().toInt();

            //  a[4]  位移传感器存储容量超限警示值
           a[4]=(ui->displacement_Store_UP_shi->currentText().toInt())*10+ui->displacement_Store_UP_ge->currentText().toInt();

           // a[5]  位移传感器总离层报警值
              a[5]=(ui->displacement_Tolat_Separation_bai->currentText().toInt())*100+\
                   (ui->displacement_Tolat_Separation_shi->currentText().toInt())*10+\
                      ui->displacement_Tolat_Separation_ge->currentText().toInt();

              //a[6] 离层变化率报警值
                a[6]=(ui->displacement_Separation_Rate_shi->currentText().toInt())*10+\
                         ui->displacement_Separation_Rate_ge->currentText().toInt();

                //     a[7]  压力传感器存储容量

              temp[1]=ui->pressure_Store_ge->currentText().toInt();
              temp[2]=ui->pressure_Store_zero->currentText().toInt();
              String_temp[1]=QString::number(temp[1]);
              String_temp[2]=QString::number(temp[2]);
              b[0]=String_temp[1]+"."+ String_temp[2];
                //a[8]   压力传感器存储容量超限值

              b[1]=ui->pressure_Store_UP->currentText();
           qDebug()<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<a[6]<<b[0]<<b[1];
//-----------------------------------------------------------------------------------------------------------------

       //   QString cmd8="use test";

        QString cmd2=QString("update Sensor_Set set sensor_total_Number= '%1',displacement_Number='%2' ,\
                                        pressure_Number='%3',displacement_Store='%4',displacement_Store_UP='%5'\
                ,displacement_Tolat_Separation='%6',displacement_Separation_Rate='%7'\
                ,pressure_Store='%8',pressure_Store_UP='%9';") \
                 .arg(a[0]).arg(a[1]).arg(a[2]).arg(a[3]).arg(a[4]).arg(a[5]).arg(a[6]).arg(b[0]).arg(b[1]);
         //       QSqlQuery  q8(cmd8,db);
                QSqlQuery  q2(cmd2,db);


 }

 /*******************************************************************************
 * Function Name  : 键盘控制
 * Description    : 键盘
 * Input          :
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
bool Substation2:: eventFilter(QObject *watched, QEvent*event)
{
//    if(watched == ui->FenZhan_NUMBER_shi || watched == ui->FenZhan_NUMBER_ge|| watched == ui->FenZhan_type_shi||\
//            watched == ui->FenZhan_type_ge || watched == ui->location\
//      || watched == ui->CAN1|| watched == ui->CAN2|| watched == ui->CAN2_rate   \
//        || watched == ui->Wireless|| watched == ui->Ethernet)//确认可控的控件
//      {
          //   qDebug()<<"12";
         if(event->type() == QEvent::KeyPress)//如果检测到按键
           {

                bool  f1 =ui->sensor_total_Number_SHI->hasFocus();
                bool  f2 =ui->sensor_total_Number_ge->hasFocus();

                bool  f3 =ui->displacement_Number_shi->hasFocus();
                bool  f4 =ui->displacement_Number_ge->hasFocus();

                bool  f5=ui->pressure_Number_shi->hasFocus();
                bool  f6=ui->pressure_Number_ge->hasFocus();

                bool  f7 =ui->displacement_Store_shi->hasFocus();
                bool  f8 = ui->displacement_Store_ge->hasFocus();


                bool  f9 =ui->displacement_Store_UP_shi->hasFocus();        //分站类型
                bool  f10 =ui->displacement_Store_UP_ge->hasFocus();  //分站编号

                bool  f11 =ui->displacement_Tolat_Separation_bai->hasFocus(); //安装位置
                bool  f12 =ui->displacement_Tolat_Separation_shi->hasFocus();
                bool  f13=ui->displacement_Tolat_Separation_ge->hasFocus();

                bool  f14=ui->displacement_Separation_Rate_shi->hasFocus();
                bool  f15 =ui->displacement_Separation_Rate_ge->hasFocus();

                bool  f16 =ui->pressure_Store_ge->hasFocus();
                bool  f17 =ui->pressure_Store_zero->hasFocus(); //安装位置

                bool  f18 =ui->pressure_Store_UP->hasFocus();  //分站编号
             QKeyEvent *key_event = static_cast<QKeyEvent *>(event); //将事件转化为键盘事件

             if(key_event->key() == Qt::Key_Right)//右键
               {
                   if(f1)//焦点在分站类型
                  {
                     focusNextChild();//焦点移动
                     ui->sensor_total_Number_ge->setFocus();//移动到分站编号
                  }
                   if(f2)
                 {
                     focusNextChild();
                    ui->displacement_Number_shi->setFocus();
                  }
                   if(f3)
                  {
                     focusNextChild();
                   ui->displacement_Number_ge->setFocus();
                  }
                   if(f4)
                  {
                    // qDebug()<<"122";
                     focusNextChild();//焦点移动
                     // ui->CAN1->setFocus();//移动到分站编号
                    ui->pressure_Number_shi->setFocus();//移动到分站编号
                  }
                   if(f5)//焦点在分站类型
                  {
                     focusNextChild();//焦点移动
                     ui->pressure_Number_ge->setFocus();//移动到分站编号
                  }
                   if(f6)
                 {
                     focusNextChild();
                  ui->displacement_Store_shi->setFocus();
                  }
                   if(f7)
                  {
                     focusNextChild();
                  ui->displacement_Store_ge->setFocus();
                  }
                   if(f8)
                 {
                     focusNextChild();
                  ui->displacement_Store_UP_shi->setFocus();
                  }
                   if(f9)
                  {
                     focusNextChild();
                    ui->displacement_Store_UP_ge->setFocus();
                  }
                   if(f10)//焦点在分站类型
                  {

                     focusNextChild();//焦点移动
                     ui->displacement_Tolat_Separation_bai->setFocus();//移动到分站编号
                  }
                   if(f11)
                 {
                     focusNextChild();
                    ui->displacement_Tolat_Separation_shi->setFocus();
                  }
                   if(f12)
                  {
                     focusNextChild();
                   ui->displacement_Tolat_Separation_ge->setFocus();
                  }
                   if(f13)
                  {
                   //  qDebug()<<"122";
                     focusNextChild();//焦点移动
                     // ui->CAN1->setFocus();//移动到分站编号
                    ui->displacement_Separation_Rate_shi->setFocus();//移动到分站编号
                  }
                   if(f14)//焦点在分站类型
                  {
                     focusNextChild();//焦点移动
                     ui->displacement_Separation_Rate_ge->setFocus();//移动到分站编号
                  }
                   if(f15)
                 {
                     focusNextChild();
                  ui->pressure_Store_ge->setFocus();
                  }
                   if(f16)
                  {
                     focusNextChild();
                  ui->pressure_Store_zero->setFocus();
                  }
                   if(f17)
                 {
                     focusNextChild();
                  ui->pressure_Store_UP->setFocus();
                  }



               }
               if(key_event->key() == Qt::Key_Left)
               {
                   if(f18)
                  {
                     focusNextChild();
                  ui->pressure_Store_zero->setFocus();
                  }
                   if(f17)
                  {
                     focusNextChild();
                  ui->pressure_Store_ge->setFocus();
                  }
                   if(f16)
                  {
                     focusNextChild();
                  ui->displacement_Separation_Rate_ge->setFocus();
                  }
                   if(f15)
                  {
                     focusNextChild();
                  ui->displacement_Separation_Rate_shi->setFocus();
                  }

                   if(f14)
                  {
                     focusNextChild();
                  ui->displacement_Tolat_Separation_ge->setFocus();
                  }
                   if(f13)
                  {
                    focusNextChild();
                  ui->displacement_Tolat_Separation_shi->setFocus();
                  }

                   if(f12)
                  {
                       qDebug()<<"1212";
                     focusNextChild();
                  ui->displacement_Tolat_Separation_bai->setFocus();
                  }
                   if(f11)
                  {
                    focusNextChild();
                  ui->displacement_Store_UP_ge->setFocus();
                  }
                   if(f10)
                  {
                     focusNextChild();
                   ui->displacement_Store_UP_shi->setFocus();
                  }
                   if(f9)
                  {
                     focusNextChild();
                  ui->displacement_Store_ge->setFocus();
                  }
                   if(f8)
                  {
                     focusNextChild();
                  ui->displacement_Store_shi->setFocus();
                  }
                   if(f7)
                  {
                     focusNextChild();
                  ui->pressure_Number_ge->setFocus();
                  }

                   if(f6)
                  {
                     focusNextChild();
                  ui->pressure_Number_shi->setFocus();
                  }
                   if(f5)
                  {
                    focusNextChild();
                  ui->displacement_Number_ge->setFocus();
                  }

                   if(f4)
                  {
                       qDebug()<<"1212";
                     focusNextChild();
                  ui->displacement_Number_shi->setFocus();
                  }
                   if(f3)
                  {
                    focusNextChild();
                  ui->sensor_total_Number_ge->setFocus();
                  }
                   if(f2)
                  {
                     focusNextChild();
                   ui->sensor_total_Number_SHI->setFocus();
                  }
               }

         }

 // }
  return QWidget::eventFilter(watched,event);     //最后将事件交给上层对话框




}
