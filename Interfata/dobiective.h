#ifndef DOBIECTIVE_H
#define DOBIECTIVE_H

#include <QWidget>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <winsock.h>
#include <windowsinstances.h>

using namespace std;
namespace Ui {
class dObiective;
}

class dObiective : public QWidget
{
    Q_OBJECT

public:
    explicit dObiective(int,QWidget *parent = nullptr);
    void detalii_ob(string str);
    ~dObiective();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dObiective *ui;
    string buff;
    char raspuns[4096];
    int socket;
};

#endif // DOBIECTIVE_H
