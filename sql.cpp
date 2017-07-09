#include "sql.h"
#include "ui_sql.h"
#include <QDebug>
#include "main.h"
#include "Real-time_Data.h"
#include "ui_dialog.h"
#include "ui_store_information.h"
#include "QKeyEvent"
#include "ui_mainwindow.h"
#include "ui_storesinformation.h"

//#include "golobe.h"
sql::sql(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sql)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint); //去标题栏

//    ui->shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
//    ui->ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器


    time = new MyThread;
   // Sub_station=new Substation;

    //connect(Sub_station, SIGNAL(Update_Signal(int )),
     //                         this, SLOT(UpdateSlot(int)));
    connect(time, SIGNAL(UpdateSignal(void)),
                               this, SLOT(UpdateSlot(void)));
   //实时数据
    connect(Qman()->ui->currentdataButton, SIGNAL(clicked()),
                               this, SLOT(UpdateSlot(void)));
  //存储信息

  connect(Total_Store_Information()->ui->roofButton, SIGNAL(clicked()),
                                      this, SLOT(UpdateSlot(void)));
  connect(Total_Store_Information()->ui->stentPressureButton, SIGNAL(clicked()),
                                       this, SLOT(UpdateSlot(void)));


    time->start();


}

sql::~sql()
{
    delete ui;
}

/*******************************************************************************
* Function Name  : 更新数据库
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void sql::UpdateSlot(void)
{


    qDebug()<<"Q WQWE";

    //位移实时信息

     SQLmain()->Show_SQL_RealTime_Date(SQLmain()->db_TEST,\
                                 "select cgq_id,shenji,qianji from  Displacement_Realtime  where cgq_id between 1 and 10 ;",\
                                 "select cgq_id,shenji,qianji from  Displacement_Realtime where cgq_id between 11 and 20;");
 //位移存储信息
     Store_Information()->Displacement_Store_Update();

    //实时数据界面更新
      REAL_TIME()->RealTime_Up_Date();

    //位移传感器历史信息
    SQLmain()->Show_SQL_Date( SQLmain()->db_TEST,"Displacement_History","Displacement_History_Show","select * from Displacement_History_Show ;","2");

       //位移历史上位机1-20
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID1_History","1");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID2_History","2");
      SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID3_History","3");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID11_History","11");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID4_History","4");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID5_History","5");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID6_History","6");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID7_History","7");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID8_History","8");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID9_History","9");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID10_History","10");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID11_History","12");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID13_History","13");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID14_History","14");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID15_History","15");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID16_History","16");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID17_History","17");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID18_History","18");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID19_History","19");
       SQLmain()->Displacement_History_UPUSE( SQLmain()->db_TEST,"Disp_ID20_History","20");


    //压力实时界面相关信息更新
     Realtime_presser()->PRESSURE_RealTime_Up_Date() ;

   //支架压力存储信息相关界面更新
      Processer_Store_Information()->Processer_StoreInformation_Up_Date();

   //位移统计更新
      WY_Statistics()->UPDATE_Statistics_Date();

    //压力统计更新
    PRESSURE_Statistics()->UPDATE_Pressure_Statistics_Date();

    //分站本机数据更新
    Substation_local()->Substation_Local_UPdate();

     //关联传感器数据更新
   // Sensor_Set()->Correlation_sensor_UPdate();

    //综合信息数据更新
    front()->Information_UPdate();
}

/*******************************************************************************
* Function Name  : 连接数据库
* Description    :成功返回1  -2 打开数据库失败 -1 无数据库
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int sql::Connect_Sql(void)
{
     /* QSqlDatabase db;
     QFile file("databasefile");
      if (file.exists())
      {
          if(QSqlDatabase::contains("qt_sql_default_connection"))
            db = QSqlDatabase::database("qt_sql_default_connection");
          else
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("databasefile");
          //打开数据库
          if(!db.open())
          {

             qDebug()<<"failed to connect"<<endl;
          return -2;
          }

      }
      else
      {

       return -1;

      }
     return 1;  */
}



