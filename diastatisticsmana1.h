#ifndef DIASTATISTICSMANA1_H
#define DIASTATISTICSMANA1_H
 //位移传感器数据统计画面头文件
#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
namespace Ui {
class Diastatisticsmana1;
}

class Diastatisticsmana1 : public QDialog
{
    Q_OBJECT

public:
    explicit Diastatisticsmana1(QWidget *parent = 0);
    ~Diastatisticsmana1();
    int Show_WY_Statistics_Date(QSqlDatabase db,QString Which_Table); //显示位移统计信息
    int UPDATE_Statistics_Date(void); //来更新数据的函数
      Ui::Diastatisticsmana1 *ui;
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件
};

#endif // DIASTATISTICSMANA1_H
