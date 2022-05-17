#ifndef ADDTRANS_H
#define ADDTRANS_H

#include <QWidget>
#include <iostream>
#include <windowsinstances.h>
#include <winsock.h>
#include <string>
#include <QString>
#include <QMessageBox>
using namespace std;
namespace Ui {
class addtrans;
}

class addtrans : public QWidget
{
    Q_OBJECT

public:
    explicit addtrans(int,QWidget *parent = nullptr);
    ~addtrans();

private slots:
    void on_add_clicked();

    void on_back_clicked();

private:
    Ui::addtrans *ui;
    int socket;
    string buff;
    char raspuns[255];
    void addTr();
};

#endif // ADDTRANS_H
