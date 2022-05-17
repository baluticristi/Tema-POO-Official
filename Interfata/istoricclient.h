#ifndef ISTORICCLIENT_H
#define ISTORICCLIENT_H

#include <QWidget>
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
class istoricClient;
}

class istoricClient : public QWidget
{
    Q_OBJECT

public:
    explicit istoricClient(int,QWidget *parent = nullptr);
    ~istoricClient();
    void adauga_lista_ist();

private slots:
    void on_pushButton_clicked();

private:
    Ui::istoricClient *ui;
    int socket;
    string buff;
    char raspuns[4096];
    int count;
};

#endif // ISTORICCLIENT_H
