#include "Real-time_Data.h"
#include "ui_dialog.h"
#include <QVariant>
#include <QFontDatabase>
#include "main.h"
#include "QKeyEvent"
#include "golobe.h"
#include <QSqlQuery>
#include <QColor>

//struct Realtime_Date_flag Displacement_Realtime1,Displacement_Realtime2;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    RealTimeui(new Ui::Dialog)
{
    RealTimeui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint); //去标题栏
    QString cgq_type= "01";
    char* cgq_type_name  = "顶板位移";
    RealTimeui->cgq_type_lineEdit_->setText(cgq_type);
    RealTimeui->name_lineEdit->setText(QObject::trUtf8(cgq_type_name));

}

Dialog::~Dialog()
{
    delete RealTimeui;
}
//----------------------------------------------------供上位机使用本地不显示---------------------------------------------------
/*******************************************************************************
* Function Name  :
* Description    :    //位移实时数据上位机
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
  int Dialog::Displacement_UP_RealTime(QSqlDatabase db,QString Which_Table,QString Which_Table2)
  {
       //取数据

      struct     Realtime_UPUSE_SHOW SHOW_ITEM;
      struct    Realtime_UPUSE SELECT_ITEM;  //取数
      QString shenji_temp[42],shenji_temp1[42];
                  QString cmd2="select * from Displacement_Realtime;";
                  QSqlQuery q2(cmd2,db);
                  int i=0;
                   while(q2.next())
                   {         i++;
                       //取数据
                               SELECT_ITEM.cgq_id[i]=q2.value(1).toInt();
                                //shenji_temp[i]=q2.value(2);          //判断是否在线
                                shenji_temp1[i]=q2.value(2).toString();
                                SELECT_ITEM.shenji[i]= shenji_temp1[i];
                               // shenji_temp1[i]=q2.value(2).toString();
                               SELECT_ITEM.qianji[i]=q2.value(3).toInt();
                               SELECT_ITEM.shiji[i]=q2.value(4).toString();
//                               qDebug()<<i<<SELECT_ITEM.cgq_id[i]<< SELECT_ITEM.shenji[i]<<SELECT_ITEM.qianji[i]\
//                                         << SELECT_ITEM.shiji[i];
                       //处理

                              SHOW_ITEM.cgq_id[i]= SELECT_ITEM.cgq_id[i];
                              SHOW_ITEM.shenji[i]=SELECT_ITEM.shenji[i];
                              SHOW_ITEM.qianji[i]=SELECT_ITEM.qianji[i];
                              SHOW_ITEM.A_B[i]=SELECT_ITEM.shenji[i].toInt()-SELECT_ITEM.qianji[i];

                               if(shenji_temp1[i].isEmpty())              //在线
                               {

                                    SHOW_ITEM.statue[i]="OFF LINE";
                               }
                               else                                                 //不在线
                               {
                                    SHOW_ITEM.statue[i]="ON LINE";
                               }
                              SHOW_ITEM.shiji[i]=SELECT_ITEM.shiji[i];

//                               qDebug()<<i<< SHOW_ITEM.cgq_id[i]<< SHOW_ITEM.shenji[i]<< SHOW_ITEM.qianji[i]\
//                                                            <<  SHOW_ITEM.A_B[i]<<SHOW_ITEM.statue[i]<<SHOW_ITEM.shiji[i];

                               //写入数据库


                              QString cmd_write=QString("update Displacement_Realtime_UPUSE set sensor = '%1', shenji_mm = '%2' , \
                                                                  qianji_mm = '%3', A_B = '%4',  sensor_statue = '%5' where sensor = %6 ;")\
                                                              .arg(SHOW_ITEM.cgq_id[i] ).arg( SHOW_ITEM.shenji[i]).arg( SHOW_ITEM.qianji[i]).\
                                                            arg( SHOW_ITEM.A_B[i]).arg( SHOW_ITEM.statue[i] ).\
                                                             arg(SHOW_ITEM.cgq_id[i]);

                              QString cmd_insert=QString("insert into Displacement_Realtime_UPUSE set sensor = '%1', shenji_mm = '%2' , \
                                                                  qianji_mm = '%3', A_B = '%4',  sensor_statue = '%5' ;")\
                                                              .arg(SHOW_ITEM.cgq_id[i] ).arg( SHOW_ITEM.shenji[i]).arg( SHOW_ITEM.qianji[i] ).\
                                                                  arg( SHOW_ITEM.A_B[i]).arg( SHOW_ITEM.statue[i] );


                          if(SHOW_ITEM.cgq_id[i]==i)                         //有数据更新
                          {

                              QSqlQuery  q1(cmd_write,db);
                            //   qDebug()<<i;
                          }
                          else
                          {
                                 QSqlQuery  q2(cmd_insert,db);


                          }








                   }

























      //写入


  }


//----------------------------------------------------供上位机使用本地不显示---------------------------------------------------------
/*******************************************************************************
* Function Name  : //发射信号的函数
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
  void Dialog::do_send(void)
  {
          emit send(1);
  }


/*******************************************************************************
* Function Name  : 实时数据的更新
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
   int Dialog::RealTime_Up_Date(void)      //实时数据的更新
   {
        REAL_TIME()->UPDATE_YL_RealTime_Number(SQLmain()->db_TEST);
        REAL_TIME()->Displacement_UP_RealTime(SQLmain()->db_TEST,"12","345");
   }
   /*******************************************************************************
   * Function Name  :
   * Description    : //更新在线台数
   * Input          : None.
   * Output         : None.
   * Return         : None.
   *******************************************************************************/

   int Dialog::UPDATE_YL_RealTime_Number(QSqlDatabase db)
   {
        QString data=NULL;
         int ON_LINE_NUMBER;
         int dd;
        QString ON_LINE_NUMBERnew;
      // for(int i=1;i<=20;i++)
    //   {
           QString cmd4 ="use test;";
           QString cmd5=QString("select count(1) from  Displacement_Realtime where shenji='%1';").arg(data);
            QSqlQuery  q4(cmd4,db);
            QSqlQuery  q5(cmd5,db);
            while (q5.next()) {
                   // qDebug() << q5.at();
                    ON_LINE_NUMBER=q5.value(0).toInt();
            }
                      q5.exec();
     //  }

     // qDebug() << "table name:" << ON_LINE_NUMBER ;
    // dd=20-ON_LINE_NUMBER;

      // QString string;
      ON_LINE_NUMBERnew=QString::number(20-ON_LINE_NUMBER);

     RealTimeui->Number_lineEdit->setText(ON_LINE_NUMBERnew);

//----------------------------计算是否在线---------------------------------
     QString temp[22],Null_temp[22];
      int i=0;

     QString cmd2="select * from Displacement_Realtime;";
     QSqlQuery q2(cmd2,db);
     while(q2.next())
     {

       //qDebug() << " is : " << q2.at()<<q2.value(2).toInt();
          //qDebug()<<q2.value(2).toString();

         Null_temp[i]=temp[i]=q2.value(2).toString();
           // qDebug()<<temp[i];

         //判断内容是否为空
        if(temp[i].isEmpty())
          {

                 Displacement_Realtime1.Displacement_Realtime1[i]=i;
                 Displacement_Realtime1.flag=0;
            //   qDebug()<< Displacement_Realtime1.Displacement_Realtime1[i];


          }
         else if(Null_temp[i].toInt()==0)                      //判断是否为0
        {
            Displacement_Realtime1.Displacement_Realtime1[i]=i+1;
            Displacement_Realtime1.flag=0;
                qDebug()<<i<<Displacement_Realtime1.Displacement_Realtime1[i];
        }







            i++;
}



   }
   /*******************************************************************************
   * Function Name  :
   * Description    : 按left建跳转到压力实时信息
   * Input          : None.
   * Output         : None.
   * Return         : None.
   *******************************************************************************/
   void Dialog::keyPressEvent(QKeyEvent *event)
   {
       switch (event->key())
       {
       case Qt::Key_Return:

            REAL_TIME()->close();
            front()->showFullScreen();
            front()->exec();

           break;
       case Qt::Key_Escape:                  //右键
           REAL_TIME()->hide();
           Qman()->showFullScreen();
               break;
           case Qt:: Key_Left:
             REAL_TIME()->hide();
             Realtime_presser()->showFullScreen();
             Realtime_presser()->exec();

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
          //ScreenSaver::keyPressEvent(event);
           break;
       }
   }

