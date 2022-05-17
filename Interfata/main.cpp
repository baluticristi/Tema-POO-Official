#include "clientconnection.h"
#include "windowsinstances.h"
#include <QApplication>
#include <QFile>


int main(int argc, char *argv[])
{
    QFile styleSheetFile("C:/Users/danda/OneDrive/Documents/GitHub/Tema-POO/Interfata/Toolery.qss");
    if(!styleSheetFile.open(QFile::ReadOnly))
    {qDebug("nup");}


    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    QApplication a(argc, argv);
    a.setStyleSheet(styleSheet);

    clientConnection C;

    int value=C.enstablish_Connection();
    windowsInstances*interfata = windowsInstances::create_Instance(value);
    interfata->show_logareclient();

    return a.exec();
}
