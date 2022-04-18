#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientconnection.h"

MainWindow::MainWindow(int socket, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nClientSocket=socket;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Button click function

/*void MainWindow::on_ButonSaVadDacaMerge_clicked()
{
    clientConnection C;
    int value=0;
    value=C.sendInput("Bine");
}
*///work in progress......

