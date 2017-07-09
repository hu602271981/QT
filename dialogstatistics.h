#ifndef DIALOGSTATISTICS_H
#define DIALOGSTATISTICS_H
//数据统计显示画面
#include <QDialog>
#include <diastatisticsmana.h>    //数据统计管理显示画面头文件
#include <diastatisticsmana1.h>   //位移传感器数据统计画面头文件
#include <diastatisticsmana2.h>  //压力传感器数据统计画面头文件

namespace Ui {
class DialogStatistics;
}

class DialogStatistics : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStatistics(QWidget *parent = 0);
    ~DialogStatistics();

private:
    Ui::DialogStatistics *ui;
 private slots:
    void DiastatisticsManaSlot();
    void Diastatisticsmana1Slot();
    void Diastatisticsmana2Slot();

protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件


};

#endif // DIALOGSTATISTICS_H
