#include "realtime_presser.h"
#include "ui_realtime_presser.h"
#include "main.h"
#include "QKeyEvent"
realtime_presser::realtime_presser(QWidget *parent) :
    QDialog(parent),
    Realtime_pressure_ui(new Ui::realtime_presser)
{
   Realtime_pressure_ui->setupUi(this);
         QString cgq_type= "02";
        char* cgq_type_name  = "顶板压力";
        Realtime_pressure_ui->cgq_type_lineEdit_->setText(cgq_type);
        Realtime_pressure_ui->name_lineEdit->setText(QObject::trUtf8(cgq_type_name));
}

realtime_presser::~realtime_presser()
{
    delete Realtime_pressure_ui;
}
/*******************************************************************************
* Function Name  : 实时数据的更新
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

int realtime_presser::PRESSURE_RealTime_Up_Date(void)      //实时数据的更新
{
    //-------------显示更新-----------------------------------------

    Realtime_presser()->Show_Pressure_RealTime_Date(SQLmain()->db_TEST,\
                                 "select cgq_id,lizhu1,lizhu2 from  Pressere_Realtime  where cgq_id between 1 and 10 ;",\
                                 "select cgq_id,lizhu1,lizhu2 from  Pressere_Realtime where cgq_id between 11 and 20;");


   //---------------更新台数-------------------------------------------
        Realtime_presser()->UPDATE_WY_RealTime_Number(SQLmain()->db_TEST);





}
/*******************************************************************************
* Function Name  :   //更新在线台数
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int realtime_presser::UPDATE_WY_RealTime_Number(QSqlDatabase db)
{
    QString data="OFF LINE";
     int ON_LINE_NUMBER;
    QString ON_LINE_NUMBERnew;
  // for(int i=1;i<=20;i++)
//   {
       QString cmd4 ="use test;";
       QString cmd5=QString("select count(1) from  Pressere_Realtime where lizhu1='%1';").arg(data);
        QSqlQuery  q4(cmd4,db);
        QSqlQuery  q5(cmd5,db);
        while (q5.next()) {
          //      qDebug() << "table name:" << q5.value(0).toString();
                ON_LINE_NUMBER=q5.value(0).toInt();
        }
                  q5.exec();
 //  }

 // qDebug() << "table name:" << ON_LINE_NUMBER ;
// dd=20-ON_LINE_NUMBER;

  // QString string;
  ON_LINE_NUMBERnew=QString::number(20-ON_LINE_NUMBER);

  Realtime_pressure_ui->Number_lineEdit->setText(ON_LINE_NUMBERnew);




}

/*******************************************************************************
    * Function Name  : //位移实时数据库初始化
    * Description    :
    * Input          :
    * Output         : None.
    * Return         : None.
    *******************************************************************************/
    int realtime_presser:: Init_Pressure_RealTime_Date_SQL(QSqlDatabase db)
    {

        QString cmd4 ="use test";
         QString init="OFF LINE";
        for(int cc=1;cc<=20;cc++)
        {

             QString cmd_write=QString("update Pressere_Realtime set lizhu1 = '%1',lizhu2 = '%2' where cgq_id = %3;").arg(init).arg(init).arg(cc);
              QSqlQuery   q4(cmd4,db);
              QSqlQuery  q5(cmd_write,db);
       }
    }
    /*******************************************************************************
    * Function Name  : 显示压力传感器当前数据库的数据
    * Description    :    Which_Table id 1~10    Which_Table2 id 10~20
    * Input          : None.
    * Output         : None.
    * Return         : None.
    *******************************************************************************/
     int realtime_presser:: Show_Pressure_RealTime_Date(QSqlDatabase db,QString Which_Table,QString Which_Table2)
    {
       //-----------------------------------id 1~10--------------------------------------------------------------------------------
         QSqlQueryModel *model= new QSqlQueryModel(Realtime_presser()->Realtime_pressure_ui->tableView);

         model->setQuery(Which_Table,db);
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("立柱1/Mpa"));

        model->setHeaderData(2,Qt::Horizontal,QObject::tr("立柱2/Mpa"));
       // model->setHeaderData(3,Qt::Horizontal,QObject::tr("时间"));
        Realtime_presser()->Realtime_pressure_ui->tableView->setModel(model);

      //  REAL_TIME()->data(REAL_TIME()->RealTimeui->tableView->currentIndex(),8);

      //  Realtime_presser()->data(Realtime_presser()->Realtime_pressure_ui->tableView->currentIndex(),8);
        //  ui->tableView->
         //------------------------------------------设置颜色-------------------------------------------------------
       Realtime_presser()->Realtime_pressure_ui->tableView->setAlternatingRowColors( true );
       Realtime_presser()->Realtime_pressure_ui->tableView->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
             //                                            // "alternate-background-color: rgb(141, 163, 215);}"
           //--------------------------------------------设置颜色-----------------------------------------------------

           //--------------------------------------------设置列宽-----------------------------------------------------
          // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
          //  ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
          //  ui->tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
         //   ui->tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
                //设置表格的各行高的宽度值
               Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(0,20);
               Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(1,20);
               Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(2,20);
                Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(3,20);
                Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(4,20);
                Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(5,20);
                Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(6,20);
                Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(7,20);
               Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(8,20);
               Realtime_presser()->Realtime_pressure_ui->tableView->setRowHeight(9,20);

                //设置表格的各列的宽度值
              /* ui->tableView->setColumnWidth(0,60);
               ui->tableView->setColumnWidth(1,60);
               ui->tableView->setColumnWidth(2,60);
               ui->tableView->setColumnWidth(3,60);
               ui->tableView->setColumnWidth(4,60);*/
               //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
             Realtime_presser()->Realtime_pressure_ui->tableView->verticalHeader()->hide();
           //--------------------------------------------设置列宽-----------------------------------------------------
      //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
       Realtime_presser()->Realtime_pressure_ui->tableView->resizeColumnsToContents();
        //ui->tableView->resizeRowsToContents();


      //-----------------------------------id 11~20--------------------------------------------------------------------------------
       QSqlQueryModel *model1= new QSqlQueryModel( Realtime_presser()->Realtime_pressure_ui->tableView_2);
       model1->setQuery(Which_Table2,db);
       model1->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
       model1->setHeaderData(1,Qt::Horizontal,QObject::tr("立柱1/Mpa"));
      model1->setHeaderData(2,Qt::Horizontal,QObject::tr("立柱2/Mpa"));
     // model->setHeaderData(3,Qt::Horizontal,QObject::tr("时间"));
      Realtime_presser()->Realtime_pressure_ui->tableView_2->setModel(model1);


      //  ui->tableView->
       //------------------------------------------设置颜色-------------------------------------------------------
      // Realtime_presser()->data( Realtime_presser()->Realtime_pressure_ui->tableView_2->currentIndex(),1);

     Realtime_presser()->Realtime_pressure_ui->tableView_2->setAlternatingRowColors( true );
      Realtime_presser()->Realtime_pressure_ui->tableView_2->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
           //                                            // "alternate-background-color: rgb(141, 163, 215);}"
         //--------------------------------------------设置颜色-----------------------------------------------------

         //--------------------------------------------设置列宽-----------------------------------------------------
        // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
        //  ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
        //  ui->tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
       //   ui->tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
              //设置表格的各行高的宽度值
             Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(0,20);
             Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(1,20);
             Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(2,20);
              Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(3,20);
              Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(4,20);
              Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(5,20);
             Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(6,20);
             Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(7,20);
            Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(8,20);
              Realtime_presser()->Realtime_pressure_ui->tableView_2->setRowHeight(9,20);

              //设置表格的各列的宽度值
            /* ui->tableView->setColumnWidth(0,60);
             ui->tableView->setColumnWidth(1,60);
             ui->tableView->setColumnWidth(2,60);
             ui->tableView->setColumnWidth(3,60);
             ui->tableView->setColumnWidth(4,60);*/
             //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
           Realtime_presser()->Realtime_pressure_ui->tableView_2->verticalHeader()->hide();
         //--------------------------------------------设置列宽-----------------------------------------------------
    //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
         Realtime_presser()->Realtime_pressure_ui->tableView_2->resizeColumnsToContents();
      //ui->tableView->resizeRowsToContents();

      }

     /*******************************************************************************
     * Function Name  :
     * Description    : 按right建跳转到位移实时信息
     * Input          : None.
     * Output         : None.
     * Return         : None.
     *******************************************************************************/
     void realtime_presser::keyPressEvent(QKeyEvent *event)
     {
         switch (event->key()) {
         case Qt::Key_F1:
           //  information();
             break;
         case Qt::Key_Escape:                  //右键
             Realtime_presser()->hide();
             Qman()->showFullScreen();

               break;
             case Qt:: Key_Left:


                  break;
             case Qt::Key_Up:                  //右键
                        ;
                 break;
             case Qt::Key_Right:                  //右键

                 break;
             case Qt::Key_Down:                  //右键
            //  Realtime_presser()->hide();
            //  REAL_TIME()->showFullScreen();
            //  REAL_TIME()->exec();
                 break;
         default:
            //ScreenSaver::keyPressEvent(event);
             break;
         }
     }
