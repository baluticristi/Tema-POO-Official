#include "locatiemenu.h"
#include "ui_locatiemenu.h"

locatiemenu::locatiemenu(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::locatiemenu)
{
    ui->setupUi(this);
    socket=sock;
    count=0;
}

locatiemenu::~locatiemenu()
{
    delete ui;
}

void locatiemenu::title_desc_func(string str){
    numeLoc=str;
    buff="DetaliiLoc|"+numeLoc+"|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    int pos=0;
    string nume, nrcamere, stele,judet, desc;
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
    pos = buff.find("|");
    desc += buff.substr(0, pos);
    buff.erase(0, pos + 1);
    ui->LocName->setText(QString::fromStdString(nume));
    buff=nume+"\n"+nrcamere+"\n"+stele+"\n"+judet+"\n"+"Descriere: "+desc;
    ui->desc->setText(QString::fromStdString(buff));
    buff.clear();
}
void locatiemenu::on_pushButton_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_lista_locatii();

}

void locatiemenu::lista_tr(){
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

        ui->comboBox->addItem(QString::fromStdString(nume));
    }
}


void locatiemenu::make_rez(){
    QString Intrare, Iesire, Transp, oraTrans;
    Intrare=ui->dateEdit->text();
    Intrare.replace("\/","\.");
    Iesire=ui->dateEdit_2->text();
    Iesire.replace("\/","\.");
    Transp=ui->comboBox->currentText();
    oraTrans=ui->dateEdit_3->text();
    oraTrans.replace("\/","\.");
    buff="RLoc|"+numeLoc+"|"+Intrare.toStdString()+"|"+Iesire.toStdString()+"|"+Transp.toStdString()+"|"+oraTrans.toStdString()+"|";
    send(socket,buff.c_str(),buff.length(),0);
    recv(socket, raspuns, 4096, 0);
    buff=raspuns;
    if(buff=="good"){
        QMessageBox::information(this,"Distractie placuta!","Rezervarea dumneavoastra a fost realizata cu succes!");
        hide();
        windowsInstances::create_Instance(socket)->show_clientmenu();
        buff.clear();
    }
    else if(buff=="locuri"){
        QMessageBox::information(this,"Ups","Nu mai exista locuri disponibile la aceasta locatie!");
        hide();
        windowsInstances::create_Instance(socket)->show_clientmenu();
        buff.clear();

    }
    else if(buff=="data"){
        QMessageBox::information(this,"Gresala la data","Aveti inversata data de plecare cu cea de sosire");
        this->show();
        buff.clear();
    }
    else if(buff=="transport"){
        QMessageBox::information(this,"Gresala la data","Aveti data transportului incorecta!");
        this->show();
        buff.clear();
    }

}
void locatiemenu::on_pushButton_2_clicked()
{
    make_rez();
}

