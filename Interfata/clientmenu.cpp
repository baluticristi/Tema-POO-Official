#include "clientmenu.h"
#include "ui_clientmenu.h"

clientmenu::clientmenu(int sock,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientmenu)
{
    ui->setupUi(this);
    socket=sock;
}

clientmenu::~clientmenu()
{
    delete ui;
}
void clientmenu::nume_prenume(QString n, QString p){
    nume=n;
    prenume=p;
    QString buff="Bine ai venit "+nume+" "+prenume+"!";
    ui->titlu->setText(buff);
}

void clientmenu::on_pushButton_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_logareclient();
}


void clientmenu::on_locatii_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_lista_locatii();
}


void clientmenu::on_transport_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_listatransport();
}


void clientmenu::on_istoric_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_istoricClient();
}


void clientmenu::on_obiective_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_obiective();
}