/*******************************************************************************
* Function Name  : 写入数据库
* Description    :输入为Date_buffer
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int sql::Add_Date(struct CAN_NET_DATA data,QSqlDatabase db,QString Which_Table)
{

   /* QSqlQuery query(db);
     query.prepare("INSERT INTO realtime1 (id, shenji, qianji) "
                           "VALUES (:id, :shenji, :qianji)");
     query.bindValue(":id", Date_buffer[1],);
     query.bindValue(":shenji",Date_buffer[2]);
     query.bindValue(":qianji", Date_buffer[3]);
     query.exec();

  */

  //批量写入

    QSqlQuery q(db);
    q.prepare(Which_Table);


    QVariantList fz_id;
   fz_id << data.CAN_ID_CHAR[0];
    q.addBindValue(fz_id);

    QVariantList fz_type;
    fz_type<< data.CAN_ID_CHAR[1];
    q.addBindValue(fz_type);

    QVariantList cgq_type;
   cgq_type << data.CAN_ID_CHAR[2];
    q.addBindValue(cgq_type);

    QVariantList cgq_id;
   cgq_id << data.CAN_ID_CHAR[3];
    q.addBindValue(cgq_id);

    QVariantList shenji;
    shenji << data.Data[0];
    q.addBindValue(shenji);

    QVariantList qianji;
    qianji<< data.Data[1];
    q.addBindValue(qianji);

    QVariantList shiji;
   shiji<< data.Can_Time;
    q.addBindValue(shiji);
    if (!q.execBatch())
        qDebug() << q.lastError();







}
/*******************************************************************************
* Function Name  : 更新数据库
* Description    ：输入为 NewDate_buffer
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int sql::Update_Date(struct CAN_NET_DATA data,QSqlDatabase db,QString Which_Table,QString Which_Table1)
{
    //---------------------------------id1-10------------------------------------------------
                       QSqlQuery q(db);
                       q.prepare(Which_Table);
                       switch (data.CAN_ID_CHAR[3]) {
                       case 1:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                           q.bindValue(":time",data.Can_Time);
                            q.bindValue(":id",1);

                           break;
                       case 2:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",2);
                           break;
                       case 3:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",3);
                           break;
                       case 4:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",4);
                           break;
                       case 5:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",5);
                           break;
                       case 6:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",6);
                           break;
                       case 7:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",7);
                           break;
                       case 8:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",8);
                           break;
                       case 9:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",9);
                           break;
                       case 10:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",10);
                           break;
                       case 11:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",11);
                           break;
                       case 12:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",12);
                           break;
                       case 13:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",13);
                           break;
                       case 14:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",14);
                           break;
                       case 15:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",15);
                           break;
                       case 16:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",16);
                           break;
                       case 17:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",17);
                           break;
                       case 18:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",18);
                           break;
                       case 19:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                              q.bindValue(":id",19);
                           break;
                       case 20:
                           q.bindValue(":qianji",data.Data[1]);
                           q.bindValue(":shenji",data.Data[0]);
                             q.bindValue(":time",data.Can_Time);
                           q.bindValue(":id",20);
                           break;
                       default:
                           break;
                       }

                       q.exec();


}
/*******************************************************************************
* Function Name  :   //位移历史上位机
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
  int sql::Displacement_History_UPUSE(QSqlDatabase db,QString Which_Table,QString select_table)
  {
      int kk=0,ID_number;
      struct SHOW_WY_HIS   SHOW_ITEM;
      struct Select_DATA        SELECT_ITEM;  //取数

      //获取制定id的条数
                   QString cmd1=QString("select count(1) from Displacement_History where cgq_id=%1;").arg(select_table);

                    QSqlQuery  q1(cmd1,db);
                    while (q1.next())
                    {
                      //     qDebug() << " ID_number:" << q1.value(0).toInt();
                               ID_number=q1.value(0).toInt();
                    }
                    //   q1.exec();
      //获取代写入数据库 time索引的值
                    //获取数据量
                    QString cmd_time_conunt=QString("select count(1) from %1 ;").arg(Which_Table);
                     int timecount=0;
                     QSqlQuery  qtimeconut(cmd_time_conunt,db);
                     while (qtimeconut.next())
                     {
                                timecount=qtimeconut.value(0).toInt();

                     }

                   //  qDebug()<<"timecount"<<timecount;
                    //获取time信息
                    QString cmd_tme=QString("select time from %1 ;").arg(Which_Table);
                    QString time_buffer[timecount+1];
                     QSqlQuery  qtime(cmd_tme,db);
                     int time_kk=0;
                     while (qtime.next())
                     {
                                time_kk++;
                                time_buffer[time_kk]=qtime.value(0).toString();
                               // qDebug()<<  time_buffer[time_kk];
                     }


      //取10条信息
                      QString cmd2=QString("select * from Displacement_History where cgq_id=%1;").arg(select_table);
                      QSqlQuery q2(cmd2,db);
                     // qDebug()<<q2.seek( ID_number);
                       if(q2.seek( ID_number-1))
                       {

                                 //qDebug() << "rowNum is : " << q2.at() <<"time is : "<< q2.value(6).toString();
                                 for (int i=0;i<=ID_number;i++)
                                 {

                                          //     q2.previous();
                                        //   qDebug() <<  "ITEM is : " << q2.at()<<"time is : "<< q2.value(6).toString();
                                                SELECT_ITEM.fz_id[i]=q2.value(0).toInt();
                                                SELECT_ITEM.fz_type[i]=q2.value(1).toInt();
                                                SELECT_ITEM.cgq_type[i]=q2.value(2).toInt();
                                                SELECT_ITEM.cgq_id[i]=q2.value(3).toInt();
                                                SELECT_ITEM.shenji[i]=q2.value(4).toInt();
                                                SELECT_ITEM.qianji[i]=q2.value(5).toInt();
                                                SELECT_ITEM.shiji[i]=q2.value(6).toString();
                                                  q2.previous();


//                                       qDebug()<< SELECT_ITEM.fz_id[i]<< SELECT_ITEM.fz_type[i]<<SELECT_ITEM.cgq_type[i]\
//                                                  << SELECT_ITEM.cgq_id[i]<<SELECT_ITEM.shenji[i]<<SELECT_ITEM.qianji[i];

                               }


                   }
 // qDebug()<<"history";
      //进行计算
          for(int d=0;d<ID_number;d++)
          {
                SHOW_ITEM.Time[d]=SELECT_ITEM.shiji[d];
  //---------------------------------------序号-------------------------------------------
                 SHOW_ITEM.id[d]= SELECT_ITEM.cgq_id[d];
  //-------------------------------------ITEM1---------------------------------------------
                  SHOW_ITEM.ITEM1[d]= SELECT_ITEM.shenji[d];
                   //qDebug() <<  "ITEM1: " <<   SHOW_ITEM.ITEM1[d];
  //--------------------------------------ITEM2--------------------------------------------
                  SHOW_ITEM.ITEM2[d]= SELECT_ITEM.qianji[d];
                  //     qDebug() <<  "ITEM2: " <<  SHOW_ITEM.ITEM2[d];
  //-------------------------------------reduce--------------------------------------------
                  SHOW_ITEM.reduce[d]=(SELECT_ITEM.shenji[d]-SELECT_ITEM.qianji[d]);
                // qDebug() <<  "reduce: " <<  SHOW_ITEM.reduce[d];
  //------------------------------------ SHOW_ITEM.Calculation1---------------------------------------------

                  //计算时间
                             QString temp_hour[11],timp_minute[11],temp[11],temp1[11],temp2[11];
                             QString  temp_day[11],temp3[11],temp4[11],temp5[11],temp6[11]; //天数
                              float  hour[11],minute[11],day[11],total_minute[11];
                              //TN
                                    temp4[d]=SELECT_ITEM.shiji[d];                           //天数
                               //      qDebug()<< SELECT_ITEM.shiji[d]<<SELECT_ITEM.shiji[d+1];
                                    temp[d]=SELECT_ITEM.shiji[d].remove(0,9);
                                    temp1[d]= temp[d];
                                //    qDebug()<<"temp1"<<temp1[d];
                                   temp_hour[d]=temp[d].remove(2,4);//
                                //   qDebug()<<" temp_hour[d]"<< temp_hour[d];
                                   timp_minute[d]=temp1[d].remove(0,3);//
                                //   qDebug()<<"timp_minute[d]"<<timp_minute[d];
                                   hour[d]= temp_hour[d].toInt();
                                   minute[d]= timp_minute[d].toInt();


                                     //天数
                                      //     qDebug()<< temp4[d];
                                        temp3[d]=temp4[d].remove(0,7);
                                         //    qDebug()<< temp3[d];
                                        temp_day[d]=temp3[d].remove(1,6);
                                        day[d]=temp_day[d].toInt();
                                        //qDebug()<<;
                                 //      qDebug()<< day[d]<< hour[d]<< minute[d];

                                        //TN+1
                                  temp5[d+1]=SELECT_ITEM.shiji[d+1];               //天
                                  temp2[d+1]=SELECT_ITEM.shiji[d+1];
                                  temp[d+1]=temp2[d+1].remove(0,9);
                                  temp1[d+1]= temp[d+1];
                                  temp_hour[d+1]=temp[d+1].remove(2,4);//
                                  timp_minute[d+1]=temp1[d+1].remove(0,3);//
                                  hour[d+1]= temp_hour[d+1].toInt();
                                  minute[d+1]= timp_minute[d+1].toInt();
                             //   qDebug()<<"d+1"<< hour[d+1] <<minute[d+1];

                                //天
                                 temp6[d+1]=temp5[d+1].remove(0,7);
                                 temp_day[d+1]=temp6[d+1].remove(1,6);
                                 day[d+1]=  temp_day[d+1].toInt();
                              //   qDebug()<<"d+1"<< day[d+1]<< hour[d+1]<< minute[d+1];


                                //对时间进行判断
                                // qDebug()<<day[d]<<day[d+1];
                                if(day[d]== day[d+1])  //同一天的数据
                                {
                                       if( hour[d+1]==hour[d])//同一时段的数据
                                        {
                                              if((minute[d]-minute[d+1])==0)   //同一分钟的数据
                                              {
                                                    total_minute[d]=1;
                                              }
                                              else                                              //不是同一分钟的数据
                                              {
                                                 total_minute[d]=minute[d]-minute[d+1];

                                              }


                                        }
                                       else     //不是同一时段的数据
                                       {
                                             total_minute[d]=(hour[d]*60+minute[d])- (hour[d+1]*60+minute[d+1]);

                                        }


                                }
        //差一天的数据-------------------------------------------------------------------------------------------------------------------
                                 if((day[d]-day[d+1])==1)
                                 {

                                     if( hour[d+1]==hour[d])//同一时段的数据
                                      {
                                            if((minute[d]-minute[d+1])==0)   //同一分钟的数据
                                            {
                                                  total_minute[d]=1440;
                                            }
                                            else                                              //不是同一分钟的数据
                                            {
                                                 total_minute[d]=1440+minute[d]-minute[d+1];

                                            }


                                      }
                                     else     //不是同一时段的数据
                                     {
                                           total_minute[d]=1440+(hour[d]*60+minute[d])- (hour[d+1]*60+minute[d+1]);

                                      }

                                 }
                 //-------------------------------------------day+1 不存在--------------------------------------------------------------------------------
                                 if(day[d+1]==0)
                                 {
                                      goto NO_DATA;
                                  }







                        //         qDebug()<<"minute: "<< total_minute[d];


                 SHOW_ITEM.Calculation1[d]=(SELECT_ITEM.shenji[d]-SELECT_ITEM.shenji[d+1]) /total_minute[d];
                 SHOW_ITEM.Calculation2[d]=(SELECT_ITEM.qianji[d]-SELECT_ITEM.qianji[d+1]) /total_minute[d];

//                                      qDebug()<<(d+1)<<SHOW_ITEM.ITEM1[d]<<SHOW_ITEM.ITEM2[d]\
//                                      <<SHOW_ITEM.reduce[d]<<SHOW_ITEM.Calculation1[d] \
//                                        <<SHOW_ITEM.Calculation2[d]<<SHOW_ITEM.Time[d];

         //写入数据库
               //进行判断 重复则更新
                 //插入语句
                 QString cmd_write=QString("insert into %1 set time = '%2', sensor_id = '%3' , shenji = '%4',  qianji = '%5',  A_B = '%6', AN_AN = '%7', BN_BN = '%8' ;")\
                                                                 .arg(Which_Table).arg(SHOW_ITEM.Time[d]).arg(SHOW_ITEM.id[d]).\
                                                                   arg(SHOW_ITEM.ITEM1[d]).arg(SHOW_ITEM.ITEM2[d]).\
                                                                 arg(SHOW_ITEM.reduce[d]).arg(SHOW_ITEM.Calculation1[d] ).\
                                                                   arg(SHOW_ITEM.Calculation2[d]);
                 //更新语句

                 QString cmd_update=QString("update %1 set time = '%2', sensor_id = '%3' , shenji = '%4',  qianji = '%5',  A_B = '%6', AN_AN = '%7', BN_BN = '%8' where time = '%9' ;")\
                                                                 .arg(Which_Table).arg(SHOW_ITEM.Time[d]).arg(SHOW_ITEM.id[d]).\
                                                                   arg(SHOW_ITEM.ITEM1[d]).arg(SHOW_ITEM.ITEM2[d]).\
                                                                 arg(SHOW_ITEM.reduce[d]).arg(SHOW_ITEM.Calculation1[d] ).\
                                                                   arg(SHOW_ITEM.Calculation2[d]).arg(SHOW_ITEM.Time[d]);
                 //更新语句
                   for(int mm=1;mm<timecount;mm++)
                     {        //  qDebug()<<SHOW_ITEM.Time[d]<<time_buffer[mm];
                            if( QString::compare(SHOW_ITEM.Time[d],time_buffer[mm])==0)
                              {
                                //数据库存在更新
                               //  qDebug()<<"equal";
                                  QSqlQuery  qupdate(cmd_update,db);
                            }
                            else //数据库不存在插入
                            {


                                  QSqlQuery  q5(cmd_write,db);
                            }

                       }
                   //无数据则插入
                       if(timecount==0)
                       {
                             QSqlQuery  q5(cmd_write,db);
                       }



   }

NO_DATA:
qDebug()<<"123123";

  }

/*******************************************************************************
* Function Name  : 分站显示的位移传感器历史数据
* Description    :    QString select_table 传感器类型
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int sql::Show_SQL_Date(QSqlDatabase db,QString Which_Table,QString output_table,QString Show_table,QString select_table)
{





        int ID_number;
        struct SHOW_WY_HIS   SHOW_ITEM;
        struct Select_DATA        SELECT_ITEM;  //取数
    //获取制定id的条数
                 QString cmd1=QString("select count(1) from %1 where cgq_id=%2;").arg(Which_Table).arg(select_table);

                  QSqlQuery  q1(cmd1,db);
                  while (q1.next())
                  {
//                         qDebug() << " ID_number:" << q1.value(0).toInt();
                             ID_number=q1.value(0).toInt();
                  }
                      ui->id->setText(select_table);
                      ui->number->setText(QString::number(ID_number));

    //取10条信息
                    QString cmd2=QString("select * from %1 where cgq_id=%2;").arg(Which_Table).arg(select_table);
                    QSqlQuery q2(cmd2,db);
                   // qDebug()<<q2.seek( ID_number);
                     if(q2.seek( ID_number-1))
                     {

                               //qDebug() << "rowNum is : " << q2.at() <<"time is : "<< q2.value(6).toString();
                               for (int i=0;i<=10;i++)
                               {

                                        //     q2.previous();
                                      //   qDebug() <<  "ITEM is : " << q2.at()<<"time is : "<< q2.value(6).toString();
                                              SELECT_ITEM.fz_id[i]=q2.value(0).toInt();
                                              SELECT_ITEM.fz_type[i]=q2.value(1).toInt();
                                              SELECT_ITEM.cgq_type[i]=q2.value(2).toInt();
                                              SELECT_ITEM.cgq_id[i]=q2.value(3).toInt();
                                              SELECT_ITEM.shenji[i]=q2.value(4).toInt();
                                              SELECT_ITEM.qianji[i]=q2.value(5).toInt();
                                              SELECT_ITEM.shiji[i]=q2.value(6).toString();
                                                q2.previous();


//                                     qDebug()<< SELECT_ITEM.fz_id[i]<< SELECT_ITEM.fz_type[i]<<SELECT_ITEM.cgq_type[i]\
//                                                << SELECT_ITEM.cgq_id[i]<<SELECT_ITEM.shenji[i]<<SELECT_ITEM.qianji[i];

                             }


                 }
//qDebug()<<"history";
    //进行计算
        for(int d=0;d<10;d++)
        {
              SHOW_ITEM.Time[d]=SELECT_ITEM.shiji[d];
//---------------------------------------序号-------------------------------------------
               SHOW_ITEM.id[d]= SELECT_ITEM.cgq_id[d];
//-------------------------------------ITEM1---------------------------------------------
                SHOW_ITEM.ITEM1[d]= SELECT_ITEM.shenji[d];
                 //qDebug() <<  "ITEM1: " <<   SHOW_ITEM.ITEM1[d];
//--------------------------------------ITEM2--------------------------------------------
                SHOW_ITEM.ITEM2[d]= SELECT_ITEM.qianji[d];
                //     qDebug() <<  "ITEM2: " <<  SHOW_ITEM.ITEM2[d];
//-------------------------------------reduce--------------------------------------------
                SHOW_ITEM.reduce[d]=(SELECT_ITEM.shenji[d]-SELECT_ITEM.qianji[d]);
              // qDebug() <<  "reduce: " <<  SHOW_ITEM.reduce[d];
//------------------------------------ SHOW_ITEM.Calculation1---------------------------------------------

                //计算时间
                           QString temp_hour[11],timp_minute[11],temp[11],temp1[11],temp2[11];
                           QString  temp_day[11],temp3[11],temp4[11],temp5[11],temp6[11]; //天数
                            float  hour[11],minute[11],day[11],total_minute[11];
                            //TN
                                  temp4[d]=SELECT_ITEM.shiji[d];                           //天数
                             //      qDebug()<< SELECT_ITEM.shiji[d]<<SELECT_ITEM.shiji[d+1];
                                  temp[d]=SELECT_ITEM.shiji[d].remove(0,9);
                                  temp1[d]= temp[d];
                              //    qDebug()<<"temp1"<<temp1[d];
                                 temp_hour[d]=temp[d].remove(2,4);//
                              //   qDebug()<<" temp_hour[d]"<< temp_hour[d];
                                 timp_minute[d]=temp1[d].remove(0,3);//
                              //   qDebug()<<"timp_minute[d]"<<timp_minute[d];
                                 hour[d]= temp_hour[d].toInt();
                                 minute[d]= timp_minute[d].toInt();


                                   //天数
                                    //     qDebug()<< temp4[d];
                                      temp3[d]=temp4[d].remove(0,7);
                                       //    qDebug()<< temp3[d];
                                      temp_day[d]=temp3[d].remove(1,6);
                                      day[d]=temp_day[d].toInt();
                                      //qDebug()<<;
                                    // qDebug()<< day[d]<< hour[d]<< minute[d];

                                      //TN+1
                                temp5[d+1]=SELECT_ITEM.shiji[d+1];               //天
                                temp2[d+1]=SELECT_ITEM.shiji[d+1];
                                temp[d+1]=temp2[d+1].remove(0,9);
                                temp1[d+1]= temp[d+1];
                                temp_hour[d+1]=temp[d+1].remove(2,4);//
                                timp_minute[d+1]=temp1[d+1].remove(0,3);//
                                hour[d+1]= temp_hour[d+1].toInt();
                                minute[d+1]= timp_minute[d+1].toInt();
                           //   qDebug()<<"d+1"<< hour[d+1] <<minute[d+1];

                              //天
                               temp6[d+1]=temp5[d+1].remove(0,7);
                               temp_day[d+1]=temp6[d+1].remove(1,6);
                               day[d+1]=  temp_day[d+1].toInt();
                            //   qDebug()<<"d+1"<< day[d+1]<< hour[d+1]<< minute[d+1];


                              //对时间进行判断
                              // qDebug()<<day[d]<<day[d+1];
                              if(day[d]== day[d+1])  //同一天的数据
                              {
                                     if( hour[d+1]==hour[d])//同一时段的数据
                                      {
                                            if((minute[d]-minute[d+1])==0)   //同一分钟的数据
                                            {
                                                  total_minute[d]=1;
                                            }
                                            else                                              //不是同一分钟的数据
                                            {
                                               total_minute[d]=minute[d]-minute[d+1];

                                            }


                                      }
                                     else     //不是同一时段的数据
                                     {
                                           total_minute[d]=(hour[d]*60+minute[d])- (hour[d+1]*60+minute[d+1]);

                                      }


                              }
      //差一天的数据-------------------------------------------------------------------------------------------------------------------
                               if((day[d]-day[d+1])==1)
                               {

                                   if( hour[d+1]==hour[d])//同一时段的数据
                                    {
                                          if((minute[d]-minute[d+1])==0)   //同一分钟的数据
                                          {
                                                total_minute[d]=1440;
                                          }
                                          else                                              //不是同一分钟的数据
                                          {
                                               total_minute[d]=1440+minute[d]-minute[d+1];

                                          }


                                    }
                                   else     //不是同一时段的数据
                                   {
                                         total_minute[d]=1440+(hour[d]*60+minute[d])- (hour[d+1]*60+minute[d+1]);

                                    }

                               }
               //-------------------------------------------day+1 不存在--------------------------------------------------------------------------------
                               if(day[d+1]==0)
                               {

                                    goto NO_DATA;
                                }







                            //   qDebug()<<"minute: "<< total_minute[d];


               SHOW_ITEM.Calculation1[d]=(SELECT_ITEM.shenji[d]-SELECT_ITEM.shenji[d+1]) /total_minute[d];
               SHOW_ITEM.Calculation2[d]=(SELECT_ITEM.qianji[d]-SELECT_ITEM.qianji[d+1]) /total_minute[d];

//                                    qDebug()<<(d+1)<<SHOW_ITEM.ITEM1[d]<<SHOW_ITEM.ITEM2[d]\
//                                    <<SHOW_ITEM.reduce[d]<<SHOW_ITEM.Calculation1[d] \
//                                      <<SHOW_ITEM.Calculation2[d]<<SHOW_ITEM.Time[d];

                //写入数据库

            QString cmd="use test";
            QString cmd_write=QString("update %1 set SHENJI = '%2', QIANJI = '%3' , AB = '%4',  ANAN = '%5',  BNBN = '%6', TIME = '%7'  where ID = %8 ;")\
                                            .arg(output_table).arg(SHOW_ITEM.ITEM1[d] ).arg(SHOW_ITEM.ITEM2[d]).arg(SHOW_ITEM.reduce[d] ).\
                                          arg(SHOW_ITEM.Calculation1[d]).arg(SHOW_ITEM.Calculation2[d] ).\
                                           arg(SHOW_ITEM.Time[d]).arg((d+1));
          // qDebug()<<d;
           QSqlQuery  q4(cmd,db);
            QSqlQuery  q5(cmd_write,db);


        }
        NO_DATA:
//qDebug()<<"history";
    //显示
      //  qDebug()<<"show";
        QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
          model->setQuery(Show_table,db);

       //  qDebug()<<model->record(1);
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("序号\n n"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("深基\n A\n (mm)"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("深基\n B\n (mm)"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("A-B\n (mm)"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("(An-An+1)/\n (Tn-Tn+1)\n (mm/min)"));
          model->setHeaderData(5,Qt::Horizontal,QObject::tr("(Bn-Bn+1)/\n (Tn-Tn+1)\n (mm/min)"));
          model->setHeaderData(6,Qt::Horizontal,QObject::tr("时间T"));
          //获取表格中的数据条数


          ui->tableView->setModel(model);
          //------------------------------------------设置颜色-------------------------------------------------------
         ui->tableView->setAlternatingRowColors( true );
         ui->tableView->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
              //                                            // "alternate-background-color: rgb(141, 163, 215);}"
            //--------------------------------------------设置颜色-----------------------------------------------------

            //--------------------------------------------设置列宽-----------------------------------------------------
           // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
           //  ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
           //  ui->tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
          //   ui->tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
                 //设置表格的各行高的宽度值
                ui->tableView->setRowHeight(0,20);
                 ui->tableView->setRowHeight(1,20);
                 ui->tableView->setRowHeight(2,20);
                 ui->tableView->setRowHeight(3,20);
                 ui->tableView->setRowHeight(4,20);
                 ui->tableView->setRowHeight(5,20);
                 ui->tableView->setRowHeight(6,20);
                 ui->tableView->setRowHeight(7,20);
                 ui->tableView->setRowHeight(8,20);
                 ui->tableView->setRowHeight(9,20);

                 //设置表格的各列的宽度值
                ui->tableView->setColumnWidth(0,30);
                ui->tableView->setColumnWidth(1,40);
                ui->tableView->setColumnWidth(2,40);
                ui->tableView->setColumnWidth(3,40);
                ui->tableView->setColumnWidth(4,85);
                  ui->tableView->setColumnWidth(5,85);
                 ui->tableView->setColumnWidth(6,140);
                //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
               ui->tableView->verticalHeader()->hide();
            //--------------------------------------------设置列宽-----------------------------------------------------
       //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
         //  ui->tableView->resizeColumnsToContents();
         //ui->tableView->resizeRowsToContents();














//------------------------------  位移历史数据显示备份----------------------------------------------------
//    QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
//      model->setQuery(Which_Table,db);

//   //  qDebug()<<model->record(1);
//      model->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));
//      model->setHeaderData(1,Qt::Horizontal,QObject::tr("深基mm"));
//      model->setHeaderData(2,Qt::Horizontal,QObject::tr("浅基mm"));
//      model->setHeaderData(3,Qt::Horizontal,QObject::tr("时间"));
//      //获取表格中的数据条数
//      qDebug()<<model->rowCount();

//      ui->tableView->setModel(model);
//      //------------------------------------------设置颜色-------------------------------------------------------
//     ui->tableView->setAlternatingRowColors( true );
//     ui->tableView->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
//          //                                            // "alternate-background-color: rgb(141, 163, 215);}"
//        //--------------------------------------------设置颜色-----------------------------------------------------

//        //--------------------------------------------设置列宽-----------------------------------------------------
//       // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
//       //  ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
//       //  ui->tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
//      //   ui->tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
//             //设置表格的各行高的宽度值
//            ui->tableView->setRowHeight(0,20);
//             ui->tableView->setRowHeight(1,20);
//             ui->tableView->setRowHeight(2,20);
//             ui->tableView->setRowHeight(3,20);
//             ui->tableView->setRowHeight(4,20);
//             ui->tableView->setRowHeight(5,20);
//             ui->tableView->setRowHeight(6,20);
//             ui->tableView->setRowHeight(7,20);
//             ui->tableView->setRowHeight(8,20);
//             ui->tableView->setRowHeight(9,20);

//             //设置表格的各列的宽度值
//           /* ui->tableView->setColumnWidth(0,60);
//            ui->tableView->setColumnWidth(1,60);
//            ui->tableView->setColumnWidth(2,60);
//            ui->tableView->setColumnWidth(3,60);
//            ui->tableView->setColumnWidth(4,60);*/
//            //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
//           ui->tableView->verticalHeader()->hide();
//        //--------------------------------------------设置列宽-----------------------------------------------------
//   //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//    ui->tableView->resizeColumnsToContents();
//     //ui->tableView->resizeRowsToContents();
}
//}

