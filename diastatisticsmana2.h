#ifndef DIASTATISTICSMANA2_H
#define DIASTATISTICSMANA2_H
//压力传感器数据统计画面头文件
#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
namespace Ui {
class Diastatisticsmana2;
}

class Diastatisticsmana2 : public QDialog
{
    Q_OBJECT

public:
    explicit Diastatisticsmana2(QWidget *parent = 0);
    ~Diastatisticsmana2();
     int Show_Pressure_Statistics_Date(QSqlDatabase db,QString Which_Table); //显示压力统计信息
     int UPDATE_Pressure_Statistics_Date(void); //压力更新数据的函数
      Ui::Diastatisticsmana2 *ui;
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件

};

#endif // DIASTATISTICSMANA2_H
