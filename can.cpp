#include "can.h"
#include "golobe.h"
#include <QDebug>
#include "main.h"
can::can()
{


}

/*******************************************************************************
* Function Name  :  can错误处理
* Description    :CAN
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void can:: handle_err_frame(const struct can_frame *fr)
{
    if (fr->can_id & CAN_ERR_TX_TIMEOUT) {
        errout("CAN_ERR_TX_TIMEOUT");
    }
    if (fr->can_id & CAN_ERR_LOSTARB) {
        errout("CAN_ERR_LOSTARB");
        errcode(fr->data[0]);
    }
    if (fr->can_id & CAN_ERR_CRTL) {
        errout("CAN_ERR_CRTL");
        errcode(fr->data[1]);
    }
    if (fr->can_id & CAN_ERR_PROT) {
        errout("CAN_ERR_PROT");
        errcode(fr->data[2]);
        errcode(fr->data[3]);
    }
    if (fr->can_id & CAN_ERR_TRX) {
        errout("CAN_ERR_TRX");
        errcode(fr->data[4]);
    }
    if (fr->can_id & CAN_ERR_ACK) {
        errout("CAN_ERR_ACK");
    }
    if (fr->can_id & CAN_ERR_BUSOFF) {
        errout("CAN_ERR_BUSOFF");
    }
    if (fr->can_id & CAN_ERR_BUSERROR) {
        errout("CAN_ERR_BUSERROR");
    }
    if (fr->can_id & CAN_ERR_RESTARTED) {
        errout("CAN_ERR_RESTARTED");
    }
}

/*******************************************************************************
* Function Name  :  can打印结构体
* Description    :CAN
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
 void can::print_frame(struct can_frame *fr)
{
    int i;
    printf("%08x\n", fr->can_id & CAN_EFF_MASK);
    //printf("%08x\n", fr->can_id);
    printf("dlc = %d\n", fr->can_dlc);
    printf("data = ");
    for (i = 0; i < fr->can_dlc; i++)
        printf("%02x ", fr->data[i]);
         printf("\n");
}

/*******************************************************************************
* Function Name  :  can tx
* Description    :CAN
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int can::CanTx(can_frame a1)
{
          int ret, i;
          struct timeval tv;
          fd_set rset;
          tv.tv_sec = 1;
          tv.tv_usec = 0;
          FD_ZERO(&rset);
          FD_SET(s, &rset);
         ret = write(s, &a1, sizeof(a1));
          if (ret < 0)
          {
                qDebug() << "write failed";
              //myerr("write failed");
              return -1;
          }
}
/*******************************************************************************
* Function Name  :  can 初始化
* Description    :CAN
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int can::CanInit()
{
      //	int s;
        int ret;
        struct sockaddr_can addr;
        struct ifreq ifr;
        int master;

      srand(time(NULL));
        s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
        if (s < 0) {
            perror("socket PF_CAN failed");
            return 1;
        }

        strcpy(ifr.ifr_name, "can0");
        ret = ioctl(s, SIOCGIFINDEX, &ifr);
        if (ret < 0) {
            perror("ioctl failed");
            return 1;
        }

        addr.can_family = PF_CAN;
        addr.can_ifindex = ifr.ifr_ifindex;

        ret = bind(s, (struct sockaddr *)&addr, sizeof(addr));
        if (ret < 0) {
            perror("bind failed");
            return 1;
        }
        //过滤器
    if (1) {
        struct can_filter filter[2];
        filter[0].can_id = 0x000| CAN_EFF_FLAG;
        filter[0].can_mask = 0xFFF;

        filter[1].can_id = 0x20F | CAN_EFF_FLAG;
        filter[1].can_mask = 0xFFF;


      //  ret = setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter));
        //if (ret < 0) {
          //  perror("setsockopt failed");
            //return 1;
        //}
    }
    //test_can_rw(s, master);



    //close(s);
    //return 0;
}
/*******************************************************************************
* Function Name  :  can rx
* Description    :CAN
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int can::Can_Rx(struct can_frame a2)
{
     //can rx;
    int ret, i;
    //struct can_frame fr, frdup;
    struct timeval tv;
    fd_set rset;


        tv.tv_sec = 1;
        tv.tv_usec = 0;
        FD_ZERO(&rset);
        FD_SET(s, &rset);

        ret = select(s+1, &rset, NULL, NULL, NULL);
        if (ret == 0) {
           qDebug() << "select time out";
            //return -1;
        }

        ret = read(s, &a2, sizeof(a2));
        if (ret < sizeof(a2)) {
            qDebug() << "read failed";
        //	return -1;
        }
        if (a2.can_id & CAN_ERR_FLAG) { /* 出错设备错误 */
            handle_err_frame(&a2);
            myerr("CAN device error");
            //continue;
        }
    //printf("'%d\n",a2.data[0]) ;
         //printf("1111");
    print_frame(&a2);
    memcpy(Can_Rx_Save,a2. data,sizeof(a2. data));
    Can_Id=a2.can_id;
 //memcpy(a2. data,Net_Tx_Buffer,a2.can_dlc);
    //memcpy(Net_Tx_Buffer,a2. data,sizeof(a2. data));

    return 1;
}
/*******************************************************************************
* Function Name  : 处理数据并发
* Description    :type 1-open 0-close
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

 int  can::Can_Filter(unsigned int can_id,int type)
 {
     struct can_filter filter[1];
     filter[0].can_id = can_id| CAN_EFF_FLAG;
     filter[0].can_mask = 0xFFF;
     if(type=1)
     {
         int ret =setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, & filter, sizeof( filter));//设置规则
         if (ret < 0) {
              qDebug() << "setsockopt open failed";
             return -1;
                            }

     }
        else
     {
          int ret=setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0); //禁用过滤规则
           if (ret < 0) {
                qDebug() << "setsockopt close failed";
               return -1;
                              }

     }
     return 1;

 }
 /*******************************************************************************
 * Function Name  : //获取系统的时间并传递到发送的数组中
 * Description    :输出到 Set_Time_Buffer
 * Input          : None.
 * Output         : None.
 * Return         : None.
 *******************************************************************************/