///*******************************************************************************
//* Function Name  : ; 显示数据存储容量
//* Description    :
//* Input          : None.
//* Output         : None.
//* Return         : None.
//*******************************************************************************/

//   int sql::Show_SQL_Data_Capacity(QSqlDatabase db,QString Which_Table10,QString Which_Table20\
//                                                                                          ,QString Which_Table30,QString Which_Table40 )
//{
//        QString total_capacity,total_number;
//        float select_capacity[41],select_number[41];
//        QString capacity[41];
//       //-----1-----------------------------计算表中总容量-------------------------------------------------------
//            //计算表所占的总信息量
//            QString cmd1 ="use information_schema";
//            QString cmd2="select concat(round(sum(data_length/1024),2),'KB')\
//                                    as data from tables where table_schema='test' and table_name='Displacement_History' ;";
//            QSqlQuery       q1(cmd1,db);
//            QSqlQuery        q2(cmd2,db);

//          while (q2.next()) {
//           //   qDebug() << "table name:" << q2.value(0).toString().remove("KB");
//               total_capacity=q2.value(0).toString().remove("KB");
//            }

//           q1.exec();
//            q2.exec();


//          //计算表中信息的条数
//             QString cmd4 ="use test";
//             QString cmd3="select count(1) from Displacement_History;";
//             QSqlQuery   q4(cmd4,db);
//              QSqlQuery  q3(cmd3,db);
//            while (q3.next()) {
//                  // qDebug() << "table name:" << q3.value(0).toString();
//                         total_number=q3.value(0).toString();
//               }
//                   q3.exec();
//                   q4.exec();


