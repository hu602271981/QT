#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QDebug>
#include <QMutex>
class MyThread: public QThread
{
      Q_OBJECT
public:
    MyThread();
    void run();
    QMutex mutex;
signals:
    void UpdateSignal(void);
};




#endif // MYTHREAD_H
