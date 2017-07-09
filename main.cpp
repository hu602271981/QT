#include "Real-time_Data.h"
#include <QApplication>
#include "can.h"
#include "golobe.h"
#include "sql.h"
#include <QFontDatabase>
#include "main.h"
#include "mythread.h"
#include "QApplication"
#include <unistd.h>
#include <QtCore>

#include "mainwindow.h"

#include <screensaver.h>
#include  <qglobal.h>
#include <zonghexinxixinshihuamian.h>

#include <application.h>
#include <qrect.h>
#include <qdebug.h>
#include <QDialog>
#include <QFile>
#include <QTextCodec>


//-----------------------全局变量初始化。b-------------------------------------------
sql* SQLmain()                          //历史数据库全局
{
    static sql golobewindow;
    return &golobewindow;
}
 can app;

 Dialog* REAL_TIME()                    //实时数据库全局
 {
     static Dialog golobewindow;
     return &golobewindow;
 }

 Store_information* Store_Information()               //存储信息
 {
     static Store_information golobewindow;
     return &golobewindow;
 }

 Substation* FZ_LOCAL()               //分站本机参数设定
 {
     static Substation golobewindow;
     return &golobewindow;
 }

 Substation2* GC_Set()               //关联传感器参数
 {
     static Substation2 golobewindow;
     return &golobewindow;
 }

 Dialog1* Communication_Test() //通信测试界面
 {
     static Dialog1 golobewindow;
     return &golobewindow;
 }
 Dialog2* Historical_data()   //历史数据显示画面
 {
     static Dialog2 golobewindow;
     return &golobewindow;
 }
 Dialog3* Data_Transmission() //数据发送显示画面
 {
     static Dialog3 golobewindow;
     return &golobewindow;
 }
 Dialogclear* Data_Delete()   //数据清除显示画面
 {
     static Dialogclear golobewindow;
     return &golobewindow;
 }
 DialogStatistics*  Data_Statistics()  //数据统计显示画面
 {
     static DialogStatistics golobewindow;
     return &golobewindow;
 }
 Dia1* Pressure_Hd()   //压力传感器历史数据画面
 {
     static Dia1 golobewindow;
     return &golobewindow;

 }
 Dia2* Displacement_Hd()  //位移传感器历史数据画面
 {
     static Dia2 golobewindow;
     return &golobewindow;

 }
realtime_presser* Realtime_presser()//顶板压力实时数据
{
    static realtime_presser golobewindow;
    return &golobewindow;

}

Processer_StoreInformation* Processer_Store_Information()  //顶板压力存储信息
{
    static Processer_StoreInformation golobewindow;
    return &golobewindow;
}
Diastatisticsmana1* WY_Statistics() //位移传感器数据统计画面头文件
{
    static Diastatisticsmana1 golobewindow;
    return &golobewindow;

}
Data_Management* Data_management() //数据管理
{
    static Data_Management golobewindow;
    return &golobewindow;

}
Diastatisticsmana2* PRESSURE_Statistics() //压力数据统计画面
{
    static Diastatisticsmana2 golobewindow;
    return &golobewindow;

}
Substation* Substation_local() //分站本机参数设定
{
    static Substation golobewindow;
    return &golobewindow;

}
ParameterSetting* Parameter_Setting() //参数设定
{
    static ParameterSetting golobewindow;
    return &golobewindow;

}
Storesinformation* Total_Store_Information()  //存储信息界面
{
    static Storesinformation golobewindow;
    return &golobewindow;

}
//Substation2* Sensor_Set()  //关联传感器参数设定
//{
//    static Substation2 golobewindow;
//    return &golobewindow;

//}
//zonghexinxixinshihuamian* Information()  //综合信息
//{
//    static zonghexinxixinshihuamian golobewindow;
//    return &golobewindow;

