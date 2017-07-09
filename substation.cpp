#include "substation.h"
#include "ui_substation.h"
#include <QNetworkInterface>
#include <QValidator>
#include <QDateTime>
#include <QString>
#include <QLabel>
#include "QKeyEvent"
#include "parametersetting.h"
#include "main.h"
//分站本机参数设定界面
Substation::Substation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Substation)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

     ui->FenZhan_type_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->FenZhan_type_ge->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->FenZhan_NUMBER_shi->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器\

     ui->location->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->time->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->week->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
     ui->CAN1->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->CAN2->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->CAN2_rate->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->Wireless->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->Ethernet->installEventFilter(this);  //在窗体上为lineEdit1安装过滤器
      ui->FenZhan_NUMBER_ge->installEventFilter(this);




//    QString a = "1";
//    QString b = "2";
//    QString c = "3";
//    QString d = "4";
//    ui->lineEdit_1->setText(a);
//    ui->lineEdit_2->setText(b);
//    ui->lineEdit_3->setText(c);
//    ui->label->setText(d);
//    ui->IPlineEdit_6->setText(QNetworkInterface().allAddresses().at(0).toString());
//    ui->lineEdit_1->setValidator(new QIntValidator(0,16,this));
//    ui->lineEdit_2->setValidator(new QIntValidator(0,64,this));
//    QDateTime  time = QDateTime::currentDateTime();//获取系统现在的时间
//    QString str =  time.toString("yyyy-MM-dd hh:mm:ss ");
//    QString str2 = time.toString("dddd");

//    ui->lineEdit_3->setText(str);
//    ui->label->setText(str2);
      UI_SHOW();

}

