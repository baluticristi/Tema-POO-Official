#include "loginadmin.h"
#include "ui_loginadmin.h"

LoginAdmin::LoginAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}