//}
//--------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    //系统配置
      //对时



    Application a(argc, argv);

    //--------------------------开发板支持中文。b--------------------------------------------------------
    // sql Data_sql;

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));  //设置开发板数据库显示中文
   int id = QFontDatabase::addApplicationFont("/opt/DroidSansFallback.ttf");
    QString msyh = QFontDatabase::applicationFontFamilies (id).at(0);
    QFont font(msyh,10);
    //   qDebug()<<msyh<<endl;
    //font.setFamily(QString::fromUtf8("/opt/DroidSansFallback.ttf"));
    font.setPointSize(16);
    a.setFont(font);


    //--------------------------------sql。b-------------------------------------------------------------------
    SQLmain()->connectSql("127.0.0.1","test1","JM","123456", SQLmain()->db_TEST); //dingban


    //位移实时数据库初始化
   SQLmain()->Init_RealTime_Date_SQL(SQLmain()->db_TEST,"insert into Displacement_Realtime values (?, ?)");
   //压力实时数据库初始化
   // Realtime_presser()->Init_Pressure_RealTime_Date_SQL(SQLmain()->db_TEST);

    //-------------------数据库备份---------------------------------------
//     QString UserName="JM";
//     QString PassWord="123456";
//     QString Serverip="127.0.0.1";
//     QString DataName="test";
//     QString BackPath="/opt/sqlbackup";

//        QString Cmd = QString("mysqldump -u%1 -p%2 -h%3 %4").arg(UserName,PassWord,Serverip,DataName);
//        QString Path = QString("%4/%5.Sql").arg(BackPath,QDateTime::currentDateTime().toString());
//        QProcess *poc=new QProcess;
//        poc->setStandardOutputFile(Path);
//        poc->start(Cmd);





    //----------------------数据库备份-------------------------------------




    MainWindow *Qman();
    Qman()->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    ScreenSaver b; //屏保
    a.setWindowInstence(&b);
    Qman()->showFullScreen();
    return a.exec();

}


//-----------------------多线程。b----------------------------
MyThread::MyThread()
{
}