//     //-----2-----------------------------获取指定id的信息量-------------------------------------------------------


//             for(int i=1;i<=40;i++)
//             {
//                 QString cmd5=QString("select count(1) from Displacement_History where cgq_id=%1;").arg(i);
//                 //      qDebug() << cmd5;
//                  QSqlQuery  q5(cmd5,db);
//                  while (q5.next()) {
//            //              qDebug() << "table name:" << q5.value(0).toString();
//                            select_number[i]=q5.value(0).toFloat();
//                  }
//                     q5.exec();
//             }

//        //-----3-----------------------------计算制定id所占的容量-------------------------------------------------------



//             for(int d=1;d<=40;d++)
//             {
//                   //    qDebug()<<d;
//                        select_capacity[d]=(total_capacity.toFloat()/total_number.toFloat())*select_number[d];
//                        capacity[d]=QString::number( select_capacity[d], 'f', 1);
//                   //      qDebug()<< capacity[d];
//                       // capacity[d]= QString("%1").arg(select_capacity[d]);


//             }


//          //-----4-----------------------------写入数据库-------------------------------------------------------
//             for(int cc=1;cc<=40;cc++)
//             {

//                  QString cmd_write=QString("update Displacement_Store set store = '%1' where id = %2;").arg( capacity[cc]+" KB").arg(cc);
//                 //   qDebug()<<cmd_write;
//                   QSqlQuery   q4(cmd4,db);
//                   QSqlQuery  q5(cmd_write,db);
//            }

