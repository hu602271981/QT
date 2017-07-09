#ifndef PROCESSER_STOREINFORMATION_H
#define PROCESSER_STOREINFORMATION_H
//支架压力存储信息头文件
#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQueryModel>
namespace Ui {
class Processer_StoreInformation;
}

class Processer_StoreInformation : public QDialog
{
    Q_OBJECT

public:
    explicit Processer_StoreInformation(QWidget *parent = 0);
    ~Processer_StoreInformation();
        Ui::Processer_StoreInformation *Ui_Processer_StoreInformation;
        int Processer_StoreInformation_Up_Date(void);       //顶板压力数据库更新信息

        int Init_Processer_StoreInformation(QSqlDatabase db); //顶板压力数据库初始化
        int Show_Processer_StoreInformation(QSqlDatabase db,QString Which_Table10,QString Which_Table20\
                                                     ,QString Which_Table30,QString Which_Table40  ); //显示顶板压力数据存储容量






protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件
};

/*******************************************************************************
* Function Name  :压力存储表格一颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Pressure_Store_SHOW1 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Pressure_Store_SHOW1(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;


signals:

public slots:

private:

};

/*******************************************************************************
* Function Name  :压力存储表格二颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Pressure_Store_SHOW2 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Pressure_Store_SHOW2(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;



signals:

public slots:

private slots:


};

/*******************************************************************************
* Function Name  :压力存储表格三颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Pressure_Store_SHOW3 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Pressure_Store_SHOW3(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;


signals:

public slots:

private:

};

/*******************************************************************************
* Function Name  :压力存储表格四颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Pressure_Store_SHOW4 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Pressure_Store_SHOW4(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;



signals:

public slots:

private slots:


};

#endif // PROCESSER_STOREINFORMATION_H
