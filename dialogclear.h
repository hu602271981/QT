#ifndef DIALOGCLEAR_H
#define DIALOGCLEAR_H
#pragma execution_character_set("utf-8")
//数据清除显示画面
#include <QDialog>
#include <QMessageBox>


namespace Ui {
class Dialogclear;
}

class Dialogclear : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogclear(QWidget *parent = 0);
    ~Dialogclear();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
     void on_pushButton_3_clicked();


private:
    Ui::Dialogclear *ui;
protected:
    void keyPressEvent(QKeyEvent *event);     //按键事件

};

#endif // DIALOGCLEAR_H
