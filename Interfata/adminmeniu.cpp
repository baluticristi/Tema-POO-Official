#include "adminmeniu.h"
#include "ui_adminmeniu.h"

adminmeniu::adminmeniu(int sock ,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminmeniu)
{

    ui->setupUi(this);
    socket=sock;
}

adminmeniu::~adminmeniu()
{
    delete ui;
}

void adminmeniu::on_pushButton_clicked()
{
    windowsInstances::create_Instance(socket)->show_logareclient();
    windowsInstances::create_Instance(socket)->hide_adminmeniu();
}


void adminmeniu::on_delObiectiv_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_del("Obiective turistice");
}


void adminmeniu::on_pushButton_4_clicked()
{

    hide();
    windowsInstances::create_Instance(socket)->show_del("Transport");
}


void adminmeniu::on_delCazare_clicked()
{
    hide();
    windowsInstances::create_Instance(socket)->show_del("Locatii");
}


void adminmeniu::on_addObiectiv_clicked()
{
    hide();
        windowsInstances::create_Instance(socket)->show_add_ob();
}


void adminmeniu::on_addTransport_clicked()
{
    hide();
        windowsInstances::create_Instance(socket)->show_add_tr();
}


void adminmeniu::on_addCazare_clicked()
{
    hide();
        windowsInstances::create_Instance(socket)->show_add_loc();
}

