#ifndef LOGINADMIN_H
#define LOGINADMIN_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QApplication>
#include <QLineEdit>
#include <QMessageBox>
#include <QPixmap>
#include <QFont>
#include <string>
#include <iostream>
#include <winsock.h>
#include "windowsinstances.h"

using namespace std;

namespace Ui {
class LoginAdmin;
}

class LoginAdmin : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAdmin(int,QWidget *parent = nullptr);
    ~LoginAdmin();

private slots:

    void on_log_clicked();

    void ceck_pass();

    void on_mainwind_clicked();

private:
    Ui::LoginAdmin *ui;
    int socket;
    string buff;
    char raspuns[255] = { 0, };
    QString user,pass;
};

#endif // LOGINADMIN_H
