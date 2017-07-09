#ifndef REALTIMEDATA_H
#define REALTIMEDATA_H
//实时数据界面
#include <QDialog>

namespace Ui {
class Realtimedata;
}

class Realtimedata : public QDialog
{
    Q_OBJECT

public:
    explicit Realtimedata(QWidget *parent = 0);
    ~Realtimedata();

private:
    Ui::Realtimedata *ui;
};

#endif // REALTIMEDATA_H
