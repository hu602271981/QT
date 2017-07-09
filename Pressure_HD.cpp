#include "Pressure_HD.h"
#include "ui_Pressure_HD.h"
#include "QKeyEvent"
#include "dialog2.h"
#include "main.h"
Dia1::Dia1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dia1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);



    //定义两个可变数组存放绘图的坐标数据
         QVector<double> x(101),y(101);//分别存放x和y坐标的数据,101为数据长度
        //添加数据，我们这里演示y=x^3,为了正负对称，我们x从-10到+10
        for(int i=0;i<=10;i++)
        {
             x[i] = i ;
         //到达初撑点
             if(i<=3)
             {
                 qDebug()<<"1-3";
                y[i] = 20*x[i]-20;
             }
             if((3<i)&&(i<=5))
             {
                 qDebug()<<"3-5";
                y[i] = 5*x[i]+25;
             }
             if((5<i)&&(i<=8))
             {
               qDebug()<<"5-7";
                y[i] = -3.75*x[i]+68.75;
             }
             if((8<i)&&(i<=10))
             {
                          qDebug()<<"7-10";
                y[i] = -35*x[i]+350;
             }



        }

        //向绘图区域QCustomPlot(从widget提升来的)添加一条曲线
          ui->widget->addGraph();
        //添加数据
         ui->widget->graph(0)->setData(x,y);

         //设置坐标轴标签名称
         ui->widget->xAxis->setLabel(QObject::trUtf8("时间"));
         ui->widget->yAxis->setLabel(QObject::trUtf8("兆帕"));

        //设置坐标轴显示范围,否则我们只能看到默认的范围
         ui->widget->xAxis->setRange(0,11);
         ui->widget->yAxis->setRange(0,60);

        //重绘，这里可以不用，官方例子有，执行setData函数后自动重绘
         //我认为应该用于动态显示或者是改变坐标轴范围之后的动态显示，我们以后探索
         // ui->widget->replot();

















}

Dia1::~Dia1()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Dia1::keyPressEvent(QKeyEvent *event)
{
     Dialog2 *d= new Dialog2();

    switch(event->key()) {
    case Qt::Key_F1:                       //左键
        // information();
        break;
    case Qt::Key_Escape:                  //右键
                    Pressure_Hd()->hide();
                    d->showFullScreen();
                    d->exec();


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
     //  fullscreenwindow::keyPressEvent(event);
        break;
    }
}
