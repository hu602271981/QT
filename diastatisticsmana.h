#ifndef DIASTATISTICSMANA_H
#define DIASTATISTICSMANA_H
//数据统计管理显示画面头文件
#include <QDialog>


namespace Ui {
class DiastatisticsMana;
}

class DiastatisticsMana : public QDialog
{
    Q_OBJECT

public:
    explicit DiastatisticsMana(QWidget *parent = 0);
    ~DiastatisticsMana();    
 private slots:
        void open_data_slots(void); //数据统计功能开启
         void close_data_slots(void); //数据统计功能开启
          void clear_data_slots(void); //数据统计功能清除

private:
    Ui::DiastatisticsMana *ui;

};

#endif // DIASTATISTICSMANA_H
