#ifndef CLIENT_H
#define CLIENT_H

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
#include"windowsinstances.h"
#include <winsock.h>

using namespace std;

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT

public:
    explicit client(int,QWidget *parent = nullptr);
    ~client();
    void ceck_pass();

private slots:
    void on_loginButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::client *ui;
    int socket;
    string buff;
    char raspuns[255];
    QString user,pass;
};


#endif // CLIENT_H