//            memset(select_capacity,0,41*sizeof(int));  //清空




//        //-----5-----------------------------显示-------------------------------------------------------
//           //-----------------------id 10------------------------------------------
//            QSqlQueryModel *model10= new QSqlQueryModel( Store_Information()->Ui_Store_information->tableView_10);
//            model10->setQuery(Which_Table10,db);
//            model10->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
//            model10->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
//            Store_Information()->Ui_Store_information->tableView_10->setModel(model10);

//            //------------------------------------------设置颜色-------------------------------------------------------
//        Store_Information()->Ui_Store_information->tableView_10->setAlternatingRowColors( true );
//         Store_Information()->Ui_Store_information->tableView_10->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
//                //                                            // "alternate-background-color: rgb(141, 163, 215);}"
//              //--------------------------------------------设置颜色-----------------------------------------------------

//              //--------------------------------------------设置列宽-----------------------------------------------------
//            Store_Information()->Ui_Store_information->tableView_10->setColumnWidth(0,50);
//             Store_Information()->Ui_Store_information->tableView_10->setColumnWidth(1,70);
//                   //设置表格的各行高的宽度值
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(0,20);
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(1,20);
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(2,20);
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(3,20);
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(4,20);
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(5,20);
//                  Store_Information()->Ui_Store_information->tableView_10->setRowHeight(6,20);
//                 Store_Information()->Ui_Store_information->tableView_10->setRowHeight(7,20);
//                 Store_Information()->Ui_Store_information->tableView_10->setRowHeight(8,20);
//                 Store_Information()->Ui_Store_information->tableView_10->setRowHeight(9,20);

