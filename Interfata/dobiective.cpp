#include "dobiective.h"
#include "ui_dobiective.h"

dObiective::dObiective(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dObiective)
{
    socket=sock;
    ui->setupUi(this);
}

dObiective::~dObiective()
{
    delete ui;
}

void dObiective::on_pushButton_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_obiective();
}
void dObiective::detalii_ob(string str){
    ui->label->setText(QString::fromStdString(str));
    buff="DetaliiOb|"+str+"|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    int pos=0;
    string nume, judet,desc;
    pos = buff.find("|");
    nume = buff.substr(0, pos);
    buff.erase(0, pos + 1);
    pos = buff.find("|");
    judet=" Judet: ";
    judet += buff.substr(0, pos);
    buff.erase(0, pos + 1);
    pos = buff.find("|");
    desc += buff.substr(0, pos);
    buff.erase(0, pos + 1);
    buff=nume+"\n"+judet+"\n"+"Descriere: "+desc;
    ui->textBrowser->setText(QString::fromStdString(buff));
}

