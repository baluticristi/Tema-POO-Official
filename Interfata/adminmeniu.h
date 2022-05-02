#ifndef ADMINMENIU_H
#define ADMINMENIU_H

#include <QWidget>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <winsock.h>

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

private:
    Ui::adminmeniu *ui;
    int socket;
    string buff;
    char raspuns[255] = { 0, };
};

#endif // ADMINMENIU_H