//------------------------------表格颜色---------------------------------------------------------------------------------------------------

   /*******************************************************************************
   * Function Name  :
   * Description    : 位移表格1
   * Input          : None.
   * Output         : None.
   * Return         : None.
   *******************************************************************************/
MySqlQueryModel::MySqlQueryModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

//更改数据显示样式
QVariant MySqlQueryModel::data(const QModelIndex &index, int role) const
{

//    QVariant value = QSqlQueryModel::data(index, role);
// if (role == Qt::BackgroundRole && index.column() == 1)  //第一列
// {
//       if (role == Qt::BackgroundRole && index.row()== 1)   //第一行
//       {
//             return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//       }
// }

// return value;
    //Displacement_Realtime1.Displacement_Realtime1[i]=i;

      QVariant value = QSqlQueryModel::data(index, role);
            //int i=0;

      if(Displacement_Realtime1.flag==0)
      {
        //  Displacement_Realtime1.flag=1;

     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
     {
           //0
           //不在线 蓝
           if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_Realtime1.Displacement_Realtime1[0]==0)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[0]=255;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           //在线  0 红
           if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_Realtime1.Displacement_Realtime1[0]==1)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[0]=255;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }

    //1
           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_Realtime1.Displacement_Realtime1[1]==1)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[1]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_Realtime1.Displacement_Realtime1[1]==2)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[1]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//        //2
           if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_Realtime1.Displacement_Realtime1[2]==2)   //第一行
           {
               Displacement_Realtime1.Displacement_Realtime1[2]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_Realtime1.Displacement_Realtime1[2]==3)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[2]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//          //3
           if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_Realtime1.Displacement_Realtime1[3]==3)   //第一行
           {
               Displacement_Realtime1.Displacement_Realtime1[3]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_Realtime1.Displacement_Realtime1[3]==4)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[3]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//          //4
           if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_Realtime1.Displacement_Realtime1[4]==4)   //第一行
           {
                Displacement_Realtime1.Displacement_Realtime1[4]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_Realtime1.Displacement_Realtime1[4]==5)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[4]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//         //5
           if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_Realtime1.Displacement_Realtime1[5]==5)   //第一行
           {
                Displacement_Realtime1.Displacement_Realtime1[5]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_Realtime1.Displacement_Realtime1[5]==6)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[5]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//         //6
           if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_Realtime1.Displacement_Realtime1[6]==6)   //第一行
           {
                Displacement_Realtime1.Displacement_Realtime1[6]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_Realtime1.Displacement_Realtime1[6]==7)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[6]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//       //7
           if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_Realtime1.Displacement_Realtime1[7]==7)   //第一行
           {
                Displacement_Realtime1.Displacement_Realtime1[7]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_Realtime1.Displacement_Realtime1[7]==8)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[7]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
