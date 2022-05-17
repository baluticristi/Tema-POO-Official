#ifndef SIGN_IN_H
#define SIGN_IN_H

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
class sign_in;
}

class sign_in : public QWidget
{
    Q_OBJECT

public:
    explicit sign_in(int, QWidget *parent = nullptr);
    ~sign_in();
    void signIn();
private slots:
    void on_creaza_Button_clicked();

    void on_back_to_login_clicked();

private:
    Ui::sign_in *ui;
    int socket;
    string buff;
    QString pass, user, nume, prenume;
    char raspuns[4096];
};

#endif // SIGN_IN_H
