#ifndef SUBSTATION2_H
#define SUBSTATION2_H
//分站关联传感器参数设定显示画面头文件
#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
namespace Ui {
class Substation2;
}

class Substation2 : public QDialog
{
    Q_OBJECT

public:
    explicit Substation2(QWidget *parent = 0);
    ~Substation2();
    Ui::Substation2 *ui;
    int Correlation_sensor_UI_SHOW(void); //界面显示
     void Correlation_sensor_UPdate(void);//分站本机参数更新
     void Correlation_sensor_Save_sql(void); //对话框判断是否写入数据库
     int Correlation_sensor_Save_Date(QSqlDatabase db,QString Which_Table); //写入数据库

public slots:
    bool eventFilter(QObject *,QEvent *);
 signals:
    void Update_Signal(int num);
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件

};

#endif // SUBSTATION2_H
