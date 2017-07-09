#ifndef STOREINFORMATION2_H
#define STOREINFORMATION2_H
//未用
#include <QDialog>

namespace Ui {
class Storeinformation2;
}

class Storeinformation2 : public QDialog
{
    Q_OBJECT

public:
    explicit Storeinformation2(QWidget *parent = 0);
    ~Storeinformation2();

private:
    Ui::Storeinformation2 *ui;
};

#endif // STOREINFORMATION2_H
