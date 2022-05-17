#include "oblictiveturistice.h"
#include "ui_oblictiveturistice.h"

oblictiveTuristice::oblictiveTuristice(int sock, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::oblictiveTuristice)
{
    count=0;
    ui->setupUi(this);
    socket=sock;
    if(count<1){
    adauga_lista();
}}

oblictiveTuristice::~oblictiveTuristice()
{
    delete ui;
}

void oblictiveTuristice::on_pushButton_clicked()
{
    windowsInstances::create_Instance(socket)->hide_obiective();
    windowsInstances::create_Instance(socket)->show_clientmenu();
}
void oblictiveTuristice::adauga_lista(){
    buff="Obiective|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 255, 0);
    buff=raspuns;
    int pos=0;
    int n=0;
    string nume, judet;
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
        judet=" Judet: ";
        judet += buff.substr(0, pos);
        buff.erase(0, pos + 1);

        QString label=QString::fromStdString(nume);
        ui->listWidget->addItem(label);
    }
}


void oblictiveTuristice::on_listWidget_doubleClicked(const QModelIndex &index)
{
    windowsInstances::create_Instance(socket)->show_dObiective(index.data().toString().toStdString());
    hide();
}

