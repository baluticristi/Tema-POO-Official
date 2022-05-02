#include "loginadmin.h"
#include "ui_loginadmin.h"

LoginAdmin::LoginAdmin(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
    socket=sock;
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}

void LoginAdmin::ceck_pass(){
    pass=ui->adminpass->text();
    buff="Log";
    buff+="|";
    buff+="admin|";
    buff+=pass.toLocal8Bit().constData();
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;

    if(buff=="connected")
    {
        QMessageBox::information(this,"Logare","V-ati logat cu succes ca admin !");
        windowsInstances::create_Instance(socket)->hide_logareadmin();
        buff.clear();
        windowsInstances::create_Instance(socket)->show_adminmeniu();
    }
    else if(buff=="denied"){
        QMessageBox::information(this,"Logare","Nu ati reusit sa va logati !");
        this->show();
        buff.clear();
    }

}


void LoginAdmin::on_log_clicked()
{
    ceck_pass();
}


void LoginAdmin::on_mainwind_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_MainWindow();
}

