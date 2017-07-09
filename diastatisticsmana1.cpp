#include "diastatisticsmana1.h"
#include "ui_diastatisticsmana1.h"
#include "main.h"
#include "QKeyEvent"
//位移传感器数据统计画面
Diastatisticsmana1::Diastatisticsmana1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diastatisticsmana1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

}

Diastatisticsmana1::~Diastatisticsmana1()
{
    delete ui;
}
/*******************************************************************************
* Function Name  : //显示位移统计信息
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int Diastatisticsmana1::Show_WY_Statistics_Date(QSqlDatabase db,QString Which_Table)
{
     QSqlQueryModel *model= new QSqlQueryModel(ui->ID_1_10);
      model->setQuery(Which_Table,db);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("序号\n n"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("在线时长\n (h)"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("离线时长\n (h)"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("离层超限\n 时间"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("深基变化率\n 报警次数"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("浅基变化率\n 报警次数"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("数据存储\n 次数"));
      //获取表格中的数据条数
    //  qDebug()<<model->rowCount();

    ui->ID_1_10->setModel(model);
      //------------------------------------------设置颜色-------------------------------------------------------
   ui->ID_1_10->setAlternatingRowColors( true );
   ui->ID_1_10->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
          //                                            // "alternate-background-color: rgb(141, 163, 215);}"
        //--------------------------------------------设置颜色-----------------------------------------------------

        //--------------------------------------------设置列宽-----------------------------------------------------
       // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
       //ui->ID_1_10->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
       //ui->ID_1_10->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
      // ui->ID_1_10->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
             //设置表格的各行高的宽度值
          ui->ID_1_10->setRowHeight(0,20);
           ui->ID_1_10->setRowHeight(1,20);
           ui->ID_1_10->setRowHeight(2,20);
           ui->ID_1_10->setRowHeight(3,20);
           ui->ID_1_10->setRowHeight(4,20);
           ui->ID_1_10->setRowHeight(5,20);
           ui->ID_1_10->setRowHeight(6,20);
           ui->ID_1_10->setRowHeight(7,20);
           ui->ID_1_10->setRowHeight(8,20);
           ui->ID_1_10->setRowHeight(9,20);

             //设置表格的各列的宽度值
          ui->ID_1_10->setColumnWidth(0,40);
          ui->ID_1_10->setColumnWidth(1,70);
          ui->ID_1_10->setColumnWidth(2,70);
          ui->ID_1_10->setColumnWidth(3,70);
          ui->ID_1_10->setColumnWidth(4,80);
            ui->ID_1_10->setColumnWidth(5,80);
           ui->ID_1_10->setColumnWidth(6,70);
            //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
         ui->ID_1_10->verticalHeader()->hide();
        //--------------------------------------------设置列宽-----------------------------------------------------
   //ui->ID_1_10->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
     //ui->ID_1_10->resizeColumnsToContents();
     //ui->tableView->resizeRowsToContents();





}
/*******************************************************************************
* Function Name  : 更新数据库
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int Diastatisticsmana1::UPDATE_Statistics_Date(void)
{
                                WY_Statistics()->Show_WY_Statistics_Date(SQLmain()->db_TEST, \
                                   "select *from Displacement_Statistics where ID between 1 and 10  ;");


}
/*******************************************************************************
* Function Name  :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Diastatisticsmana1::keyPressEvent(QKeyEvent *event)
{
     // DialogStatistics *f = new DialogStatistics();
    switch(event->key()) {
    case Qt::Key_F1:                       //左键
         //information();
        break;
    case Qt::Key_Escape:                  //右键
                //WY_Statistics()->hide();
                 WY_Statistics()->close();
                Data_Statistics()->showFullScreen();
               Data_Statistics()->exec();

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
