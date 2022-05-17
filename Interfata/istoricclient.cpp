#include "istoricclient.h"
#include "ui_istoricclient.h"

istoricClient::istoricClient(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::istoricClient)
{
    ui->setupUi(this);
    socket=sock;
    count=0;
}

istoricClient::~istoricClient()
{
    delete ui;
}
void istoricClient::adauga_lista_ist(){
    buff="Istoric|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    int pos=0;
    int n=0;
    string nume, dasaSosire,dataPlecare,transport,dataTransport;
    pos = buff.find("|");
    nume = buff.substr(0, pos);
    if(nume=="error")
    {
                windowsInstances::create_Instance(socket)->hide_istoricClient();
        QMessageBox::information(this,"NU exista istoric personal!","Eroare");
        windowsInstances::create_Instance(socket)->show_clientmenu();
    }
    else{
    n=QString::fromStdString(nume).toInt();
    nume.clear();
    buff.erase(0, pos + 1);
    QString label="\tIstoric:\n\n";
    for (int i = 0; i < n; i++) {
        pos = buff.find("|");
        nume=QString::number(i+1).toStdString()+". ";
        nume = buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        dasaSosire=" \nData sosire: ";
        dasaSosire += buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        dataPlecare=" \nData plecare: ";
        dataPlecare += buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        transport=" \nTransport: ";
        transport += buff.substr(0, pos);
        buff.erase(0, pos + 1);
        pos = buff.find("|");
        dataTransport=" \nData plecare: ";
        dataTransport += buff.substr(0, pos);
        buff.erase(0, pos + 1);


        label+=QString::fromStdString(nume+dasaSosire+dataPlecare+transport+dataTransport)+"\n\n";
    }
    ui->textBrowser->setText(label);
}
}

void istoricClient::on_pushButton_clicked()
{
     windowsInstances::create_Instance(socket)->hide_istoricClient();
     windowsInstances::create_Instance(socket)->show_clientmenu();
}

