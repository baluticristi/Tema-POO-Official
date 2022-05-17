#ifndef ADMINMENIU_H
#define ADMINMENIU_H

#include <QWidget>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <winsock.h>
#include <windowsinstances.h>

using namespace std;
namespace Ui {
class adminmeniu;
}

class adminmeniu : public QWidget
{
    Q_OBJECT

public:
    explicit adminmeniu(int sock,QWidget *parent = nullptr);
    ~adminmeniu();

private slots:
    void on_pushButton_clicked();

    void on_delObiectiv_clicked();

    void on_pushButton_4_clicked();

    void on_delCazare_clicked();

    void on_addObiectiv_clicked();

    void on_addTransport_clicked();

    void on_addCazare_clicked();

private:
    Ui::adminmeniu *ui;
    int socket;
    string buff;
    char raspuns[255];
};

#endif // ADMINMENIU_H
