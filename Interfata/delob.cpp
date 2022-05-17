#include "delob.h"
#include "ui_delob.h"

delOb::delOb(int sock,string str,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delOb)
{
    ui->setupUi(this);
    socket=sock;
    del=str;
    QString str1="Stergere "+QString::fromStdString(del);
    ui->label_2->setText(str1);
}

delOb::~delOb()
{
    delete ui;
}

void delOb::on_pushButton_2_clicked()
{
    windowsInstances::create_Instance(socket)->hide_del();
    windowsInstances::create_Instance(socket)->show_adminmeniu();
}

void delOb::delFunc(){
    QString junk=ui->lineEdit->text();
    if(del=="Obiective turistice")
    {
        buff="DelObj";
    }
    if(del=="Locatii")
    {
        buff="DelLoc";
    }
    if(del=="Transport")
    {
        buff="DelTrans";
    }
    buff+="|";
    buff+=junk.toLocal8Bit().constData();
    buff+="|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;
    if(buff=="yes"){
        QMessageBox::information(this,del.c_str(),"Stergere efectuata cu succes !");
        windowsInstances::create_Instance(socket)->hide_del();
        windowsInstances::create_Instance(socket)->show_adminmeniu();
    }
    else{
        QMessageBox::information(this,del.c_str(),"Eroare! Stergere neefectuata!");
        this->show();
    }
}
void delOb::on_pushButton_clicked()
{
    delFunc();
}

