#ifndef PARAMETERSETTING_H
#define PARAMETERSETTING_H
//参数设定头文件
#include <QDialog>
#include <substation.h>  //分站本机参数设定显示画面头文件
#include <substation2.h>  //分站关联传感器参数设定显示画面头文件
//

namespace Ui {
class ParameterSetting;
}

class ParameterSetting : public QDialog
{
    Q_OBJECT

public:
    explicit ParameterSetting(QWidget *parent = 0);
    ~ParameterSetting();

private:
    Ui::ParameterSetting *ui;
private slots:
    void substationslot();
    void substation2slot();

};

#endif // PARAMETERSETTING_H
