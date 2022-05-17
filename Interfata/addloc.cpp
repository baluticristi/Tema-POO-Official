#include "addloc.h"
#include "ui_addloc.h"

addloc::addloc(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addloc)
{
    socket=sock;
    ui->setupUi(this);
}

addloc::~addloc()
{
    delete ui;
}

void addloc::on_back_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_adminmeniu();
}


void addloc::on_add_clicked()
{
    addLoc();
}
void addloc::addLoc(){
buff="AddLoc|";
QString nume, judet, stele,camere, desc;
nume=ui->lineEdit->text()+"|";
judet=ui->lineEdit_2->text()+"|";
camere=ui->lineEdit_3->text()+"|";
stele=ui->lineEdit_4->text()+"|";
desc=ui->textEdit->toPlainText()+"|";
buff+=nume.toStdString()+camere.toStdString()+stele.toStdString()+judet.toStdString()+desc.toStdString();
send(socket,buff.c_str(),buff.length(),0);
recv(socket, raspuns, 255, 0);
buff=raspuns;
if(buff=="yes"){
     QMessageBox::information(this,"Succes!","Ati adaugat o noua locatie cu succes!");
     hide();
     windowsInstances::create_Instance(socket)->show_adminmeniu();
}
else if(buff=="nume"){
    QMessageBox::information(this,"Error!","Numele locatiei este prea scurt!");
    this->show();
}
else if(buff=="camere"){
    QMessageBox::information(this,"Error!","Sunt prea putine camere!");
    this->show();
}
else if(buff=="stele"){
    QMessageBox::information(this,"Error!","Numar stele incorect!");
    this->show();
}
else if(buff=="judet"){
    QMessageBox::information(this,"Error!","Numele judetului locatiei este prea scurt!");
    this->show();
}
else if(buff=="descriere"){
    QMessageBox::information(this,"Error!","Descrierea locatiei este prea scurt!");
    this->show();
}
else if(buff=="no"){
    QMessageBox::information(this,"Error!","Erare la adaugare, incercati mai tarziu!");
    this->show();
}

}
