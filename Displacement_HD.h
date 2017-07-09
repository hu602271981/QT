#ifndef DIA2_H
#define DIA2_H
//位移传感器历史数据画面
#include <QDialog>

namespace Ui {
class Dia2;
}

class Dia2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dia2(QWidget *parent = 0);
    ~Dia2();

private:
    Ui::Dia2 *ui;

};

#endif // DIA2_H
