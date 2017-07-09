#ifndef APPLICATION_H
#define APPLICATION_H
#include  <QApplication>
#include <screensaver.h>
#include <QDebug>
#include <QTimer>
//application重写
class  Application : public QApplication

{
 public :
    Application (int & argc, char ** argv);
    bool notify(QObject *, QEvent *);
    void setWindowInstence (ScreenSaver *wnd);
 private:
    ScreenSaver *window;  //保存一个窗体的指针
    QTimer *timer;
};
#endif // APPLICATION_H
