#include "addtrans.h"
#include "ui_addtrans.h"

addtrans::addtrans(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addtrans)
{
    socket=sock;
    ui->setupUi(this);
}

addtrans::~addtrans()
{
    delete ui;
}

void addtrans::on_add_clicked()
{
    addTr();
}


void addtrans::on_back_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_adminmeniu();
}
void addtrans::addTr(){
    buff="AddTrans|";
    QString nume, viteza,desc;
    nume=ui->lineEdit->text()+"|";
    viteza=ui->lineEdit_2->text()+"|";
    desc=ui->textEdit->toPlainText()+"|";
    buff+=nume.toStdString()+viteza.toStdString()+desc.toStdString();
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;
    if(buff=="yes"){
         QMessageBox::information(this,"Succes!","Ati adaugat o noua modalitate de transport cu succes!");
         hide();
         windowsInstances::create_Instance(socket)->show_adminmeniu();
    }
    else if(buff=="nume"){
        QMessageBox::information(this,"Error!","Numele transportului este prea scurt!");
        this->show();
    }

    else if(buff=="viteza"){
        QMessageBox::information(this,"Error!","Viteza transportului este prea mica!");
        this->show();
    }
    else if(buff=="descriere"){
        QMessageBox::information(this,"Error!","Descrierea transportului este prea scurta!");
        this->show();
    }
    else if(buff=="no"){
        QMessageBox::information(this,"Error!","Erare la adaugare, incercati mai tarziu!");
        this->show();
    }
}

