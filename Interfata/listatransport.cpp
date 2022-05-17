#include "listatransport.h"
#include "ui_listatransport.h"

listatransport::listatransport(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listatransport)
{
    ui->setupUi(this);
    socket=sock;
    adauga_lista();
}

listatransport::~listatransport()
{
    delete ui;
}

void listatransport::on_pushButton_clicked()
{
    windowsInstances::create_Instance(socket)->hide_listatransport();
    windowsInstances::create_Instance(socket)->show_clientmenu();
}
void listatransport::adauga_lista(){
    buff="Transport|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    int pos=0;
    int n=0;
    string nume, viteza;
    pos = buff.find("|");
    nume = buff.substr(0, pos);
    n=QString::fromStdString(nume).toInt();
    nume.clear();
    buff.erase(0, pos + 1);
    for (int i = 0; i < n; i++) {
        pos = buff.find("|");
        nume = buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        viteza=" Viteza: ";
        viteza += buff.substr(0, pos);
        buff.erase(0, pos + 1);

        QString label=QString::fromStdString(nume);
        ui->listWidget->addItem(label);
    }
}





void listatransport::on_listWidget_doubleClicked(const QModelIndex &index)
{
     windowsInstances::create_Instance(socket)->show_dTrans(index.data().toString().toStdString());
     hide();

}

