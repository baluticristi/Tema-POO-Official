#ifndef DELOB_H
#define DELOB_H

#include <QWidget>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <winsock.h>
#include <windowsinstances.h>

using namespace std;
namespace Ui {
class delOb;
}

class delOb : public QWidget
{
    Q_OBJECT

public:
    explicit delOb(int,string,QWidget *parent = nullptr);
    ~delOb();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    string del;
    Ui::delOb *ui;
    string buff;
    char raspuns[255];
    int socket;
    void delFunc();
};

#endif // DELOB_H
