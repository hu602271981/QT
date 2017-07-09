#ifndef STORESINFORMATION_H
#define STORESINFORMATION_H
//存储信息头文件
#include <QDialog>
#include <storeinformation1.h>   //顶板离层存储信息列表画面头文件
#include <storeinformation2.h>    //支架压力存储信息头文件

namespace Ui {
class Storesinformation;
}

class Storesinformation : public QDialog
{
    Q_OBJECT

public:
    explicit Storesinformation(QWidget *parent = 0);
    ~Storesinformation();
     Ui::Storesinformation *ui;


private slots:
    void storeInformation1Slot();
    void storeInformation2Slot();

};

#endif // STORESINFORMATION_H