//                   //设置表格的各列的宽度值
//                 /* ui->tableView->setColumnWidth(0,60);
//                  ui->tableView->setColumnWidth(1,60);
//                  ui->tableView->setColumnWidth(2,60);
//                  ui->tableView->setColumnWidth(3,60);
//                  ui->tableView->setColumnWidth(4,60);*/
//                  //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
//               Store_Information()->Ui_Store_information->tableView_10->verticalHeader()->hide();
//              //--------------------------------------------设置列宽-----------------------------------------------------
//         //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//         // Store_Information()->Ui_Store_information->tableView_10->resizeColumnsToContents();
//           //ui->tableView->resizeRowsToContents();


//                //-----------------------id 20------------------------------------------
//          QSqlQueryModel *model20= new QSqlQueryModel(Store_Information()->Ui_Store_information->tableView_20);
//         model20->setQuery(Which_Table20,db);
//         model20->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
//        model20->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
//         Store_Information()->Ui_Store_information->tableView_20->setModel(model20);

//         //  ui->tableView->
//          //------------------------------------------设置颜色-------------------------------------------------------
//       Store_Information()->Ui_Store_information->tableView_20->setAlternatingRowColors( true );
//       Store_Information()->Ui_Store_information->tableView_20->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
//              //                                            // "alternate-background-color: rgb(141, 163, 215);}"
//            //--------------------------------------------设置颜色-----------------------------------------------------

//            //--------------------------------------------设置列宽-----------------------------------------------------
//       Store_Information()->Ui_Store_information->tableView_20->setColumnWidth(0,50);
//       Store_Information()->Ui_Store_information->tableView_20->setColumnWidth(1,70);
//                 //设置表格的各行高的宽度值
//              Store_Information()->Ui_Store_information->tableView_20->setRowHeight(0,20);
//              Store_Information()->Ui_Store_information->tableView_20->setRowHeight(1,20);
//              Store_Information()->Ui_Store_information->tableView_20->setRowHeight(2,20);
//               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(3,20);
//                 Store_Information()->Ui_Store_information->tableView_20->setRowHeight(4,20);
//                Store_Information()->Ui_Store_information->tableView_20->setRowHeight(5,20);
//               Store_Information()->Ui_Store_information->tableView_20->setRowHeight(6,20);
//              Store_Information()->Ui_Store_information->tableView_20->setRowHeight(7,20);
//              Store_Information()->Ui_Store_information->tableView_20->setRowHeight(8,20);
//             Store_Information()->Ui_Store_information->tableView_20->setRowHeight(9,20);

//                 //设置表格的各列的宽度值
//               /* ui->tableView->setColumnWidth(0,60);
//                ui->tableView->setColumnWidth(1,60);
//                ui->tableView->setColumnWidth(2,60);
//                ui->tableView->setColumnWidth(3,60);
//                ui->tableView->setColumnWidth(4,60);*/
//                //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
//              Store_Information()->Ui_Store_information->tableView_20->verticalHeader()->hide();
//            //--------------------------------------------设置列宽-----------------------------------------------------
//       //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//      // Store_Information()->Ui_Store_information->tableView_20->resizeColumnsToContents();
//         //ui->tableView->resizeRowsToContents();


//              //-----------------------id 30------------------------------------------
//        QSqlQueryModel *model30= new QSqlQueryModel(Store_Information()->Ui_Store_information->tableView_30);
//        model30->setQuery(Which_Table30,db);
//        model30->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
//       model30->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
//      Store_Information()->Ui_Store_information->tableView_30->setModel(model30);

//       //  ui->tableView->
//        //------------------------------------------设置颜色-------------------------------------------------------
//      Store_Information()->Ui_Store_information->tableView_30->setAlternatingRowColors( true );
//     Store_Information()->Ui_Store_information->tableView_30->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
//            //                                            // "alternate-background-color: rgb(141, 163, 215);}"
//          //--------------------------------------------设置颜色-----------------------------------------------------

//          //--------------------------------------------设置列宽-----------------------------------------------------
//     Store_Information()->Ui_Store_information->tableView_30->setColumnWidth(0,50);
//      Store_Information()->Ui_Store_information->tableView_30->setColumnWidth(1,70);
//               //设置表格的各行高的宽度值
//            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(0,20);
//            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(1,20);
//            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(2,20);
//             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(3,20);
//             Store_Information()->Ui_Store_information->tableView_30->setRowHeight(4,20);
//            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(5,20);
//          Store_Information()->Ui_Store_information->tableView_30->setRowHeight(6,20);
//           Store_Information()->Ui_Store_information->tableView_30->setRowHeight(7,20);
//            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(8,20);
//            Store_Information()->Ui_Store_information->tableView_30->setRowHeight(9,20);

//               //设置表格的各列的宽度值
//             /* ui->tableView->setColumnWidth(0,60);
//              ui->tableView->setColumnWidth(1,60);
//              ui->tableView->setColumnWidth(2,60);
//              ui->tableView->setColumnWidth(3,60);
//              ui->tableView->setColumnWidth(4,60);*/
//              //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
//           Store_Information()->Ui_Store_information->tableView_30->verticalHeader()->hide();
//          //--------------------------------------------设置列宽-----------------------------------------------------
//     //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//   //  Store_Information()->Ui_Store_information->tableView_30->resizeColumnsToContents();
//       //ui->tableView->resizeRowsToContents();


//                //-----------------------id 40------------------------------------------
//      QSqlQueryModel *model40= new QSqlQueryModel(Store_Information()->Ui_Store_information->tableView_4);
//     model40->setQuery(Which_Table40,db);
//     model40->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
//     model40->setHeaderData(1,Qt::Horizontal,QObject::tr("容量"));
//     Store_Information()->Ui_Store_information->tableView_4->setModel(model40);


