#ifndef DIALOG2_H
#define DIALOG2_H
//历史数据显示画面
#include <QDialog>
#include <Pressure_HD.h>  //位移传感器历史数据画面
#include <Displacement_HD.h>  //压力传感器历史数据画面

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();

private:
    Ui::Dialog2 *ui;
private slots:
    void diaSlot();  //   压力传感器历史数据画面
    void dia2Slot(); // 位移传感器历史数据画面
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件
};

#endif // DIALOG2_H
