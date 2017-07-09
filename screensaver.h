#ifndef SCREENSAVER_H
#define SCREENSAVER_H
#include <QKeyEvent>
#include <QDialog>
//屏幕保护画面
namespace Ui {
class ScreenSaver;
}

class ScreenSaver : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenSaver(QWidget *parent = 0);
    ~ScreenSaver();

private:
    Ui::ScreenSaver *ui;
private slots:
     void onTimerOut();
     void information();
protected:
     void keyPressEvent(QKeyEvent *event);  //按键事件
};

#endif // SCREENSAVER_H
