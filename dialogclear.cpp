#include "dialogclear.h"
#include "ui_dialogclear.h"
#include <QTextCodec>
#include "QKeyEvent"
#include "main.h"
Dialogclear::Dialogclear(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogclear)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Dialogclear::~Dialogclear()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 清除分站保存的位移传感器数据
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialogclear::on_pushButton_clicked()
{

    QMessageBox message(QMessageBox::Warning,"Information","Really to clear data?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
    }
    else
    {
        qDebug()<<"clicked no\n";
    }
}

/*******************************************************************************
* Function Name  : 清楚分站保存的压力数据
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialogclear::on_pushButton_2_clicked()
{

    QMessageBox message(QMessageBox::Warning,"Information","Really to clear data?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
    }
    else
    {
        qDebug()<<"clicked no\n";
    }
}
/*******************************************************************************
* Function Name  :清楚分站保存的传感器数据
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialogclear::on_pushButton_3_clicked()
{

    QMessageBox message(QMessageBox::Warning,"Information","Really to clear data?",QMessageBox::Yes|QMessageBox::No,NULL);
    if (message.exec()==QMessageBox::Yes)
    {
        qDebug()<<"clicked yes\n";
    }
    else
    {
        qDebug()<<"clicked no\n";
    }
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dialogclear::keyPressEvent(QKeyEvent *event)
{

     Data_Management *kk =new Data_Management();


    switch(event->key()) {
    case Qt::Key_F1:                       //左键
         //information();
        break;
    case Qt::Key_Escape:                  //右键
              Data_Delete()->hide();
              kk->showFullScreen();
              kk->exec();
        break;
    case Qt:: Key_Left:
         //front()->hide();
             ;
        break;
    case Qt::Key_Up:                  //右键
         //front()->hide();
             ;
        break;
    case Qt::Key_Right:                  //右键
         //front()->hide();
             ;
        break;
    case Qt::Key_Down:                  //右键
         //front()->hide();
             ;
        break;
    default:
    //   fullscreenwindow::keyPressEvent(event);
        break;
    }
}

