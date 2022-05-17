#include "listalocatii.h"
#include "ui_listalocatii.h"

listaLocatii::listaLocatii(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listaLocatii)
{
    ui->setupUi(this);
    socket=sock;
    count=0;
    if(count<1){
    adauga_lista();
    count++;
    }
}

listaLocatii::~listaLocatii()
{
    delete ui;
}

void listaLocatii::on_pushButton_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_clientmenu();
}

void listaLocatii::adauga_lista(){
    buff="Locatii|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    int pos=0;
    int n=0;
    string nume, nrcamere, stele,judet;
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
        nrcamere=" Camere: ";
        nrcamere += buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        stele += " Stele :";
        stele += buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        judet =" Judetul: ";
        judet += buff.substr(0, pos);
        buff.erase(0, pos + 1);

        QString label=QString::fromStdString(nume);
        ui->listWidget->addItem(label);
    }
}


void listaLocatii::on_listWidget_doubleClicked(const QModelIndex &index)
{
    windowsInstances::create_Instance(socket)->show_loc_menu();
    windowsInstances::create_Instance(socket)->title_desc_func(index.data().toString().toStdString());
    //index.data().toString().toStdString()
    windowsInstances::create_Instance(socket)->hide_lista_locatii();


}

