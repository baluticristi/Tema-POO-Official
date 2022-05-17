#include "dtrans.h"
#include "ui_dtrans.h"

dTrans::dTrans(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dTrans)
{
    socket=sock;
    ui->setupUi(this);
}

dTrans::~dTrans()
{
    delete ui;
}

void dTrans::on_pushButton_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_listatransport();
}
void dTrans::detalii_tr(string str){
    ui->label->setText(QString::fromStdString(str));
    buff="DetaliiTran|"+str+"|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    int pos=0;
    string nume, viteza,desc;
    pos = buff.find("|");
    nume = buff.substr(0, pos);
    buff.erase(0, pos + 1);
    pos = buff.find("|");
    viteza=" Viteza: ";
    viteza += buff.substr(0, pos);
    buff.erase(0, pos + 1);
    pos = buff.find("|");
    desc += buff.substr(0, pos);
    buff.erase(0, pos + 1);
    buff=nume+"\n"+viteza+"\n"+"Descriere: "+desc;
    ui->textBrowser->setText(QString::fromStdString(buff));
}
