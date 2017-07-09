#include "storesinformation.h"
#include "ui_storesinformation.h"
#include "main.h"

Storesinformation::Storesinformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Storesinformation)
{
    ui->setupUi(this);
      ui->roofButton->setCheckable (false );
        ui->stentPressureButton->setCheckable (false );

    QObject::connect(ui->roofButton,SIGNAL(clicked()),this,SLOT(storeInformation1Slot())); //顶板离层
    QObject::connect(ui->stentPressureButton,SIGNAL(clicked()),this,SLOT(storeInformation2Slot())); //压力
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Storesinformation::~Storesinformation()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 顶板离层
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void Storesinformation::storeInformation1Slot()
{
    //StoreInformation1 *a = new StoreInformation1();
   // Storesinformation *b =new Storesinformation();
  //  this->hide();
    Total_Store_Information()->close();
    Store_Information()->showFullScreen();
    Store_Information()->exec();

   // a->show();
   // a->exec();
   // b->show();
  //  b->exec();
  // this->show();
}
/*******************************************************************************
* Function Name  : 压力
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void Storesinformation::storeInformation2Slot()
{
    //Storeinformation2 *aa =new Storeinformation2();
   // Storesinformation  *bb = new Storesinformation();
     Total_Store_Information()->close();
     Processer_Store_Information()->showFullScreen();
     Processer_Store_Information()->exec();

}
