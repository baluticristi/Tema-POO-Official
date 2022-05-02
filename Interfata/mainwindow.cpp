#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientconnection.h"

MainWindow::MainWindow(int socket, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nClientSocket=socket;
//    QPixmap pix("C:/Users/danda/OneDrive/Documents/GitHub/Tema-POO/Interfata/img/Background.jpg");
//    pix=pix.scaled(this->size(),Qt::IgnoreAspectRatio);
//    QPalette pal;
//    this->centralWidget()->setStyleSheet(
//             "background-image:url(:/img/Background.jpg); background-position: center;" );
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::creare_admin(){
    hide();
    windowsInstances::create_Instance(nClientSocket)->show_logareadmin();
}

void MainWindow::creare_client()
{
    hide();
    windowsInstances::create_Instance(nClientSocket)->show_logareclient();
}
void MainWindow::on_pushButton_clicked()
{
    creare_admin();
}


void MainWindow::on_pushButton_2_clicked()
{
    creare_client();
}