Substation::~Substation()
{

    delete ui;
}
/*******************************************************************************
* Function Name  :分站本机参数更新
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
   void Substation::Substation_Local_UPdate(void)
  {



   }
/*******************************************************************************
* Function Name  :  界面显示
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
  int Substation:: UI_SHOW(void)
  {     // focusNextChild();
       //  ui->FenZhan_type_shi->setFocus();
  // 分站类型
    //   ui->FenZhan_type->setText("00");
  //分站编号
    //  ui->FenZhan_NUMBER->setText("01");
   //安装地点
     ui->location->setText(QObject::trUtf8("工作面"));
  //时间
     QDateTime  time = QDateTime::currentDateTime();//获取系统现在的时间
      QString str =  time.toString("yyyy-MM-dd hh:mm:ss ");
       QString str2 = time.toString("dddd");
       ui->time->setText(str);


       if( QString::compare(str2,"Monday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期一"));
       }
       if( QString::compare(str2,"Tuesday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期二"));
       }
       if( QString::compare(str2,"Wednesday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期三"));
       }
       if( QString::compare(str2,"Thursday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期四"));
       }
       if( QString::compare(str2,"Friday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期五"));
       }
       if( QString::compare(str2,"Saturday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期六"));
       }
       if( QString::compare(str2,"Sunday")==0)
       {
            ui->week->setText(QObject::trUtf8("星期日"));
       }
 //第一路CAN


 //第二路CAN

 //无线传输

 //以太网


       QList<QNetworkInterface> list=QNetworkInterface::allInterfaces ();
       for(int i=0;i<list.count();i++)
       {
               QNetworkInterface interface=list.at(i);

                QString hardwareAddress=interface.hardwareAddress();
               QList<QNetworkAddressEntry> entryList=interface.addressEntries();
               for(int j=0;j<entryList.count();j++)
               {
                       QNetworkAddressEntry entry=entryList.at(j);
                        ui->IP->setText(entry.ip().toString());
                        ui->YanMan->setText(entry.netmask().toString());
                        ui->WangGuan->setText(entry.broadcast().toString());

               }

       }


  }

/*******************************************************************************
* Function Name  : 键盘控制  在锁屏状态下显示分站综合信息
* Description    : 键盘
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
void Substation::keyPressEvent(QKeyEvent *event)
{
    ParameterSetting *window=new ParameterSetting();  //参数设定主界面
    // Substation *h=new Substation(); //分站本机
    switch(event->key()) {
    case Qt::Key_F1:                       //左键
            //information();
        break;
    case Qt::Key_Escape:      //右键
                FZ_LOCAL()->Save_sql();//判断数据是否存入数据库
                FZ_LOCAL()->close();
                window->showFullScreen();
                window->exec();
        break;
    case Qt:: Key_Left:
         //front()->hide();
             ;
        break;
    case Qt::Key_Up:                  //右键



        break;
   // case Qt::Key_Right:                  //右键
         //front()->hide();
          //   ;
    //    break;
    case Qt::Key_Down:                  //右键
         //front()->hide();
             ;
        break;
    default:

       //fullscreenwindow::keyPressEvent(event);
        break;
    }
}
/*******************************************************************************
* Function Name  : 判断是否写入数据库
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
  void Substation::Save_sql(void)  //写入数据库
  {
      QMessageBox message(QMessageBox::Warning,"Information","Really to save setting?",QMessageBox::Yes|QMessageBox::No,NULL);
      if (message.exec()==QMessageBox::Yes)
      { //写书数据库
            //emit Update_Signal(1);
            qDebug()<<"clicked yes\n";
           FZ_LOCAL()->Substation_Save_Date(SQLmain()->db_TEST,"Really to save setting?");
      }
      else
      { //不写入数据库
          qDebug()<<"clicked no\n";
      }

  }
  /*******************************************************************************
  * Function Name  : //写入数据库
  * Description    :
  * Input          :
  * Output         : None.
  * Return         : None.
  *******************************************************************************/
 int Substation::Substation_Save_Date(QSqlDatabase db,QString Which_Table)
 {
//--------------------------------------------------------------------------------------------------------
     //计算分站类型和分站编号
    int a[5];//用来存放a[0]分站类型 a[1]分站编号

     a[0]=(ui->FenZhan_type_shi->currentText().toInt())*10+ui->FenZhan_type_ge->currentText().toInt();
     a[1]=(ui->FenZhan_NUMBER_shi->currentText().toInt())*10+ui->FenZhan_NUMBER_ge->currentText().toInt();
     //qDebug()<<a[0]<<a[1];
   QString cmd1=QString("update Substation_Set set Station_Type= '%1',Station_Number='%2' ,Installation_location='%3',\
                        Time='%4',week='%5';") \
            .arg(a[0]).arg(a[1])\
           .arg(ui->location->text()).arg(ui->time->text()).arg(ui->week->text());

   QSqlQuery  q(cmd1,db);

//-------------------------------------------------------------------------------------------------------------
   QString cmd2=QString("update Substation_Set set CAN1_Situation= '%1',CAN2_Situation='%2' ,\
                        CAN2_Rate='%3',Wireless_Situation='%4',Ethernet_Situation='%5';") \
            .arg(ui->CAN1->currentText()).arg(ui->CAN2->currentText())\
           .arg(ui->CAN2_rate->currentText()).arg(ui->Wireless->currentText()).arg(ui->Ethernet->currentText());

   QSqlQuery  q2(cmd2,db);

//---------------------------------------------网络IP类---还没有设置-------------------------------------------------------------------
   QString cmd3=QString("update Substation_Set set local_IP= '%1',local_Mask='%2' ,\
                        local_Gateway='%3',Server_IP='%4',Server_Port='%5';") \
            .arg(ui->IP->text()).arg(ui->YanMan->text())\
           .arg(ui->WangGuan->text()).arg(ui->SERVER_NET->text()).arg(ui->SERVER_PORT->text());

   QSqlQuery  q3(cmd3,db);

 }
