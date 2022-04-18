#include "mainwindow.h"
#include "clientconnection.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    clientConnection C;

    int value=C.enstablish_Connection();
    MainWindow w(value);
    w.show();

    return a.exec();
}
