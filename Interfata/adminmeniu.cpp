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
