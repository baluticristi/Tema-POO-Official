#include "addobiective.h"
#include "ui_addobiective.h"

addobiective::addobiective(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addobiective)
{
    socket=sock;
    ui->setupUi(this);
}

addobiective::~addobiective()
{
    delete ui;
}

void addobiective::on_add_clicked()
{
 addOb();
}


void addobiective::on_back_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_adminmeniu();
}
void addobiective::addOb(){
    buff="AddObj|";
    QString nume, judet,desc;
    nume=ui->lineEdit->text()+"|";
    judet=ui->lineEdit_2->text()+"|";
    desc=ui->textEdit->toPlainText()+"|";
    buff+=nume.toStdString()+judet.toStdString()+desc.toStdString();
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;
    if(buff=="yes"){
         QMessageBox::information(this,"Succes!","Ati adaugat o noua atractie turistica cu succes!");
         hide();
         windowsInstances::create_Instance(socket)->show_adminmeniu();
    }
    else if(buff=="nume"){
        QMessageBox::information(this,"Error!","Numele obiectivului este prea scurt!");
        this->show();
    }

    else if(buff=="judet"){
        QMessageBox::information(this,"Error!","Numele judetului obiectivului este prea scurt!");
        this->show();
    }
    else if(buff=="descriere"){
        QMessageBox::information(this,"Error!","Descrierea obiectivului este prea scurta!");
        this->show();
    }
    else if(buff=="no"){
        QMessageBox::information(this,"Error!","Erare la adaugare, incercati mai tarziu!");
        this->show();
    }
}
