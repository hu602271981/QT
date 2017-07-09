#include "screensaver.h"
#include "ui_screensaver.h"
#include "golobe.h"
#include "QKeyEvent"
#include "main.h"
ScreenSaver::ScreenSaver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenSaver)
{
    ui->setupUi(this);
}

ScreenSaver::~ScreenSaver()
{
    delete ui;
}
void ScreenSaver::onTimerOut()
{
    this->showFullScreen();
}
void ScreenSaver::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Return:
        information();
        break;
    case Qt::Key_Escape:                  //右键
             //front()->hide();
                 ;
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
       ScreenSaver::keyPressEvent(event);
        break;
    }
}

void ScreenSaver::information()
{
      front()->showFullScreen();
      front()->exec();
      front()->hide();



}
