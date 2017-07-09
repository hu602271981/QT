#ifndef DIALOG3_H
#define DIALOG3_H
//数据发送显示画面
#include <QDialog>

#include <QPushButton>


namespace Ui {
class Dialog3;
}

class Dialog3 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog3(QWidget *parent = 0);
    ~Dialog3();
private:
    Ui::Dialog3 *ui;
private slots:
    void Dataslot1(); //发送分站保存的位移传感器数据
    void Dataslot2(); //发送分站保存的压力传感器数据
    void Dataslot3(); //发送分站保存的传感器数据
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件


};

#endif // DIALOG3_H
