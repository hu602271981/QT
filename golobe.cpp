#include "golobe.h"
#include <zonghexinxixinshihuamian.h>
#include <realtimedata.h>


//主窗口全局访问
MainWindow *Qman()
{
    static MainWindow golobewindow;
    return &golobewindow;
}

//综合信息全局访问
zonghexinxixinshihuamian *front()
{
    static zonghexinxixinshihuamian ZH;
    return &ZH;
}

//extern struct Realtime_Date_flag Displacement_Realtime1,Displacement_Realtime2;

unsigned char Can_Rx_Save[8]; //用来暂时保存can总线接收的数据
unsigned int Can_Id; //保存canid

 PressureStore_struct Pressure_Store_store_date;
 Realtime_Date_flag Displacement_Realtime1,Displacement_Realtime2;
Store_struct Displacement_store_date;
