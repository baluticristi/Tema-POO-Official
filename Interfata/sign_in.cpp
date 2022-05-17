#include "sign_in.h"
#include "ui_sign_in.h"

sign_in::sign_in(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sign_in)
{
    ui->setupUi(this);
    socket=sock;
}

sign_in::~sign_in()
{
    delete ui;
}
void sign_in::signIn(){
    buff+="Reg|";
    pass=ui->passline->text();
    user=ui->userline->text();
    nume=ui->nameline->text();
    prenume=ui->prenumeline->text();
    buff+=user.toLocal8Bit().constData();
    buff+="|";
    buff+=pass.toLocal8Bit().constData();
    buff+="|";
    buff+=nume.toLocal8Bit().constData();
    buff+="|";
    buff+=prenume.toLocal8Bit().constData();
    buff+="|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;
    if(buff=="created"){
        QMessageBox::information(this,"Cont Creat","V-ati creat un cont cu succes !");
        hide();
        windowsInstances::create_Instance(socket)->show_logareclient();
        buff.clear();
    }
    else if(buff=="denied"){
         QMessageBox::information(this,"Cont existent","Nu v-ati creat un cont cu succes deoarece mai exista un cont cu acelasi username!");
         this->show();
         buff.clear();
    }
    else if(buff=="username"){
        QMessageBox::information(this,"Gresala creare cont","Nu v-ati creat un cont cu succes deoarece username-ul este prea scurt");
        this->show();
        buff.clear();

    }
    else if(buff=="parola"){
        QMessageBox::information(this,"Gresala creare cont","Nu v-ati creat un cont cu succes deoarece parola este prea scurta");
        this->show();
        buff.clear();
    }
    else if(buff=="nume"){
        QMessageBox::information(this,"Gresala creare cont","Nu v-ati creat un cont cu succes deoarece nu ati completat numele");
        this->show();
        buff.clear();
    }

}

void sign_in::on_creaza_Button_clicked()
{
    signIn();
}


void sign_in::on_back_to_login_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_logareclient();
}

