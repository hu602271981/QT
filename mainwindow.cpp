#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  "main.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

      ui->saveButton->setCheckable (false );
      ui->parameterButton->setCheckable (false );
       ui->dataManagementButton->setCheckable (false );
       ui->currentdataButton->setCheckable (false );




    QObject::connect(ui->saveButton,SIGNAL(clicked(bool)),this,SLOT(saveDataslot()));
    QObject::connect(ui->parameterButton,SIGNAL(clicked(bool)),this,SLOT(parameterSettingSlot()));
    QObject::connect(ui->dataManagementButton,SIGNAL(clicked(bool)),this,SLOT(dataslot()));
    QObject::connect(ui->currentdataButton,SIGNAL(clicked()),this,SLOT(Realtimedataslot()));

    this->setWindowFlags(Qt::FramelessWindowHint);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 存储信息
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void MainWindow::saveDataslot()
{
    Storesinformation *u=new Storesinformation();
    this->hide();
    u->show();
    u->exec();
    this->show();
}
/*******************************************************************************
* Function Name  : 参数设定
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void MainWindow::parameterSettingSlot()
{
  // ParameterSetting *i=new  ParameterSetting();
     this->hide();
     Parameter_Setting()->showFullScreen();
     Parameter_Setting()->exec();
     this->show();
}
/*******************************************************************************
* Function Name  : 数据管理
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void MainWindow::dataslot()
{
    Data_Management *j = new Data_Management();
    this->hide();
    j->show();
    j->exec();
    this->show();
}
/*******************************************************************************
* Function Name  : 实时数据
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void MainWindow::Realtimedataslot()
{
//    Realtimedata *hh = new Realtimedata();
//    this->hide();
//    hh->show();
//    hh->exec();
//    this->show();
     //----------------------------------------2016 12 11 改---------------------------------

       this->hide();
       REAL_TIME()->showFullScreen();
       REAL_TIME()->exec();
       this->show();




}
