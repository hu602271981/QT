#ifndef REALTIME_PRESSER_H
#define REALTIME_PRESSER_H

#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
namespace Ui {
class realtime_presser;
}

class realtime_presser : public QDialog
{
    Q_OBJECT

public:
    explicit realtime_presser(QWidget *parent = 0);
    ~realtime_presser();
      Ui::realtime_presser *Realtime_pressure_ui;
       int PRESSURE_RealTime_Up_Date(void);       //实时数据的更新
       int UPDATE_WY_RealTime_Number(QSqlDatabase db); //更新在线台数
       int Init_Pressure_RealTime_Date_SQL(QSqlDatabase db); //数据库初始化
      int Show_Pressure_RealTime_Date(QSqlDatabase db,QString Which_Table,QString Which_Table2); //显示
protected:
     void keyPressEvent(QKeyEvent *event);  //按键事件
};

#endif // REALTIME_PRESSER_H
