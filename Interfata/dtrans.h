#ifndef DTRANS_H
#define DTRANS_H

#include <QWidget>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <winsock.h>
#include <windowsinstances.h>

using namespace std;
namespace Ui {
class dTrans;
}

class dTrans : public QWidget
{
    Q_OBJECT

public:
    explicit dTrans(int,QWidget *parent = nullptr);
    void detalii_tr(string str);
    ~dTrans();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dTrans *ui;
    string buff;
    char raspuns[4096];
    int socket;
};

#endif // DTRANS_H