//      //------------------------------------------设置颜色-------------------------------------------------------
//    Store_Information()->Ui_Store_information->tableView_4->setAlternatingRowColors( true );
//   Store_Information()->Ui_Store_information->tableView_4->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
//          //                                            // "alternate-background-color: rgb(141, 163, 215);}"
//        //--------------------------------------------设置颜色-----------------------------------------------------

//        //--------------------------------------------设置列宽-----------------------------------------------------
//   Store_Information()->Ui_Store_information->tableView_4->setColumnWidth(0,50);
//    Store_Information()->Ui_Store_information->tableView_4->setColumnWidth(1,70);
//             //设置表格的各行高的宽度值
//           Store_Information()->Ui_Store_information->tableView_4->setRowHeight(0,20);
//         Store_Information()->Ui_Store_information->tableView_4->setRowHeight(1,20);
//        Store_Information()->Ui_Store_information->tableView_4->setRowHeight(2,20);
//         Store_Information()->Ui_Store_information->tableView_4->setRowHeight(3,20);
//           Store_Information()->Ui_Store_information->tableView_4->setRowHeight(4,20);
//           Store_Information()->Ui_Store_information->tableView_4->setRowHeight(5,20);
//            Store_Information()->Ui_Store_information->tableView_4->setRowHeight(6,20);
//          Store_Information()->Ui_Store_information->tableView_4->setRowHeight(7,20);
//          Store_Information()->Ui_Store_information->tableView_4->setRowHeight(8,20);
//       Store_Information()->Ui_Store_information->tableView_4->setRowHeight(9,20);

//             //设置表格的各列的宽度值
//           /* ui->tableView->setColumnWidth(0,60);
//            ui->tableView->setColumnWidth(1,60);
//            ui->tableView->setColumnWidth(2,60);
//            ui->tableView->setColumnWidth(3,60);
//            ui->tableView->setColumnWidth(4,60);*/
//            //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
//         Store_Information()->Ui_Store_information->tableView_4->verticalHeader()->hide();
//        //--------------------------------------------设置列宽-----------------------------------------------------
//   //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
//   // Store_Information()->Ui_Store_information->tableView_4->resizeColumnsToContents();
//     //ui->tableView->resizeRowsToContents();

//   }
/*******************************************************************************
* Function Name  : 显示当前数据库的数据
* Description    :    Which_Table id 1~10    Which_Table2 id 10~20
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
 int sql::Show_SQL_RealTime_Date(QSqlDatabase db,QString Which_Table,QString Which_Table2)
{
   //-----------------------------------id 1~10--------------------------------------------------------------------------------
     //QSqlQueryModel *model= new QSqlQueryModel(REAL_TIME()->RealTimeui->tableView);
     MySqlQueryModel * model = new MySqlQueryModel(REAL_TIME()->RealTimeui->tableView); //创建自己模型的对象
     model->setQuery(Which_Table,db);
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("深基mm"));

    model->setHeaderData(2,Qt::Horizontal,QObject::tr("浅基mm"));
   // model->setHeaderData(3,Qt::Horizontal,QObject::tr("时间"));
    REAL_TIME()->RealTimeui->tableView->setModel(model);
    qDebug()<<model->rowCount();


    //REAL_TIME()->data(REAL_TIME()->RealTimeui->tableView->currentIndex(),8);
    //  ui->tableView->
     //------------------------------------------设置颜色-------------------------------------------------------
   REAL_TIME()->RealTimeui->tableView->setAlternatingRowColors( true );
   REAL_TIME()->RealTimeui->tableView->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
         //                                            // "alternate-background-color: rgb(141, 163, 215);}"
       //--------------------------------------------设置颜色-----------------------------------------------------

       //--------------------------------------------设置列宽-----------------------------------------------------
      // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
      //  ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
      //  ui->tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
     //   ui->tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
            //设置表格的各行高的宽度值
           REAL_TIME()->RealTimeui->tableView->setRowHeight(0,20);
           REAL_TIME()->RealTimeui->tableView->setRowHeight(1,20);
           REAL_TIME()->RealTimeui->tableView->setRowHeight(2,20);
            REAL_TIME()->RealTimeui->tableView->setRowHeight(3,20);
            REAL_TIME()->RealTimeui->tableView->setRowHeight(4,20);
            REAL_TIME()->RealTimeui->tableView->setRowHeight(5,20);
            REAL_TIME()->RealTimeui->tableView->setRowHeight(6,20);
            REAL_TIME()->RealTimeui->tableView->setRowHeight(7,20);
           REAL_TIME()->RealTimeui->tableView->setRowHeight(8,20);
           REAL_TIME()->RealTimeui->tableView->setRowHeight(9,20);

            //设置表格的各列的宽度值
          /* ui->tableView->setColumnWidth(0,60);
           ui->tableView->setColumnWidth(1,60);
           ui->tableView->setColumnWidth(2,60);
           ui->tableView->setColumnWidth(3,60);
           ui->tableView->setColumnWidth(4,60);*/
           //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
         REAL_TIME()->RealTimeui->tableView->verticalHeader()->hide();
       //--------------------------------------------设置列宽-----------------------------------------------------
  //  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
   REAL_TIME()->RealTimeui->tableView->resizeColumnsToContents();
    //ui->tableView->resizeRowsToContents();


  //-----------------------------------id 11~20--------------------------------------------------------------------------------
 //  QSqlQueryModel *model1= new QSqlQueryModel( REAL_TIME()->RealTimeui->tableView_2);
    Displacement_Realtime2_MySql * model1 = new Displacement_Realtime2_MySql(REAL_TIME()->RealTimeui->tableView_2);
    model1->setQuery(Which_Table2,db);
    model1->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));  //显示时的表头
    model1->setHeaderData(1,Qt::Horizontal,QObject::tr("深基mm"));
    model1->setHeaderData(2,Qt::Horizontal,QObject::tr("浅基mm"));
 // model->setHeaderData(3,Qt::Horizontal,QObject::tr("时间"));
  REAL_TIME()->RealTimeui->tableView_2->setModel(model1);


  //  ui->tableView->
   //------------------------------------------设置颜色-------------------------------------------------------
  // REAL_TIME()->data( REAL_TIME()->RealTimeui->tableView_2->currentIndex(),1);

 REAL_TIME()->RealTimeui->tableView_2->setAlternatingRowColors( true );
  REAL_TIME()->RealTimeui->tableView_2->setStyleSheet( "QTableView{background-color: rgb(250, 250, 115);" "alternate-background-color: rgb(250, 250, 115);}"   );
       //                                            // "alternate-background-color: rgb(141, 163, 215);}"
     //--------------------------------------------设置颜色-----------------------------------------------------

     //--------------------------------------------设置列宽-----------------------------------------------------
    // ui->tableView->horizontalHeader()->setResizeMode(0, QHeaderView::Fixed);
    //  ui->tableView->horizontalHeader()->setResizeMode(1, QHeaderView::Fixed);
    //  ui->tableView->horizontalHeader()->setResizeMode(2, QHeaderView::Fixed);
   //   ui->tableView->horizontalHeader()->setResizeMode(3, QHeaderView::Fixed);
          //设置表格的各行高的宽度值
         REAL_TIME()->RealTimeui->tableView_2->setRowHeight(0,20);
         REAL_TIME()->RealTimeui->tableView_2->setRowHeight(1,20);
         REAL_TIME()->RealTimeui->tableView_2->setRowHeight(2,20);
          REAL_TIME()->RealTimeui->tableView_2->setRowHeight(3,20);
          REAL_TIME()->RealTimeui->tableView_2->setRowHeight(4,20);
          REAL_TIME()->RealTimeui->tableView_2->setRowHeight(5,20);
         REAL_TIME()->RealTimeui->tableView_2->setRowHeight(6,20);
         REAL_TIME()->RealTimeui->tableView_2->setRowHeight(7,20);
        REAL_TIME()->RealTimeui->tableView_2->setRowHeight(8,20);
          REAL_TIME()->RealTimeui->tableView_2->setRowHeight(9,20);

          //设置表格的各列的宽度值
        /* ui->tableView->setColumnWidth(0,60);
         ui->tableView->setColumnWidth(1,60);
         ui->tableView->setColumnWidth(2,60);
         ui->tableView->setColumnWidth(3,60);
         ui->tableView->setColumnWidth(4,60);*/
         //默认显示行头，如果你觉得不美观的话，我们可以将隐藏
       REAL_TIME()->RealTimeui->tableView_2->verticalHeader()->hide();
     //--------------------------------------------设置列宽-----------------------------------------------------
