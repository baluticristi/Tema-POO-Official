#ifndef ADDLOC_H
#define ADDLOC_H

#include <QWidget>
#include <iostream>
#include <windowsinstances.h>
#include <winsock.h>
#include <string>
#include <QString>
#include <QMessageBox>
using namespace std;
namespace Ui {
class addloc;
}

class addloc : public QWidget
{
    Q_OBJECT

public:
    explicit addloc(int,QWidget *parent = nullptr);
    ~addloc();

private slots:
    void on_back_clicked();

    void on_add_clicked();

private:
    Ui::addloc *ui;
    int socket;
    string buff;
    char raspuns[255];
    void addLoc();
};

#endif // ADDLOC_H
