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
    if(pass.size()<3)
    {
        QMessageBox::information(this,"Logare","Nu ati reusit sa va logati !");
        this->show();
    }
    {
    buff+=pass.toLocal8Bit().constData();
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;


    if(buff=="connected")
    {

        if(user=="admin"){
        QMessageBox::information(this,"Logare","V-ati logat cu succes ca admin !");
        hide();
        windowsInstances::create_Instance(socket)->show_adminmeniu();}
        else{
            hide();
        }
    }
    else if(buff=="denied"){
        QMessageBox::information(this,"Logare","Nu ati reusit sa va logati !");
        this->show();
        buff.clear();
    }
    }

}

void client::on_loginButton_clicked()
{
    ceck_pass();
}

