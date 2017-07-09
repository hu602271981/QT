#ifndef SUBSTATION_H
#define SUBSTATION_H
//分站本机参数设定显示画面头文件
#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QtNetwork>
namespace Ui {
class Substation;
}

class Substation : public QDialog
{
    Q_OBJECT

public:
    explicit Substation(QWidget *parent = 0);
    ~Substation();
       int UI_SHOW(void); //界面显示
      Ui::Substation *ui;
      void Substation_Local_UPdate(void);//分站本机参数更新
      void Save_sql(void); //对话框判断是否写入数据库
       int Substation_Save_Date(QSqlDatabase db,QString Which_Table); //写入数据库
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件
public slots:
      bool eventFilter(QObject *,QEvent *);
signals:
    void Update_Signal(int num);
};

#endif // SUBSTATION_H
