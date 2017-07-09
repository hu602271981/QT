#include "zonghexinxixinshihuamian.h"
#include "ui_zonghexinxixinshihuamian.h"
#include"realtimedata.h"
#include "QKeyEvent"
#include "golobe.h"
#include <QNetworkInterface>
#include <QDateTime>
#include "main.h"
zonghexinxixinshihuamian::zonghexinxixinshihuamian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zonghexinxixinshihuamian)
{
          ui->setupUi(this);
         QDateTime  time = QDateTime::currentDateTime();//获取系统现在的时间
          QString str =  time.toString("yyyy-MM-dd hh:mm:ss ");
           QString str2 = time.toString("dddd");
            ui->timeLabel1->setText(str);
            ui->timeLabel2->setText(str);
         if( QString::compare(str2,"Monday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期一"));
               ui->week2->setText(QObject::trUtf8("星期一"));
         }
         if( QString::compare(str2,"Tuesday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期二"));
                 ui->week2->setText(QObject::trUtf8("星期二"));
         }
         if( QString::compare(str2,"Wednesday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期三"));
                 ui->week2->setText(QObject::trUtf8("星期三"));
         }
         if( QString::compare(str2,"Thursday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期四"));
               ui->week2->setText(QObject::trUtf8("星期四"));
         }
         if( QString::compare(str2,"Friday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期五"));
                ui->week2->setText(QObject::trUtf8("星期五"));
         }
         if( QString::compare(str2,"Saturday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期六"));
                ui->week2->setText(QObject::trUtf8("星期六"));
         }
         if( QString::compare(str2,"Sunday")==0)
         {
              ui->week1->setText(QObject::trUtf8("星期日"));
               ui->week2->setText(QObject::trUtf8("星期日"));
         }
//界面显示初始化
     //   Information_show(SQLmain()->db_TEST);
     //    UPDATE_wy_Number(SQLmain()->db_TEST);
     //  ui->ON_LINE_displacement_sensor->setText("0");
   //    ui->OFF_LINE_displacement_sensor->setText("20");
}

zonghexinxixinshihuamian::~zonghexinxixinshihuamian()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : //显示本页面数据
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int zonghexinxixinshihuamian:: Information_show(QSqlDatabase db)
{
   //-------------------------分站本机参数设定提取信息------------------------------------------------------------

    QString cmd2="select * from Substation_Set;";
    QSqlQuery q2(cmd2,db);

     while(q2.next())
     {

           //分站编号
         ui->Station_Number->setText(q2.value(0).toString());
          //安装地点
         ui->LOCATION->setText(QObject::trUtf8(q2.value(2).toString().toStdString().data()));
         //第一路CAN
          ui->CAN1->setText(QObject::trUtf8(q2.value(5).toString().toStdString().data()));
         //第二路CAN
            ui->CAN2->setText(QObject::trUtf8(q2.value(6).toString().toStdString().data()));
            ui->CAN2_RATE->setText(QObject::trUtf8(q2.value(7).toString().toStdString().data()));
            //以太网接口及相关信息
          ui->Internet->setText(QObject::trUtf8(q2.value(9).toString().toStdString().data()));
            //无线网接口
           ui->wireless->setText(QObject::trUtf8(q2.value(8).toString().toStdString().data()));
           //网络信息
          ui->LOCAL_IP->setText(QObject::trUtf8(q2.value(10).toString().toStdString().data()));
          ui->LOCAL_MASK->setText(QObject::trUtf8(q2.value(11).toString().toStdString().data()));
          ui->LOCAL_gateway->setText(QObject::trUtf8(q2.value(12).toString().toStdString().data()));

            //传感器信息
    }

//-------------------------关联传感器信息提取------------------------------------------------------------
     QString cmd="select * from Sensor_Set;";
     QSqlQuery q(cmd,db);

      while(q.next())
      {
        ui->TOTAL_sensor->setText(q.value(0).toString());



     }
}
/*******************************************************************************
* Function Name  :
* Description    : //更新在线台数
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

int zonghexinxixinshihuamian:: UPDATE_wy_Number(QSqlDatabase db)
{
     QString data="OFF LINE";
      int ON_LINE_NUMBER;
      int dd;
     QString ON_LINE_NUMBERnew;
   // for(int i=1;i<=20;i++)
 //   {
        QString cmd4 ="use test;";
        QString cmd5=QString("select count(1) from  Displacement_Realtime where shenji='%1';").arg(data);
         QSqlQuery  q4(cmd4,db);
         QSqlQuery  q5(cmd5,db);
         while (q5.next()) {
           //      qDebug() << "table name:" << q5.value(0).toString();
                 ON_LINE_NUMBER=q5.value(0).toInt();
         }
                   q5.exec();
  //  }

 // qDebug() << "table name:" << ON_LINE_NUMBER ;
 // dd=20-ON_LINE_NUMBER;

   // QString string;
   ON_LINE_NUMBERnew=QString::number(20-ON_LINE_NUMBER);
   ui->ON_LINE_displacement_sensor->setText(ON_LINE_NUMBERnew);
   ui->OFF_LINE_displacement_sensor->setText(QString::number(ON_LINE_NUMBER));


}


/*******************************************************************************
* Function Name  : 更新数据库
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int  zonghexinxixinshihuamian:: Information_UPdate(void) //综合信息更新
{


   front()->Information_show(SQLmain()->db_TEST);

    front()->UPDATE_wy_Number(SQLmain()->db_TEST);


}
/*******************************************************************************
* Function Name  : 键盘事件
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void zonghexinxixinshihuamian::keyPressEvent(QKeyEvent *event)
{

    switch(event->key()) {
    case Qt::Key_Return:                       //左键
           Real_time_Date();
        break;
    case Qt::Key_Escape:                       //左键
        //front()->showFullScreen();
      //  front()->exec();
          front()->hide();

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
       zonghexinxixinshihuamian::keyPressEvent(event);
        break;
    }
}
/*******************************************************************************
* Function Name  : 由综合信息调到实时信息
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void zonghexinxixinshihuamian::Real_time_Date()
{
     front()->close();
     REAL_TIME()->showFullScreen();
     REAL_TIME()->exec();

}
/*******************************************************************************
* Function Name  : 更新数据库
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void zonghexinxixinshihuamian::CloseWindows()
  {
     // Dialog_RealtimeDate w;
      //w.showFullScreen();
      //w.exec();
      //w.hide();
       zonghexinxixinshihuamian w;
       w.hide();
  }



