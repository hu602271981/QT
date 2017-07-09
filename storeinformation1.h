#ifndef STOREINFORMATION1_H
#define STOREINFORMATION1_H
  //暂时不用
#include <QDialog>

namespace Ui {
class StoreInformation1;
}

class StoreInformation1 : public QDialog
{
    Q_OBJECT

public:
    explicit StoreInformation1(QWidget *parent = 0);
    ~StoreInformation1();

private:
    Ui::StoreInformation1 *ui;
};

#endif // STOREINFORMATION1_H
