#include "client.h"
#include "ui_client.h"

client::client(int sock, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    socket=sock;
    ui->setupUi(this);
}

client::~client()
{
    delete ui;
}
void client::ceck_pass(){
    pass=ui->passline->text();
    user=ui->userline->text();
    buff="Log";
    buff+="|";
    buff+=user.toLocal8Bit().constData();
    buff+="|";
    buff+=pass.toLocal8Bit().constData();
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;


    if (buff=="denied"){
        QMessageBox::information(this,"Logare","Nu ati reusit sa va logati !");
        this->show();
        buff.clear();
    }
    else {

        ///cod pentru nume si prenume
        if(user=="admin"){
        QMessageBox::information(this,"Logare","V-ati logat cu succes ca admin !");
        hide();
        windowsInstances::create_Instance(socket)->show_adminmeniu();}
        else{
            int pos=0;
            string nume, prenume;
            QString message="V-ati logat cu succes ca " +user+ "!";
            for (int i = 0; i < 2; i++) {
                pos = buff.find("|");
                nume = buff.substr(0, pos);
                buff.erase(0, pos + 1);
            }
            pos = buff.find("|");
            prenume = buff.substr(0, pos);
            buff.erase(0, pos + 1);
            QMessageBox::information(this,"Logare",message);
            hide();
            windowsInstances::create_Instance(socket)->add_nume_prenume_titlu(QString::fromStdString(nume),QString::fromStdString(prenume));
            windowsInstances::create_Instance(socket)->show_clientmenu();
        }
    }

}




void client::on_loginButton_clicked()
{
    ceck_pass();
}


void client::on_pushButton_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_signin();
}

