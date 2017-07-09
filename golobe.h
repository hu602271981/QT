#ifndef GOLOBE_H
#define GOLOBE_H
#include <QApplication>
#include <QDialog>
#include <zonghexinxixinshihuamian.h>
#include <realtimedata.h>
#include <mainwindow.h>

MainWindow* Qman();  //主界面
zonghexinxixinshihuamian *front(); //综合信息界面
Realtimedata *RealTimeDate_front(); //实时数据界面
extern int timeflag;
extern unsigned char Can_Rx_Save[8]; //用来暂时保存can总线接收的数据
extern unsigned int Can_Id; //保存canid
struct CAN_NET_DATA
  {
      //unsigned char FZ_Type;
      //unsigned char FZ_Id;
      //unsigned char CGQ_Type;
      //unsigned char CGQ_Id;
      unsigned int CAN_ID_CHAR[10];
     QString Can_Time;
     QString  Data[10];            //用来存放数据
 };
//----------------------------------------------用于存放在 SHOW_WY_HIS的数据----------------------------------------------------------
struct SHOW_WY_HIS
{
     int id[255];
     int ITEM1[255];
     int ITEM2[255];
     int reduce[255];
    float Calculation1[255];
    float Calculation2[255];
    QString Time[255];
};
//--------------------------------用来从位移历史数据库读取信息----------------------------------------------------
struct Select_DATA
{
     int fz_id[255];
     int  fz_type[255];
      int cgq_type[255];
       int cgq_id[255];
     int shenji[255];
    int qianji[255];
    QString shiji[255];
};

//--------------------------------供上位机访问位移实时数据----------------------------------------------------
struct Realtime_UPUSE    //取出原始数据
{
  //   int fz_id[42];
   //  int  fz_type[42];
      int cgq_type[42];
       int cgq_id[42];
     QString shenji[42];
    int qianji[42];
    QString shiji[42];
};

struct Realtime_UPUSE_SHOW    //写入数据库
{
    // int fz_id[42];
   //  int  fz_type[42];
      int cgq_type[42];
       int cgq_id[42];
      QString shenji[42];
      int qianji[42];
      int A_B[42];
      QString statue[42];
      QString shiji[42];
};

//--------------------------------用来从位移历史数据库读取信息----------------------------------------------------
struct Realtime_Date_flag
{
     int flag;
     int Displacement_Realtime1[20];
};
extern Realtime_Date_flag Displacement_Realtime1,Displacement_Realtime2;
//---------------------------------------位移历史存储--------------------------------------------------------------
struct Store_struct
{
     int flag;
     int Displacement_store_date[41];
};
extern Store_struct Displacement_store_date;
//---------------------------------------压力历史存储--------------------------------------------------------------
struct PressureStore_struct
{
     int flag;
     int Pressure_Store_store_date[41];
};
extern  PressureStore_struct Pressure_Store_store_date;


#endif // GOLOBE_H