//  ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
     REAL_TIME()->RealTimeui->tableView_2->resizeColumnsToContents();
  //ui->tableView->resizeRowsToContents();




  }



/*******************************************************************************
* Function Name  : 创建数据库
* Description    : name 名称 lie 名称 hang 名称
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
  int sql::Create_Sql(void)
  {

        //------------------------连接---------------------------
      MYSQL *conR=mysql_init(NULL);
     mysql_real_connect(conR,NULL,NULL,NULL,NULL,0,NULL,0);
    QMYSQLDriver *drvR =  new QMYSQLDriver(conR);
      QSqlDatabase dbR;
     dbR=QSqlDatabase::addDatabase(drvR,"dbr");
     dbR.setHostName("192.168.1.100");
     dbR.setDatabaseName("dingban");
     dbR.setUserName("hu1");
     dbR.setPassword("hu");
     if( !dbR.open())
     {
         qDebug()<<"Failed to connect to Mysql!\n";
        //return 0;
    }else
     {
       qDebug()<<"Connected to Mysql successfully!\n";
    }
     //-----------------插入-------------------
      QSqlQuery query(dbR);
       query.prepare("INSERT INTO realtime1 (id, shenji, qianji) "
                             "VALUES (:id, :shenji, :qianji)");
        query.bindValue(":id", 57);
      query.bindValue(":shenji", 8);
       query.bindValue(":qianji", 3);
       query.exec();

         //---------------------显示---------------------
       QSqlQueryModel *model= new QSqlQueryModel(ui->tableView);
       model->setQuery(QString("select * from realtime1 ;"),dbR);
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("编号"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("深基mm"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("浅基mm"));
       ui->tableView->setModel(model);
      ui->tableView->resizeColumnsToContents();
      ui->tableView->resizeRowsToContents();
  }
  /*******************************************************************************
  * Function Name  : 远程连接
  * Description    : name 名称 lie 名称 hang 名称
  * Input          : None.
  * Output         : None.
  * Return         : None.
  *******************************************************************************/
  int sql::connectSql(QString sIp, QString sDbNm, QString sUserNm, QString sPwd,QSqlDatabase &db)
  {
      MYSQL *conR=mysql_init(NULL);
      mysql_real_connect(conR,NULL,NULL,NULL,NULL,0,NULL,0);
     QMYSQLDriver *drvR =  new QMYSQLDriver(conR);
     db=QSqlDatabase::addDatabase(drvR,"dbr");
     db.setHostName(sIp);
     db.setDatabaseName(sDbNm);
     db.setUserName(sUserNm);
     db.setPassword(sPwd);
    db.exec("SET NAMES 'utf8'");
     if( !db.open())
     {
         qDebug()<<"Failed to connect to Mysql!\n";
       // return -1;
    }else
     {
         //return 1;
       qDebug()<<"Connected to Mysql successfully!\n";
    }

  }
  /*******************************************************************************
  * Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
  * Description    : 键盘
  * Input          :
  * Output         : None.
  * Return         : None.
  *******************************************************************************/
  void sql::keyPressEvent(QKeyEvent *event)
  {

       Dialog2 *dd =new Dialog2();  //历史数据类

       //SQLmain()->hide();
      switch(event->key()) {
      case Qt::Key_F1:                       //左键
          // information();
          break;
      case Qt::Key_Escape:                  //右键

           SQLmain()->hide();
           dd->showFullScreen();
            dd->exec();
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
        // fullscreenwindow::keyPressEvent(event);
          break;
      }
  }
  /*******************************************************************************
      * Function Name  : 键盘选择
      * Description    :
      * Input          :
      * Output         : None.
      * Return         : None.
      *******************************************************************************/
   bool sql:: eventFilter(QObject *watched, QEvent*event)
   {

//       if(watched == ui->shi || watched == ui->ge)//确认可控的控件
//         {
//               // qDebug()<<"12";
//            if(event->type() == QEvent::KeyPress)//如果检测到按键
//              {

//                   bool  f1 =ui->shi->hasFocus();        //分站类型
//                   bool  f2 =ui->ge->hasFocus();  //分站编号

//                QKeyEvent *key_event = static_cast<QKeyEvent *>(event); //将事件转化为键盘事件

//                if(key_event->key() == Qt::Key_Right)//右键
//                  {
//                      if(f1)//焦点在分站类型
//                     {

//                        focusNextChild();//焦点移动
//                        ui->ge->setFocus();//移动到分站编号
//                     }
//                  }
//                  if(key_event->key() == Qt::Key_Left)
//                  {
//                      if(f2)
//                     {
//                        focusNextChild();
//                      ui->shi->setFocus();
//                     }
//                  }

//            }

//     }
//     return QWidget::eventFilter(watched,event);     //最后将事件交给上层对话框


   }
  /*******************************************************************************
      * Function Name  : //位移实时数据库初始化
      * Description    :
      * Input          :
      * Output         : None.
      * Return         : None.
      *******************************************************************************/
      int sql::Init_RealTime_Date_SQL(QSqlDatabase db,QString Which_Table)
      {

           QString cmd4 ="use test";
           QString init=NULL;
          for(int cc=1;cc<=20;cc++)
          {

               QString cmd_write=QString("update Displacement_Realtime set shenji = '%1',qianji = '%2',time = '%3' where cgq_id = %4;").arg(init).arg(init).arg(init).arg(cc);
                QSqlQuery   q4(cmd4,db);
                QSqlQuery  q5(cmd_write,db);
         }

      }

