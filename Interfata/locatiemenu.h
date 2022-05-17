#ifndef LOCATIEMENU_H
#define LOCATIEMENU_H
#include <QMessageBox>
#include <QWidget>
#include <iostream>
#include <windowsinstances.h>
#include <winsock.h>
#include <string>
#include <QString>

using namespace std;

namespace Ui {
class locatiemenu;
}

class locatiemenu : public QWidget
{
    Q_OBJECT

public:
    explicit locatiemenu(int,QWidget *parent = nullptr);
    void title_desc_func(string str);
    void make_rez();
    void lista_tr();
    ~locatiemenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::locatiemenu *ui;
    int socket;
    char raspuns[4096];
    string buff;
    string numeLoc;
    int count;

};

#endif // LOCATIEMENU_H