int can::Set_Time(  unsigned char Set_Time_Buffer[8])
{

     QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间

     QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式

     qDebug() << str<<endl;

          QByteArray ba = str.toLatin1();

           char *mm = ba.data();
           Set_Time_Buffer[0]=0x00;
           Set_Time_Buffer[1]=(((int)mm[2]%16)*10)+ ((int)mm[3]%16); //年
           Set_Time_Buffer[2]=(((int)mm[5]%16)*10)+ ((int)mm[6]%16); //月
           Set_Time_Buffer[3]=(((int)mm[8]%16)*10)+ ((int)mm[9]%16); //日
           Set_Time_Buffer[4]=(((int)mm[11]%16)*10)+ ((int)mm[12]%16); //时
           Set_Time_Buffer[5]=(((int)mm[14]%16)*10)+ ((int)mm[15]%16); //分
           Set_Time_Buffer[6]=(((int)mm[17]%16)*10)+ ((int)mm[18]%16); //秒
           Set_Time_Buffer[7]=0xdd;

      //qDebug() << Set_Time_Buffer[0]<<endl;
     // qDebug() << Set_Time_Buffer[1]<<endl;
      //qDebug() << Set_Time_Buffer[2]<<endl;
     // qDebug() << Set_Time_Buffer[3]<<endl;
      //qDebug() << Set_Time_Buffer[4]<<endl;
     // qDebug() << Set_Time_Buffer[5]<<endl;
     // qDebug() << Set_Time_Buffer[6]<<endl;
     // qDebug() << Set_Time_Buffer[7]<<endl;



}
//---------------------------char 转 unsigned char-------------------------------------
void can::convertStrToUnChar(char* str, unsigned char* UnChar)
{
    int i = strlen(str), j = 0, counter = 0;
    char c[2];
    unsigned int bytes[2];

    for (j = 0; j < i; j += 2)
    {
        if(0 == j % 2)
        {
            c[0] = str[j];
            c[1] = str[j + 1];
            sscanf(c, "%02x" , &bytes[0]);
            UnChar[counter] = bytes[0];
            counter++;
        }
    }
    return;
}
/*******************************************************************************
* Function Name  : canid
* Description    ：0x         00 00 00 00
*                                          ab  c    d
* Input          : None.     id 接收到的canid                   *buffer 接收到的数据信息
* Output         : None.   ID_CHAR 处理后的id信息      After_Date 处理后的数据信息      QString Afler_Time 处理后的时间信息
* Return         : None.
*******************************************************************************/
unsigned int can::Can_Now_Time_Chuli(unsigned int id,unsigned int *ID_CHAR,unsigned char *buffer,QString &Afler_Time)

