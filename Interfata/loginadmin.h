#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QWidget>

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAdmin(QWidget *parent = nullptr);
    ~LoginAdmin();

private:
    Ui::LoginAdmin *ui;
};

#endif // LOGINADMIN_H
