#ifndef DIA1_H
#define DIA1_H
//压力传感器历史数据画面
#include <QDialog>

namespace Ui {
class Dia1;
}

class Dia1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dia1(QWidget *parent = 0);
    ~Dia1();

private:
    Ui::Dia1 *ui;
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件


};

#endif // DIA1_H
