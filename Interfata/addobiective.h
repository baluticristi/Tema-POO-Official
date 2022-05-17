#ifndef ADDOBIECTIVE_H
#define ADDOBIECTIVE_H

#include <QWidget>
#include <iostream>
#include <windowsinstances.h>
#include <winsock.h>
#include <string>
#include <QString>
#include <QMessageBox>
using namespace std;
namespace Ui {
class addobiective;
}

class addobiective : public QWidget
{
    Q_OBJECT

public:
    explicit addobiective(int,QWidget *parent = nullptr);
    ~addobiective();

private slots:
    void on_add_clicked();

    void on_back_clicked();

private:
    Ui::addobiective *ui;
    int socket;
    string buff;
    char raspuns[255];
    void addOb();
};

#endif // ADDOBIECTIVE_H
