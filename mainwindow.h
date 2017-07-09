#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//桌面图标显示画面
#include <QMainWindow>
#include<storesinformation.h>//存储信息头文件
#include <parametersetting.h>//参数设定头文件
#include "Data_Management.h"//数据处理头文件
#include <realtimedata.h>//实时数据头文件

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  Ui::MainWindow *ui;
//private:

private slots:
    void saveDataslot();//存储数据槽
    void parameterSettingSlot();//参数设定槽
    void dataslot();
    void Realtimedataslot();

};

#endif // MAINWINDOW_H
