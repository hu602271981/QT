#ifndef MAIN_H
#define MAIN_H
#include "sql.h"
#include "Real-time_Data.h"
#include "store_information.h"
#include "substation.h"
#include "substation2.h"
#include <dialog1.h>    //通信测试显示画面头文件
#include <dialog2.h>    //历史数据显示画面头文件
#include <dialog3.h>    //数据发送显示画面头文件
#include <dialogclear.h>  //数据清除显示画面头文件
#include <dialogstatistics.h>  //数据统计显示画面头文件
#include <Pressure_HD.h>  //压力传感器历史数据画面
#include <Displacement_HD.h>    //位移传感器历史数据画面
#include "realtime_presser.h"
#include "processer_storeinformation.h" //顶板压力存储信息
#include "diastatisticsmana1.h" //顶板位移统计
#include "Data_Management.h" //数据管理
#include "diastatisticsmana2.h" //压力统计画面
#include "substation.h" //分站本机参数设定
#include "parametersetting.h"  //参数设定
#include "substation2.h" //关联传感器参数设定
#include "zonghexinxixinshihuamian.h" //综合信息显示
//#include "mysqlquerymodel.h"
#include "storesinformation.h"

sql* SQLmain();  //主界面
Dialog* REAL_TIME();  //实时数据库
Storesinformation* Total_Store_Information(); //存储信息界面
Store_information* Store_Information(); //顶板位移存储信息
Processer_StoreInformation* Processer_Store_Information(); //顶板压力存储信息

Substation* FZ_LOCAL(); //分站本机参数设定
Substation2* GC_Set(); //关联传感器
Dialog1* Communication_Test();  //通信测试界面
Dialog2* Historical_data();   //历史数据显示画面
Dialog3* Data_Transmission(); //数据发送显示画面
Dialogclear* Data_Delete(); //数据清除显示画面
DialogStatistics*  Data_Statistics(); //数据统计显示画面
Dia1* Pressure_Hd();    //压力传感器历史数据画面
Dia2* Displacement_Hd();  //位移传感器历史数据画面
realtime_presser* Realtime_presser();//顶板压力实时数据

Diastatisticsmana1* WY_Statistics();//位移传感器数据统计画面头文件
Data_Management* Data_management();//数据管理
Diastatisticsmana2* PRESSURE_Statistics();//压力数据统计画面
Substation* Substation_local();//分站本机参数设定
ParameterSetting* Parameter_Setting();//参数设定
//Substation2* Sensor_Set();////关联传感器参数设定
//zonghexinxixinshihuamian* Information(); //综合信息

//int flag_realtime;
#endif // MAIN_H
