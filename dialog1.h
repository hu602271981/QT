#ifndef DIALOG1_H
#define DIALOG1_H
//通信测试显示画面
#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();



private:
    Ui::Dialog1 *ui;
private slots:
    void Dataslot1(); //向传感器发送一帧时间信息
    void Dataslot2(); //清楚传感器历史数据指令
    void Dataslot3(); //发送传感器数据清零测试指令
    void Dataslot4(); //向上层设备发送分站本机参数信息
    void Dataslot5(); //向上层设备发送本机关联传感器参数信息
protected:
    void keyPressEvent(QKeyEvent *event);

};

#endif // DIALOG1_H
