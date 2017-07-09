#include "parametersetting.h"
#include "ui_parametersetting.h"
#include "main.h"
ParameterSetting::ParameterSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParameterSetting)
{
    ui->setupUi(this);
       ui->substationButton->setCheckable (false );
          ui->associationButton->setCheckable (false );
    QObject::connect(ui->substationButton,SIGNAL(clicked(bool)),this,SLOT(substationslot())); //分站本机
    QObject::connect(ui->associationButton,SIGNAL(clicked()),this,SLOT(substation2slot())); //关联传感器
    this->setWindowFlags(Qt::FramelessWindowHint);
}

ParameterSetting::~ParameterSetting()
{
    delete ui;
}
/*******************************************************************************
* Function Name  :  分站本机参数设定
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void ParameterSetting::substationslot()
{
  //Substation *h=new Substation();
   Parameter_Setting()->close();

    FZ_LOCAL()->showFullScreen();
    FZ_LOCAL()->exec();

    // h->show();
    // h->exec();
      this->show();
}
/*******************************************************************************
* Function Name  :  关联传感器参数设定
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void ParameterSetting::substation2slot()
{
   // Substation2 *o =new Substation2();
   Parameter_Setting()->close();
    GC_Set()->showFullScreen();
    GC_Set()->exec();
   // o->show();
   // o->exec();
   // this->show();
}

