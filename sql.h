#ifndef SQL_H
#define SQL_H
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include </opt/local/mysql/include/mysql/mysql.h>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "qsql_mysql.h"
#include "golobe.h"
#include <QtCore>
#include <mythread.h>
#include "substation.h"

namespace Ui {
class sql;
}

class sql : public QDialog
{
    Q_OBJECT

public:
    explicit sql(QWidget *parent = 0);
    ~sql();
      QSqlDatabase db_dingban;
      QSqlDatabase db_TEST;
      QSqlDatabase db_SUB;


        //多线程
    //  struct CAN_NET_DATA SQL_DATA;
     int Connect_Sql(void); //连接数据库
     int Add_Date(struct CAN_NET_DATA data,QSqlDatabase db,QString Which_Table); //写入数据库
    // int Update_Date(unsigned char *Date_buffer,QSqlDatabase db,QString Which_Table);//更新数据库
     int Update_Date(struct CAN_NET_DATA data,QSqlDatabase db,QString Which_Table,QString Which_Table1);//实时数据
//----------------------------------------------位移传感器历史数据.开始------------------------------------------------------------------------------------------------------------------------
      int Show_SQL_Date(QSqlDatabase db,QString Which_Table,QString output_table,\
                                                 QString Show_table,QString select_table); //分站显示的位移传感器历史数据

      //-----------------------用于上位机查看-------------------------------------------------
      int Displacement_History_UPUSE(QSqlDatabase db,QString Which_Table,QString select_table);   //位移历史上位机





      //-------------------------用于上位机查看-----------------------------------------------





//-----------------------------------------------位移传感器历史数据.结束---------------------------------------------------------------------------------------------------------------------------
     int Show_SQL_RealTime_Date(QSqlDatabase db,QString Which_Table,QString Which_Table2); //显示当前实时数据数据库的数据
//     int Show_SQL_Data_Capacity(QSqlDatabase db,QString Which_Table10,QString Which_Table20\
//                                                  ,QString Which_Table30,QString Which_Table40  ); //显示数据存储容量
     int Create_Sql(void); //创建数据库
     int connectSql(QString sIp,  QString sDbNm, QString sUserNm, QString sPwd,QSqlDatabase &db) ; //远程连接
      int Init_RealTime_Date_SQL(QSqlDatabase db,QString Which_Table); //实时数据库初始化

     // unsigned int Can_Data_Chuli( unsigned int id,unsigned char *buffer,unsigned char *data);  //对数据进行处理
     //数据库名 dingban

private:
    Ui::sql *ui;
    MyThread* time;
   // Substation* Sub_station;


  public slots:
       void UpdateSlot(void);
        bool eventFilter(QObject *,QEvent *);
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件



};




#endif // SQL_H
