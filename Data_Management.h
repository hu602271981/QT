#ifndef DATA_H
#define DATA_H
//数据管理头文件
#include <QDialog>
#include <dialog1.h>    //通信测试显示画面头文件
#include <dialog2.h>    //历史数据显示画面头文件
#include <dialog3.h>    //数据发送显示画面头文件
#include <dialogclear.h>  //数据清除显示画面头文件
#include <dialogstatistics.h>  //数据统计显示画面头文件
#include <QPushButton>
namespace Ui {
class Data;
}

class Data_Management : public QDialog
{
    Q_OBJECT

public:
    explicit Data_Management(QWidget *parent = 0);
    ~Data_Management();

private:
    Ui::Data *ui;
private slots:
    void dialog1slot();    //通讯测试槽
    void dialog2slot();   //历史数据槽
    void dialog3slot();   //数据发送槽
    void dialog4slot();   //数据清除槽
    void dialog5slot();   //数据统计槽
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件
};

#endif // DATA_H