//       //8
           if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_Realtime1.Displacement_Realtime1[8]==8)   //第一行
           {
                Displacement_Realtime1.Displacement_Realtime1[8]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_Realtime1.Displacement_Realtime1[8]==9)   //第一行
           {
                Displacement_Realtime1.Displacement_Realtime1[8]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
    //       else
         //  {
              //    return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
//           }
//        //9
           if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_Realtime1.Displacement_Realtime1[9]==9)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[9]=0;
                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
           }
           if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_Realtime1.Displacement_Realtime1[9]==10)   //第一行
           {
                 Displacement_Realtime1.Displacement_Realtime1[9]=0;
                 return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
           }
    }

//     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
//     {
//           qDebug()<<Displacement_Realtime1.Displacement_Realtime1[1];
//           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_Realtime1.Displacement_Realtime1[1]==1)   //第一行
//           {    Displacement_Realtime1.Displacement_Realtime1[1]=0;
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
Displacement_Realtime2_MySql::Displacement_Realtime2_MySql(QObject *parent) :
 QSqlQueryModel(parent)
{
}

//更改数据显示样式
QVariant Displacement_Realtime2_MySql::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);
          //int i=0;

    if(Displacement_Realtime1.flag==0)
    {
      //  Displacement_Realtime1.flag=1;

   if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
   {
         //0
         if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_Realtime1.Displacement_Realtime1[10]==10)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[10]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 0&& Displacement_Realtime1.Displacement_Realtime1[10]==11)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[10]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
     //1

         if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_Realtime1.Displacement_Realtime1[11]==11)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[11]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_Realtime1.Displacement_Realtime1[11]==12)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[11]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//        //2
         if (role == Qt::BackgroundRole && index.row()==2&& Displacement_Realtime1.Displacement_Realtime1[12]==12)   //第一行
         {
             Displacement_Realtime1.Displacement_Realtime1[12]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 2&& Displacement_Realtime1.Displacement_Realtime1[12]==13)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[12]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//          //3
         if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_Realtime1.Displacement_Realtime1[13]==13)   //第一行
         {
             Displacement_Realtime1.Displacement_Realtime1[13]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 3&& Displacement_Realtime1.Displacement_Realtime1[13]==14)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[13]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//          //4
         if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_Realtime1.Displacement_Realtime1[14]==14)   //第一行
         {
              Displacement_Realtime1.Displacement_Realtime1[14]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 4&& Displacement_Realtime1.Displacement_Realtime1[14]==15)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[14]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//         //5
         if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_Realtime1.Displacement_Realtime1[15]==15)   //第一行
         {
              Displacement_Realtime1.Displacement_Realtime1[15]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 5&& Displacement_Realtime1.Displacement_Realtime1[15]==16)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[15]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//         //6
         if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_Realtime1.Displacement_Realtime1[16]==16)   //第一行
         {
              Displacement_Realtime1.Displacement_Realtime1[16]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 6&& Displacement_Realtime1.Displacement_Realtime1[16]==17)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[16]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//       //7
         if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_Realtime1.Displacement_Realtime1[17]==17)   //第一行
         {
              Displacement_Realtime1.Displacement_Realtime1[17]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 7&& Displacement_Realtime1.Displacement_Realtime1[17]==18)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[17]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//       //8
         if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_Realtime1.Displacement_Realtime1[18]==18)   //第一行
         {
              Displacement_Realtime1.Displacement_Realtime1[18]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 8&& Displacement_Realtime1.Displacement_Realtime1[18]==19)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[18]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
//        //9
         if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_Realtime1.Displacement_Realtime1[19]==19)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[19]=0;
               return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
         }
         if (role == Qt::BackgroundRole && index.row()== 9&& Displacement_Realtime1.Displacement_Realtime1[19]==20)   //第一行
         {
               Displacement_Realtime1.Displacement_Realtime1[19]=0;
               return qVariantFromValue(QColor(Qt::red)); //第一个属性的字体颜色为红色
         }
  }
 }
//     if (role == Qt::BackgroundRole && index.column() == 0)  //第一列
//     {
//           qDebug()<<Displacement_Realtime1.Displacement_Realtime1[1];
//           if (role == Qt::BackgroundRole && index.row()== 1&& Displacement_Realtime1.Displacement_Realtime1[1]==1)   //第一行
//           {    Displacement_Realtime1.Displacement_Realtime1[1]=0;
//                 return qVariantFromValue(QColor(Qt::blue)); //第一个属性的字体颜色为红色
//           }
//           else
//           {
//                return qVariantFromValue(QColor(Qt::white)); //第一个属性的字体颜色为红色
//           }
//     }


return value;



}