{
    unsigned int DingYI_Id;   //用来把协议实际id 转化为协议

    unsigned int a,b,c,d;   //a  分站类型  b分站编号   c 传感器类型  d   传感器编号
  //-----------------等传感器的新协议做好直接替代----------
         //  DingYI_Id=id<<3;
   //----------------------------------
           //-----------------暂时代替---------
    switch (id) {
    case 0x80a0e220:     //编号57
         DingYI_Id=0x01010900;
        break;
   case 0x80004220:     //编号2
         DingYI_Id=0x01010200;
        break;
    default:
           DingYI_Id=id;
        break;
    }
      //-----------------------------------------
   a=( DingYI_Id&0xffffff00)>>28;    //标识码1：高四位表示分站类型
   ID_CHAR[0]=a;
   b=(( DingYI_Id&0xffffff00)>>24)&(0xf);    //标识码1：低四位表示分站编号
   ID_CHAR[1]=b;
   c=(( DingYI_Id&0xffffff00)>>16)&(0xff);    //  标识码2：表示传感器类型；
   ID_CHAR[2]=c;
   d=(( DingYI_Id&0xffffff00)>>8)&(0xff);      //  标识码3：  表示传感器编号；
   ID_CHAR[3]=d;


     if (buffer[0]=0xdd)   //时间帧
    {
        QString string_year = QString::number(buffer[1],16);
        QString string_yue = QString::number(buffer[2],16);
        QString string_day= QString::number(buffer[3],16);
         QString string_hour= QString::number(buffer[4],16);
        QString string_minute= QString::number(buffer[5],16);
         Afler_Time="20"+string_year+"-"+string_yue+"-"+string_day+" "+string_hour+":"+string_minute;
         qDebug()<<Afler_Time;
            return 1;
        }

}
/*******************************************************************************
* Function Name  : canid
* Description    ：0x         00 00 00 00
*                                          ab  c    d
* Input          : None.     id 接收到的canid                   *buffer 接收到的数据信息
* Output         : None.   ID_CHAR 处理后的id信息      After_Date 处理后的数据信息      QString Afler_Time 处理后的时间信息
* Return         : None.
*******************************************************************************/
unsigned int can::Can_Now_Data_Chuli(unsigned int id,unsigned int *ID_CHAR,\
                                                    unsigned char *buffer,QString *data)
 {
    unsigned int DingYI_Id;   //用来把协议实际id 转化为协议

    unsigned int a,b,c,d;   //a  分站类型  b分站编号   c 传感器类型  d   传感器编号
  //-----------------等传感器的新协议做好直接替代----------
//          DingYI_Id=id<<3;
//          qDebug()<<"id:"<<DingYI_Id;
   //----------------------------------
           //-----------------暂时代替---------
    switch (id) {
    case 0x80a0e220:     //编号9
         DingYI_Id=0x01010900;
        break;
   case 0x80004220:     //编号2
         DingYI_Id=0x01010200;
        break;
    default:
          DingYI_Id=id;
        break;
    }
      //-----------------------------------------
   a=( DingYI_Id&0xffffff00)>>28;    //标识码1：高四位表示分站类型
   ID_CHAR[0]=a;
   b=(( DingYI_Id&0xffffff00)>>24)&(0xf);    //标识码1：低四位表示分站编号
   ID_CHAR[1]=b;
   c=(( DingYI_Id&0xffffff00)>>16)&(0xff);    //  标识码2：表示传感器类型；
   ID_CHAR[2]=c;
   d=(( DingYI_Id&0xffffff00)>>8)&(0xff);      //  标识码3：  表示传感器编号；
   ID_CHAR[3]=d;

   a=buffer[1]&0xf;
   b=buffer[2]&0xf;
   c=buffer[3]&0xf;

      QString string1_bai = QString::number(buffer[2],16);
      QString string1_shi= QString::number(buffer[3],16);
      QString string1_ge = QString::number(buffer[4],16);

       data[0]=string1_bai+string1_shi+ string1_ge;

      QString string2_bai = QString::number(buffer[5],16);
      QString string2_shi= QString::number(buffer[6],16);
      QString string2_ge = QString::number(buffer[7],16);

       data[1]=string2_bai+string2_shi+ string2_ge;




 }