/*******************************************************************************
* Function Name  : 用来按键移动
* Description    :
* Input          :
* Output         : None.
* Return         : None.
*******************************************************************************/
 bool Substation::eventFilter(QObject *watched, QEvent*event)
 {

     if(watched == ui->FenZhan_NUMBER_shi || watched == ui->FenZhan_NUMBER_ge|| watched == ui->FenZhan_type_shi||\
             watched == ui->FenZhan_type_ge || watched == ui->location\
       || watched == ui->CAN1|| watched == ui->CAN2|| watched == ui->CAN2_rate   \
         || watched == ui->Wireless|| watched == ui->Ethernet)//确认可控的控件
       {
             // qDebug()<<"12";
          if(event->type() == QEvent::KeyPress)//如果检测到按键
            {

                 bool  f1 =ui->FenZhan_type_shi->hasFocus();        //分站类型
                 bool  f2 =ui->FenZhan_type_ge->hasFocus();  //分站编号


                 bool  f3 =ui->location->hasFocus(); //安装位置
               //  bool  f6 =ui->time->hasFocus();
                // bool  f7 =ui->week->hasFocus();
                 bool  f4 =ui->CAN1->hasFocus();
                 bool  f5=ui->CAN2->hasFocus();
                 bool  f6=ui->CAN2_rate->hasFocus();
                 bool  f7 =ui->Wireless->hasFocus();
                 bool  f8 =ui->Ethernet->hasFocus();
                  bool  f9 =ui->FenZhan_NUMBER_shi->hasFocus(); //安装位置
                 bool  f10 =ui->FenZhan_NUMBER_ge->hasFocus();  //分站编号
              QKeyEvent *key_event = static_cast<QKeyEvent *>(event); //将事件转化为键盘事件

              if(key_event->key() == Qt::Key_Right)//右键
                {
                    if(f1)//焦点在分站类型
                   {

                      focusNextChild();//焦点移动
                      ui->FenZhan_type_ge->setFocus();//移动到分站编号
                   }
                    if(f2)
                  {
                      focusNextChild();
                     ui->location->setFocus();
                   }
                    if(f3)
                   {
                      focusNextChild();
                    ui->CAN1->setFocus();
                   }
                    if(f4)
                   {
                      qDebug()<<"122";
                      focusNextChild();//焦点移动
                      // ui->CAN1->setFocus();//移动到分站编号
                     ui->CAN2->setFocus();//移动到分站编号
                   }
                    if(f5)//焦点在分站类型
                   {
                      focusNextChild();//焦点移动
                      ui->CAN2_rate->setFocus();//移动到分站编号
                   }
                    if(f6)
                  {
                      focusNextChild();
                   ui->Wireless->setFocus();
                   }
                    if(f7)
                   {
                      focusNextChild();
                   ui->Ethernet->setFocus();
                   }
                    if(f8)
                  {
                      focusNextChild();
                   ui->FenZhan_NUMBER_shi->setFocus();
                   }
                    if(f9)
                   {
                      focusNextChild();
                     ui->FenZhan_NUMBER_ge->setFocus();
                   }


                }
                if(key_event->key() == Qt::Key_Left)
                {

                    if(f10)
                   {
                      focusNextChild();
                   ui->FenZhan_NUMBER_shi->setFocus();
                   }
                    if(f9)
                   {
                      focusNextChild();
                   ui->Ethernet->setFocus();
                   }
                    if(f8)
                   {
                      focusNextChild();
                   ui->Wireless->setFocus();
                   }
                    if(f7)
                   {
                      focusNextChild();
                   ui->CAN2_rate->setFocus();
                   }

                    if(f6)
                   {
                      focusNextChild();
                   ui->CAN2->setFocus();
                   }
                    if(f5)
                   {
                     focusNextChild();
                   ui->CAN1->setFocus();
                   }

                    if(f4)
                   {
                        qDebug()<<"1212";
                      focusNextChild();
                   ui->location->setFocus();
                   }
                    if(f3)
                   {
                     focusNextChild();
                   ui->FenZhan_type_ge->setFocus();
                   }
                    if(f2)
                   {
                      focusNextChild();
                    ui->FenZhan_type_shi->setFocus();
                   }
                }

          }

   }
   return QWidget::eventFilter(watched,event);     //最后将事件交给上层对话框

 }
