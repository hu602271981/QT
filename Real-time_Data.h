#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
//#include "golobe.h"
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>

#include <QSqlQueryModel>
//位移实时






namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Ui::Dialog *RealTimeui;
   //  QVariant data(const QModelIndex &index, int role) const;   //设置颜色
     int RealTime_Up_Date(void);       //实时数据的更新
     int UPDATE_YL_RealTime_Number(QSqlDatabase db); //更新在线台数
     void do_send(void); //发射信号的函数
 //----------------------------------------------------供上位机使用本地不显示---------------------------------------------------
   int Displacement_UP_RealTime(QSqlDatabase db,QString Which_Table,QString Which_Table2); //位移实时数据上位机


 //-------------------------------------------------------------------------------------------------------------
protected:
     void keyPressEvent(QKeyEvent *event);  //按键事件

signals:
        void send(int num);


};



/*******************************************************************************
* Function Name  :实时位移表格一颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class MySqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit MySqlQueryModel(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;


signals:

public slots:

private:

};

/*******************************************************************************
* Function Name  :实时位移表格二颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Displacement_Realtime2_MySql : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Displacement_Realtime2_MySql(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;



signals:

public slots:

private slots:


};

#endif // DIALOG_H
