#include "application.h"
#include <qglobal.h>
#include <QDebug>
Application::Application (int  &argc, char **argv)
                     :QApplication(argc, argv )

{
      //创建一个QTimer对象
    timer = new QTimer();
    //设置定时器每个多少毫秒发送一个timeout()信号
    timer->setInterval(50000);
    //启动定时器
    timer->start();
}
void Application::setWindowInstence(ScreenSaver *wnd)
{
    window = wnd;
    //信号和槽
    connect(timer,SIGNAL(timeout()),wnd,SLOT(onTimerOut()));

}
bool Application::notify(QObject *obj, QEvent *e)
{
    if(e->type() == QEvent::KeyPress)
    {
        if(window)
        {
            //timeflag=1;
            timer->stop();
            qDebug()<<"stop";
            window->hide(); //调用你窗体相应的函数
        }
    }
    else
    {
        if(!timer->isActive())
        {
            timer->start();
            qDebug()<<"start";
        }
    }

    return QApplication::notify(obj,e);
}