void MyThread::run()
{
    system("ifconfig can0 down");
    system("/sbin/ip link set can0 type can bitrate 5000");
    system("ifconfig can0 up");
    app.CanInit();
    emit UpdateSignal();
    while(1)
       {

            app.Can_Rx(app.Can_Rx_Buffer);  //接收第一帧
            //判断收到的帧是否为对时
     NO_HISTORY:     //l连续两帧之后无历史数据跳转
             app.Can_Filter(Can_Id,1); //


            if ((Can_Rx_Save[0]==0xdd)&&(Can_Rx_Save[1]==0x16)&&(Can_Rx_Save[2]==0x01)&&(Can_Rx_Save[7]==0x00))
            {

 //---------------------------------------------------- 时间错误.b-------------------------------------------------------------------------------------------------------
                   memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                     //接收第二帧 当前数据 数据丢弃 不写入数据库
                   app.Can_Rx(app.Can_Rx_Buffer);

                   memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空

                   //发送对时信息
                   app.Set_Time(app.Can_Rx_Buffer.data);
                   struct can_frame Can_Tx_Buffer={CAN_EFF_FLAG |0x0,8,\
                                   {app.Can_Rx_Buffer.data[0],app.Can_Rx_Buffer.data[1],\
                                    app.Can_Rx_Buffer.data[2],app.Can_Rx_Buffer.data[3],\
                                    app.Can_Rx_Buffer.data[4],app.Can_Rx_Buffer.data[5],\
                                    app.Can_Rx_Buffer.data[6],app.Can_Rx_Buffer.data[7]}};
                   app.CanTx(Can_Tx_Buffer);

                   //接收历史数据 多帧
                    app.Can_Rx(app.Can_Rx_Buffer);
                    if(Can_Rx_Save[0]==0xaa)        //判断两帧之后是否有历史数据
                      {
                         //后续加写入数据库的函数
                         int shiwei=Can_Rx_Save[6],gewei=Can_Rx_Save[7];
                         int historydata=((Can_Rx_Save[6]*10)+Can_Rx_Save[7]);
                         memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                         //根据历史信息的长度确定接收的次数

                          for(int i=0;i<historydata;i++)
                          {
                                app.Can_Rx(app.Can_Rx_Buffer);
                               //数据处理
                                memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空

                                app.Can_Rx(app.Can_Rx_Buffer);
                               //数据处理
                                memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空

                          }
                          //返回成功接收
                          struct can_frame Can_Tx_Buffer={CAN_EFF_FLAG |0x01,8,{shiwei, gewei, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa}};
                          app.CanTx(Can_Tx_Buffer);
                          //关闭过滤器
                          //app.Can_Filter(Can_Id,0);
                          //清空
                          shiwei=0;
                          gewei=0;
                          historydata=0;
                     }
                    else      //对时之后无历史数据
                    {

                         goto NO_HISTORY;

                    }
            }

           else

//---------------------------------------------------- 若时间正确.b-------------------------------------------------------------------------------------------------------
            {
     //---------------------------------------------------- 实时数据库写入.b------------------------------------------------------------------------------
                app.Now_Data_FLAG=app.Can_Now_Time_Chuli(Can_Id, app.NOW.CAN_ID_CHAR,Can_Rx_Save,app.NOW.Can_Time);
               // qDebug()<<app.NOW.Can_Time;
                memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                 app.Can_Filter(Can_Id,1);
                     Can_Id=0;
                 //需清空id

                //接收第二帧 当前数据 需保存
                app.Can_Rx(app.Can_Rx_Buffer);
                if((Can_Rx_Save[2]==0x00)&&(Can_Rx_Save[3]==0x00)&&(Can_Rx_Save[4]==0x00)\
                     &&(Can_Rx_Save[5]==0x00)&&(Can_Rx_Save[6]==0x00)&&(Can_Rx_Save[7]==0x00))   //判断数据的有效性 有效写入数据库 无效则丢弃
                {
                    //数据无效
                         //判断   CAN_ID_CHAR[2]  传感器类型； 来选择写入不同的数据库
                    switch (app.NOW.CAN_ID_CHAR[2])
                    {
                    case 1:  //位移传感器
                                    mutex.lock();
                                   app.Can_Now_Data_Chuli(Can_Id, app.NOW.CAN_ID_CHAR,Can_Rx_Save,app.NOW.Data);
                                  //  qDebug()<<app.NOW.CAN_ID_CHAR[3]<<app.NOW.Data[0]<<app.NOW.Data[1];
                                    SQLmain()->Update_Date(app.NOW, SQLmain()->db_TEST,\
                                   "UPDATE  Displacement_Realtime SET qianji=:qianji,shenji=:shenji,time=:time WHERE cgq_id=:id",\
                                   "UPDATE  Displacement_Realtime SET qianji=:qianji,shenji=:shenji,time=:time WHERE cgq_id=:id");
                                     mutex.unlock();
                        break;
                    default:
                        break;
                    }

                   emit UpdateSignal();
                }
                else  //数据有效写入数据库
                {
                 if(app.Now_Data_FLAG==1)
                 {
                    app.Now_Data_FLAG==0;  //释放标志位
                     app.Can_Now_Data_Chuli(Can_Id, app.NOW.CAN_ID_CHAR,Can_Rx_Save,app.NOW.Data);
                     // qDebug()<<app.NOW.Can_Time;
                     //写入历史数据库 realtime1
                   //  SQLmain()->Add_Date(app.NOW, SQLmain()->db_TEST,"insert into Displacement_History values (?, ?,?,?, ?,?,?)");

                     //写入位移实时数据库 Displacement_Realtime
                     switch (app.NOW.CAN_ID_CHAR[2])
                     {
                     case 1:  //位移传感器
                                     mutex.lock();
                                     SQLmain()->Update_Date(app.NOW, SQLmain()->db_TEST,\
                                    "UPDATE  Displacement_Realtime SET qianji=:qianji,shenji=:shenji,time=:time WHERE cgq_id=:id",\
                                    "UPDATE  Displacement_Realtime SET qianji=:qianji,shenji=:shenji,time=:time WHERE cgq_id=:id");
                                      mutex.unlock();
                         break;
                     default:
                         break;
                     }

                     emit UpdateSignal();

                 }
                  else
                 {
                      ;  //当前信息时间帧不对，无法写入数据库
                 }
                }
                memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                  Can_Id=0;
    //---------------------------------------------------- 实时数据库写入.e------------------------------------------------------------------------------

  //---------------------------------------------------- 写入历史数据库.b-------------------------------------------------------------------------------
                 app.Can_Rx(app.Can_Rx_Buffer);                        //历史数据的长度
                 if(Can_Rx_Save[0]==0xaa)
                   {
                      //后续加写入数据库的函数
                      int shiwei=Can_Rx_Save[6],gewei=Can_Rx_Save[7];
                      int historydata=((Can_Rx_Save[6]*10)+Can_Rx_Save[7]);
                      memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                      //根据历史信息的长度确定接收的次数

                       for(int i=0;i<historydata;i++)
                       {
                              app.Can_Rx(app.Can_Rx_Buffer);     //历史数据的时间帧
                          if ((Can_Rx_Save[0]==0xdd)&&(Can_Rx_Save[1]==0x16)&&(Can_Rx_Save[2]==0x01)&&(Can_Rx_Save[7]==0x00))
                          {
                                 //历史数据时间不对
                                   app.Can_Rx(app.Can_Rx_Buffer);
                          }
                          else       //历史数据时间正确
                          {
                              //写入历史数据的时间信息

                                 app.Now_Data_FLAG=app.Can_Now_Time_Chuli(Can_Id,  app.ID_CHAR_DATE,Can_Rx_Save,app.NOW.Can_Time);
                                  memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                                   Can_Id=0;

                              app.Can_Rx(app.Can_Rx_Buffer);                //历史数据的数据帧
                             //数据处理
                              if((Can_Rx_Save[2]==0x00)&&(Can_Rx_Save[3]==0x00)&&(Can_Rx_Save[4]==0x00)\
                                   &&(Can_Rx_Save[5]==0x00)&&(Can_Rx_Save[6]==0x00)&&(Can_Rx_Save[7]==0x00))   //判断数据的有效性 有效写入数据库 无效则丢弃
                              { ;  }    //数据无效不写入数据库
                              else  //数据有效写入数据库
                              {
                                       //加入新的协议 之后写入数据库   对id 进行处理
                                  if(app.Now_Data_FLAG==1)
                                  {
                                      app.Now_Data_FLAG==0;  //释放标志位
                                      app.Can_Now_Data_Chuli(Can_Id, app.ID_CHAR_DATE,Can_Rx_Save,app.NOW.Data);
                                    //写入数据库
                                      switch (app.NOW.CAN_ID_CHAR[2])
                                      {
                                      case 1:    //位移传感器历史数据
                                            mutex.lock();
                                             SQLmain()->Add_Date(app.NOW, SQLmain()->db_TEST,"insert into Displacement_History values (?, ?,?,?, ?,?,?)");

                                            mutex.unlock();
                                             //qDebug()<<"222";
                                          break;
                                      case 2:  //支柱压力传感器历史数据

                                          break;
                                      default:
                                          break;
                                      }
                                   //   emit UpdateSignal(1);

                                  }
                                   else   //当前信息时间帧不对，无法写入数据库
                                  { ;  }

                              }
                                    memset(Can_Rx_Save,0,8*sizeof(unsigned char));  //清空
                                    Can_Id=0;
                          }

                       }
                        emit UpdateSignal();
                       //返回成功接收
                       struct can_frame Can_Tx_Buffer={CAN_EFF_FLAG |0x01,8,{shiwei, gewei, 0x00, 0x00, 0x00, 0x00, 0x00, 0xaa}};
                       app.CanTx(Can_Tx_Buffer);
                       //关闭过滤
                       //app.Can_Filter(Can_Id,0);
                       //清空
                       shiwei=0;
                       gewei=0;
                       historydata=0;
                    }
//---------------------------------------------------- 写入历史数据库.e-------------------------------------------------------------------------------
                 //若第二帧之后的无历史数据
                 else
                 {
                     goto NO_HISTORY;

                 }
             }
       }


}





























