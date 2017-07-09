#ifndef STORE_INFORMATION_H
#define STORE_INFORMATION_H

#include <QDialog>
#include<stdlib.h>
#include<stdio.h>
#include <QDialog>
#include <QSqlDatabase>
#include <QtSql>
#include <QSqlQueryModel>
//顶板位移存储信息
namespace Ui {
class Store_information;
}

class Store_information : public QDialog
{
    Q_OBJECT

public:
    explicit Store_information(QWidget *parent = 0);
    ~Store_information();
        Ui::Store_information *Ui_Store_information;
        int Displacement_Store_SHOW(QSqlDatabase db,QString Which_Table10,QString Which_Table20\
                                                     ,QString Which_Table30,QString Which_Table40  ); //显示数据存储容量
        int Displacement_Store_Update(void);
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件

};

/*******************************************************************************
* Function Name  :位移存储表格一颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Displacement_Store_show1 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Displacement_Store_show1(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;


signals:

public slots:

private:

};

/*******************************************************************************
* Function Name  :位移存储表格二颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Displacement_Store_show2 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Displacement_Store_show2(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;



signals:

public slots:

private slots:


};

/*******************************************************************************
* Function Name  :位移存储表格三颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Displacement_Store_show3 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Displacement_Store_show3(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;


signals:

public slots:

private:

};

/*******************************************************************************
* Function Name  :位移存储表格四颜色
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/


class Displacement_Store_show4 : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit Displacement_Store_show4(QObject *parent = 0);
    QVariant data(const QModelIndex &item, int role=Qt::DisplayRole) const;



signals:

public slots:

private slots:


};

#endif // STORE_INFORMATION_H
