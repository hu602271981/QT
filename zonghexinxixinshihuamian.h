#ifndef ZONGHEXINXIXINSHIHUAMIAN_H
#define ZONGHEXINXIXINSHIHUAMIAN_H
#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
//分站综合信息显示画面
namespace Ui {
class zonghexinxixinshihuamian;
}

class zonghexinxixinshihuamian : public QDialog
{
    Q_OBJECT

public:
    explicit zonghexinxixinshihuamian(QWidget *parent = 0);
    ~zonghexinxixinshihuamian();
    int   Information_show(QSqlDatabase db);//显示本页面数据
    int   Information_UPdate(void); //综合信息更新
    int   UPDATE_wy_Number(QSqlDatabase db); //位移传感器在线台数
   Ui::zonghexinxixinshihuamian *ui;


protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件

private slots:
     void Real_time_Date();
     void CloseWindows();
};

#endif // ZONGHEXINXIXINSHIHUAMIAN_H
