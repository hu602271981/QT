#include "store_information.h"
#include "ui_store_information.h"
#include <QFontDatabase>
#include "storesinformation.h"
#include "QKeyEvent"
#include "main.h"
#include <QSqlQuery>
#include <QColor>
#include "golobe.h"
//struct Store_struct Displacement_store_date;

Store_information::Store_information(QWidget *parent) :
    QDialog(parent),
    Ui_Store_information(new Ui::Store_information)
{
    Ui_Store_information->setupUi(this);

}

Store_information::~Store_information()
{
    delete Ui_Store_information;
}
/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Store_information::keyPressEvent(QKeyEvent *event)
{
    //Storesinformation *b =new Storesinformation();
    switch(event->key()) {
    case Qt::Key_F1:                       //左键
     //    information();
        break;
    case Qt::Key_Escape:                  //右键
                   Store_Information()->close();
                   Total_Store_Information()->showFullScreen();
                   Total_Store_Information()->exec();

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

/*******************************************************************************
* Function Name  : 位移存储更新
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
  int Store_information::Displacement_Store_Update(void)
  {

   Store_Information()->Displacement_Store_SHOW(SQLmain()->db_TEST, \
                                                "select id,store from Displacement_Store where id between 1 and 10 ;",\
                                               "select id,store from Displacement_Store where id between 11 and 20 ;",\
                                                 "select id,store from Displacement_Store where id between 21 and 30 ; ;",\
                                             "select id,store from Displacement_Store where id between 31 and 40 ; ;");

  }





 /*******************************************************************************
 * Function Name  : ; 显示数据存储容量
 * Description    :
 * Input          : None.
 * Output         : None.
 * Return         : None.
 *******************************************************************************/

    int Store_information::Displacement_Store_SHOW(QSqlDatabase db,QString Which_Table10,QString Which_Table20\
                                                                                           ,QString Which_Table30,QString Which_Table40 )
 {
         QString total_capacity,total_number;
         float select_capacity[41],select_number[41];
         QString capacity[41],store_data[41];
        //-----1-----------------------------计算表中总容量-------------------------------------------------------
             //计算表所占的总信息量
             QString cmd1 ="use information_schema";
             QString cmd2="select concat(round(sum(data_length/1024),2),'KB')\
                                     as data from tables where table_schema='test' and table_name='Displacement_History' ;";
             QSqlQuery       q1(cmd1,db);
             QSqlQuery        q2(cmd2,db);

           while (q2.next()) {
            //   qDebug() << "table name:" << q2.value(0).toString().remove("KB");
                total_capacity=q2.value(0).toString().remove("KB");
             }

            q1.exec();
             q2.exec();


           //计算表中信息的条数
              QString cmd4 ="use test";
              QString cmd3="select count(1) from Displacement_History;";
              QSqlQuery   q4(cmd4,db);
               QSqlQuery  q3(cmd3,db);
             while (q3.next()) {
                   // qDebug() << "table name:" << q3.value(0).toString();
                          total_number=q3.value(0).toString();
                }
                    q3.exec();
                    q4.exec();


      //-----2-----------------------------获取指定id的信息量-------------------------------------------------------


              for(int i=1;i<=40;i++)
              {
                  QString cmd5=QString("select count(1) from Displacement_History where cgq_id=%1;").arg(i);
                  //      qDebug() << cmd5;
                   QSqlQuery  q5(cmd5,db);
                   while (q5.next()) {
             //              qDebug() << "table name:" << q5.value(0).toString();
                             select_number[i]=q5.value(0).toFloat();
                   }
                      q5.exec();
              }

         //-----3-----------------------------计算制定id所占的容量-------------------------------------------------------



              for(int d=1;d<=40;d++)
              {
                    //    qDebug()<<d;
                         select_capacity[d]=(total_capacity.toFloat()/total_number.toFloat())*select_number[d];
                         store_data[d]=capacity[d]=QString::number( select_capacity[d], 'f', 1);
                          //qDebug()<< capacity[d];
                        // capacity[d]= QString("%1").arg(select_capacity[d]);


              }


           //-----4-----------------------------写入数据库-------------------------------------------------------
              for(int cc=1;cc<=40;cc++)
              {

                   QString cmd_write=QString("update Displacement_Store set store = '%1' where id = %2;").arg( capacity[cc]+"KB").arg(cc);
                  //   qDebug()<<cmd_write;
                    QSqlQuery   q4(cmd4,db);
                    QSqlQuery  q5(cmd_write,db);

            //数据检测 ----------------------------------------------------------------------------------------------------------------------------------
                  //    qDebug()<<cc<<store_data[cc].toFloat();
                    if(store_data[cc].toFloat()>=5)
                      {

                              Displacement_store_date.flag=0;
                              Displacement_store_date.Displacement_store_date[cc]=cc;
                           //     qDebug()<<cc<<Displacement_store_date.Displacement_store_date[cc];
                       //      Displacement_Realtime1.Displacement_Realtime1[i]=i;
                         //    Displacement_Realtime1.flag=0;
                        //   qDebug()<< Displacement_Realtime1.Displacement_Realtime1[i];


                      }




             }

             memset(select_capacity,0,41*sizeof(int));  //清空










         //-----5-----------------------------显示-------------------------------------------------------
            //-----------------------id 10------------------------------------------
             Displacement_Store_show1 *model10= new Displacement_Store_show1( Store_Information()->Ui_Store_information->tableView_10);
             model10->setQuery(Which_Table10,db);
             model10->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
             model10->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
             Store_Information()->Ui_Store_information->tableView_10->setModel(model10);

             //------------------------------------------设置颜色-------------------------------------------------------
         Store_Information()->Ui_Store_information->tableView_10->setAlternatingRowColors( true );
          Store_Information()->Ui_Store_information->tableView_10->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
                 //                                            // "alternate-background-color: rgb(141, 163, 215);}"
               //--------------------------------------------设置颜色-----------------------------------------------------

               //--------------------------------------------设置列宽-----------------------------------------------------
             Store_Information()->Ui_Store_information->tableView_10->setColumnWidth(0,50);
              Store_Information()->Ui_Store_information->tableView_10->setColumnWidth(1,70);
                    //设置表格的各行高的宽度值
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(0,20);
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(1,20);
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(2,20);
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(3,20);
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(4,20);
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(5,20);
                   Store_Information()->Ui_Store_information->tableView_10->setRowHeight(6,20);
                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(7,20);
                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(8,20);
                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(9,20);

                    //设置表格的各列的宽度值
                  /* ui->tableView->setColumnWidth(0,60);
                   ui->tableView->setColumnWidth(1,60);
                   ui->tableView->setColumnWidth(2,60);
                   ui->tableView->setColumnWidth(3,60);
                   ui->tableView->setColumnWidth(4,60);*/
                   //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
                Store_Information()->Ui_Store_information->tableView_10->verticalHeader()->hide();
               //--------------------------------------------设置列宽-----------------------------------------------------
          //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
          // Store_Information()->Ui_Store_information->tableView_10->resizeColumnsToContents();
            //ui->tableView->resizeRowsToContents();


                 //-----------------------id 20------------------------------------------
           Displacement_Store_show2 *model20= new Displacement_Store_show2(Store_Information()->Ui_Store_information->tableView_20);
          model20->setQuery(Which_Table20,db);
          model20->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
         model20->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
          Store_Information()->Ui_Store_information->tableView_20->setModel(model20);

          //  ui->tableView->
           //------------------------------------------设置颜色-------------------------------------------------------
        Store_Information()->Ui_Store_information->tableView_20->setAlternatingRowColors( true );
        Store_Information()->Ui_Store_information->tableView_20->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
               //                                            // "alternate-background-color: rgb(141, 163, 215);}"
             //--------------------------------------------设置颜色-----------------------------------------------------

             //--------------------------------------------设置列宽-----------------------------------------------------
        Store_Information()->Ui_Store_information->tableView_20->setColumnWidth(0,50);
        Store_Information()->Ui_Store_information->tableView_20->setColumnWidth(1,70);
                  //设置表格的各行高的宽度值
               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(0,20);
               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(1,20);
               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(2,20);
                Store_Information()->Ui_Store_information->tableView_20->setRowHeight(3,20);
                  Store_Information()->Ui_Store_information->tableView_20->setRowHeight(4,20);
                 Store_Information()->Ui_Store_information->tableView_20->setRowHeight(5,20);
                Store_Information()->Ui_Store_information->tableView_20->setRowHeight(6,20);
               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(7,20);
               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(8,20);
              Store_Information()->Ui_Store_information->tableView_20->setRowHeight(9,20);

                  //设置表格的各列的宽度值
                /* ui->tableView->setColumnWidth(0,60);
                 ui->tableView->setColumnWidth(1,60);
                 ui->tableView->setColumnWidth(2,60);
                 ui->tableView->setColumnWidth(3,60);
                 ui->tableView->setColumnWidth(4,60);*/
                 //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
               Store_Information()->Ui_Store_information->tableView_20->verticalHeader()->hide();
             //--------------------------------------------设置列宽-----------------------------------------------------
        //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
       // Store_Information()->Ui_Store_information->tableView_20->resizeColumnsToContents();
          //ui->tableView->resizeRowsToContents();


               //-----------------------id 30------------------------------------------
         Displacement_Store_show3 *model30= new Displacement_Store_show3(Store_Information()->Ui_Store_information->tableView_30);
         model30->setQuery(Which_Table30,db);
         model30->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
        model30->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
       Store_Information()->Ui_Store_information->tableView_30->setModel(model30);

        //  ui->tableView->
         //------------------------------------------设置颜色-------------------------------------------------------
       Store_Information()->Ui_Store_information->tableView_30->setAlternatingRowColors( true );
      Store_Information()->Ui_Store_information->tableView_30->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
             //                                            // "alternate-background-color: rgb(141, 163, 215);}"
           //--------------------------------------------设置颜色-----------------------------------------------------

           //--------------------------------------------设置列宽-----------------------------------------------------
      Store_Information()->Ui_Store_information->tableView_30->setColumnWidth(0,50);
       Store_Information()->Ui_Store_information->tableView_30->setColumnWidth(1,70);
                //设置表格的各行高的宽度值
             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(0,20);
             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(1,20);
             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(2,20);
              Store_Information()->Ui_Store_information->tableView_30->setRowHeight(3,20);
              Store_Information()->Ui_Store_information->tableView_30->setRowHeight(4,20);
             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(5,20);
           Store_Information()->Ui_Store_information->tableView_30->setRowHeight(6,20);
            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(7,20);
             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(8,20);
             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(9,20);

                //设置表格的各列的宽度值
              /* ui->tableView->setColumnWidth(0,60);
               ui->tableView->setColumnWidth(1,60);
               ui->tableView->setColumnWidth(2,60);
               ui->tableView->setColumnWidth(3,60);
               ui->tableView->setColumnWidth(4,60);*/
               //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
            Store_Information()->Ui_Store_information->tableView_30->verticalHeader()->hide();
           //--------------------------------------------设置列宽-----------------------------------------------------
      //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //  Store_Information()->Ui_Store_information->tableView_30->resizeColumnsToContents();
        //ui->tableView->resizeRowsToContents();


                 //-----------------------id 40------------------------------------------
       Displacement_Store_show4 *model40= new Displacement_Store_show4(Store_Information()->Ui_Store_information->tableView_4);
      model40->setQuery(Which_Table40,db);
      model40->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
      model40->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
      Store_Information()->Ui_Store_information->tableView_4->setModel(model40);


       //------------------------------------------设置颜色-------------------------------------------------------
     Store_Information()->Ui_Store_information->tableView_4->setAlternatingRowColors( true );
    Store_Information()->Ui_Store_information->tableView_4->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
           //                                            // "alternate-background-color: rgb(141, 163, 215);}"
         //--------------------------------------------设置颜色-----------------------------------------------------

         //--------------------------------------------设置列宽-----------------------------------------------------
    Store_Information()->Ui_Store_information->tableView_4->setColumnWidth(0,50);
     Store_Information()->Ui_Store_information->tableView_4->setColumnWidth(1,70);
              //设置表格的各行高的宽度值
            Store_Information()->Ui_Store_information->tableView_4->setRowHeight(0,20);
          Store_Information()->Ui_Store_information->tableView_4->setRowHeight(1,20);
         Store_Information()->Ui_Store_information->tableView_4->setRowHeight(2,20);
          Store_Information()->Ui_Store_information->tableView_4->setRowHeight(3,20);
            Store_Information()->Ui_Store_information->tableView_4->setRowHeight(4,20);
            Store_Information()->Ui_Store_information->tableView_4->setRowHeight(5,20);
             Store_Information()->Ui_Store_information->tableView_4->setRowHeight(6,20);
           Store_Information()->Ui_Store_information->tableView_4->setRowHeight(7,20);
           Store_Information()->Ui_Store_information->tableView_4->setRowHeight(8,20);
        Store_Information()->Ui_Store_information->tableView_4->setRowHeight(9,20);

              //设置表格的各列的宽度值
            /* ui->tableView->setColumnWidth(0,60);
             ui->tableView->setColumnWidth(1,60);
             ui->tableView->setColumnWidth(2,60);
             ui->tableView->setColumnWidth(3,60);
             ui->tableView->setColumnWidth(4,60);*/
             //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
          Store_Information()->Ui_Store_information->tableView_4->verticalHeader()->hide();
         //--------------------------------------------设置列宽-----------------------------------------------------
    //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    // Store_Information()->Ui_Store_information->tableView_4->resizeColumnsToContents();
      //ui->tableView->resizeRowsToContents();

    }
    //------------------------------表格颜色---------------------------------------------------------------------------------------------------

       /*******************************************************************************
       * Function Name  :
       * Description    : 位移表格1
       * Input          : None.
       * Output         : None.
       * Return         : None.
       *******************************************************************************/
    Displacement_Store_show1::Displacement_Store_show1(QObject *parent) :
        QSqlQueryModel(parent)
    {
    }

    //更改数据显示样式
    QVariant Displacement_Store_show1::data(const QModelIndex &index, int role) const
    {

          QVariant value = QSqlQueryModel::data(index, role);
                //int i=0;

          if(Displacement_store_date.flag==0)
          {
            //  Displacement_store_date.flag=1;

         if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
         {
               //0
               //不在线 蓝
//               if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[0]==0)   //第一行
//               {
//                     Displacement_store_date.Displacement_store_date[0]=255;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
        //  0 超限红
               if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[1]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }

        //1
//               if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
//               {
//                     Displacement_store_date.Displacement_store_date[1]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[2]==2)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[2]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }

           //2
//               if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_store_date.Displacement_store_date[2]==2)   //第一行
//               {
//                   Displacement_store_date.Displacement_store_date[2]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_store_date.Displacement_store_date[3]==3)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[3]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //          //3
//               if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[3]==3)   //第一行
//               {
//                   Displacement_store_date.Displacement_store_date[3]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[4]==4)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[4]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //          //4
//               if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[4]==4)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[4]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[5]==5)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[5]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //         //5
//               if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[5]==5)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[5]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[6]==6)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[6]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //         //6
//               if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[6]==6)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[6]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[7]==7)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[7]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //       //7
//               if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[7]==7)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[7]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[8]==8)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[8]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //       //8
//               if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[8]==8)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[8]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[9]==9)   //第一行
               {
                    Displacement_store_date.Displacement_store_date[9]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
        //       else
             //  {
                  //    return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
    //           }
    //        //9
//               if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[9]==9)   //第一行
//               {
//                     Displacement_store_date.Displacement_store_date[9]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[10]==10)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[10]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
        }

    //     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
    //     {
    //           qDebug()<<Displacement_store_date.Displacement_store_date[1];
    //           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
    //           {    Displacement_store_date.Displacement_store_date[1]=0;
    //                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
    //           }
    //           else
    //           {
    //                return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
    //           }
    //     }

    }
     return value;



    }

    /*******************************************************************************
    * Function Name  :
    * Description    : 位移表格2
    * Input          : None.
    * Output         : None.
    * Return         : None.
    *******************************************************************************/
    Displacement_Store_show2::Displacement_Store_show2(QObject *parent) :
     QSqlQueryModel(parent)
    {
    }

    //更改数据显示样式
    QVariant Displacement_Store_show2::data(const QModelIndex &index, int role) const
    {
        QVariant value = QSqlQueryModel::data(index, role);
              //int i=0;

        if(Displacement_store_date.flag==0)
        {
          //  Displacement_store_date.flag=1;

       if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
       {
             //0
//             if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[10]==10)   //第一行
//             {
//                   Displacement_store_date.Displacement_store_date[10]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[11]==11)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[11]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
         //1

//             if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[11]==11)   //第一行
//             {
//                   Displacement_store_date.Displacement_store_date[11]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[12]==12)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[12]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //        //2
//             if (role == Qt::BackgroundRole && index.row()==2&& Displacement_store_date.Displacement_store_date[12]==12)   //第一行
//             {
//                 Displacement_store_date.Displacement_store_date[12]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_store_date.Displacement_store_date[13]==13)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[13]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //          //3
//             if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[13]==13)   //第一行
//             {
//                 Displacement_store_date.Displacement_store_date[13]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[14]==14)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[14]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //          //4
//             if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[14]==14)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[14]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[15]==15)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[15]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //         //5
//             if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[15]==15)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[15]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[16]==16)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[16]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //         //6
//             if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[16]==16)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[16]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[17]==17)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[17]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //       //7
//             if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[17]==17)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[17]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[18]==18)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[18]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //       //8
//             if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[18]==18)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[18]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[19]==19)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[19]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //        //9
//             if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[19]==19)   //第一行
//             {
//                   Displacement_store_date.Displacement_store_date[19]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[20]==20)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[20]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
      }
     }
    //     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
    //     {
    //           qDebug()<<Displacement_store_date.Displacement_store_date[1];
    //           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
    //           {    Displacement_store_date.Displacement_store_date[1]=0;
    //                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
    //           }
    //           else
    //           {
    //                return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
    //           }
    //     }


    return value;



    }
    //------------------------------表格颜色---------------------------------------------------------------------------------------------------

       /*******************************************************************************
       * Function Name  :
       * Description    : 位移表格1
       * Input          : None.
       * Output         : None.
       * Return         : None.
       *******************************************************************************/
    Displacement_Store_show3::Displacement_Store_show3(QObject *parent) :
        QSqlQueryModel(parent)
    {
    }

    //更改数据显示样式
    QVariant Displacement_Store_show3::data(const QModelIndex &index, int role) const
    {

          QVariant value = QSqlQueryModel::data(index, role);
                //int i=0;

          if(Displacement_store_date.flag==0)
          {
            //  Displacement_store_date.flag=1;

         if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
         {
               //0
               //不在线 蓝
//               if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
//               {
//                     Displacement_store_date.Displacement_store_date[1]=255;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               //在线  0 红
               if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[21]==21)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[21]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }

        //1
//               if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
//               {
//                     Displacement_store_date.Displacement_store_date[1]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[22]==22)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[22]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //        //2
//               if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_store_date.Displacement_store_date[2]==2)   //第一行
//               {
//                   Displacement_store_date.Displacement_store_date[2]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_store_date.Displacement_store_date[23]==23)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[23]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //          //3
//               if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[3]==3)   //第一行
//               {
//                   Displacement_store_date.Displacement_store_date[3]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[24]==24)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[24]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //          //4
//               if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[4]==4)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[4]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[25]==25)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[25]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //         //5
//               if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[5]==5)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[5]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[26]==26)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[26]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //         //6
//               if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[6]==6)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[6]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[27]==27)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[27]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //       //7
//               if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[7]==7)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[7]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[28]==28)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[28]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
    //       //8
//               if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[8]==8)   //第一行
//               {
//                    Displacement_store_date.Displacement_store_date[8]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[29]==29)   //第一行
               {
                    Displacement_store_date.Displacement_store_date[29]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
        //       else
             //  {
                  //    return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
    //           }
    //        //9
//               if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[9]==9)   //第一行
//               {
//                     Displacement_store_date.Displacement_store_date[9]=0;
//                     return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//               }
               if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[30]==30)   //第一行
               {
                     Displacement_store_date.Displacement_store_date[30]=0;
                     return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
               }
        }

    //     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
    //     {
    //           qDebug()<<Displacement_store_date.Displacement_store_date[1];
    //           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
    //           {    Displacement_store_date.Displacement_store_date[1]=0;
    //                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
    //           }
    //           else
    //           {
    //                return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
    //           }
    //     }

    }
     return value;



    }

    /*******************************************************************************
    * Function Name  :
    * Description    : 位移表格2
    * Input          : None.
    * Output         : None.
    * Return         : None.
    *******************************************************************************/
    Displacement_Store_show4::Displacement_Store_show4(QObject *parent) :
     QSqlQueryModel(parent)
    {
    }

    //更改数据显示样式
    QVariant Displacement_Store_show4::data(const QModelIndex &index, int role) const
    {
        QVariant value = QSqlQueryModel::data(index, role);
              //int i=0;

        if(Displacement_store_date.flag==0)
        {
          //  Displacement_store_date.flag=1;

       if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
       {
             //0
//             if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[]==10)   //第一行
//             {
//                   Displacement_store_date.Displacement_store_date[10]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_store_date.Displacement_store_date[31]==31)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[31]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
         //1

//             if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[11]==11)   //第一行
//             {
//                   Displacement_store_date.Displacement_store_date[11]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[32]==32)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[32]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //        //2
//             if (role == Qt::BackgroundRole && index.row()==2&& Displacement_store_date.Displacement_store_date[12]==12)   //第一行
//             {
//                 Displacement_store_date.Displacement_store_date[12]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_store_date.Displacement_store_date[33]==33)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[33]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //          //3
//             if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[13]==13)   //第一行
//             {
//                 Displacement_store_date.Displacement_store_date[13]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_store_date.Displacement_store_date[34]==34)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[13]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //          //4
//             if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[14]==14)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[14]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_store_date.Displacement_store_date[35]==35)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[35]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //         //5
//             if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[15]==15)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[15]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_store_date.Displacement_store_date[36]==36)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[36]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //         //6
//             if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[16]==16)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[16]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_store_date.Displacement_store_date[37]==37)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[37]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //       //7
//             if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[17]==17)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[17]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_store_date.Displacement_store_date[38]==38)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[38]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //       //8
//             if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[18]==18)   //第一行
//             {
//                  Displacement_store_date.Displacement_store_date[18]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_store_date.Displacement_store_date[39]==39)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[39]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
    //        //9
//             if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[19]==19)   //第一行
//             {
//                   Displacement_store_date.Displacement_store_date[19]=0;
//                   return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//             }
             if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_store_date.Displacement_store_date[40]==40)   //第一行
             {
                   Displacement_store_date.Displacement_store_date[40]=0;
                   return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
             }
      }
     }
    //     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
    //     {
    //           qDebug()<<Displacement_store_date.Displacement_store_date[1];
    //           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_store_date.Displacement_store_date[1]==1)   //第一行
    //           {    Displacement_store_date.Displacement_store_date[1]=0;
    //                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
    //           }
    //           else
    //           {
    //                return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
    //           }
    //     }


    return value;



    }
