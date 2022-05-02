#include "windowsinstances.h"

windowsInstances* windowsInstances::instance = nullptr;
windowsInstances::windowsInstances(int sock)
{

    Ma=new adminmeniu(sock);
    LogA= new LoginAdmin(sock);
    Lc=new client(sock);
    ptr=new MainWindow(sock);
    socket=sock;
}
windowsInstances* windowsInstances::create_Instance(int sock){
    if(instance==nullptr)
    {
        instance=new windowsInstances(sock);
        return instance;
    }
    else return instance;
}
void windowsInstances::destroy_Instance(){
    delete instance->LogA;
    delete instance->Lc;
    delete instance->Ma;
    delete instance->ptr;
    instance=nullptr;
}

void windowsInstances::show_adminmeniu(){
    Ma->show();
}
void windowsInstances::show_logareadmin(){
    LogA->show();
}
void windowsInstances::show_logareclient(){
    Lc->show();
}
void windowsInstances::hide_adminmeniu(){
    Ma->hide();
}
void windowsInstances::hide_logareadmin(){
    LogA->hide();
}
void windowsInstances::hide_logareclient(){
    Lc->hide();
}
void windowsInstances::show_MainWindow(){
    ptr->show();
}
void windowsInstances::hide_MainWindow(){
    ptr->hide();
}

