#include "windowsinstances.h"

windowsInstances* windowsInstances::instance = nullptr;
windowsInstances::windowsInstances(int sock)
{
    socket=sock;
    count_tr=0;
    count_ist=0;
    Ma=new adminmeniu(sock);

    Lc=new client(sock);
    sign=new sign_in(sock);
    Mc=new clientmenu(sock);
    lista_locatii=new listaLocatii(socket);
    lista_tr=new listatransport(socket);
    ob_tur =new oblictiveTuristice(socket);
    loc_menu=new locatiemenu(socket);
    ist_client=new istoricClient(socket);
    detalii_obiective=new dObiective(socket);
    detalii_trans=new dTrans(socket);
    add_loc=new addloc(socket);
    add_ob =new addobiective(socket);
    add_tr=new addtrans(socket);

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
    delete instance->Lc;
    delete instance->Ma;
    delete instance->sign;
    delete ist_client;
    instance=nullptr;
}

void windowsInstances::show_adminmeniu(){
    Ma->show();
}

void windowsInstances::show_logareclient(){
    Lc->show();
}
void windowsInstances::hide_adminmeniu(){
    Ma->hide();
    restore_after_admin();
}

void windowsInstances::hide_logareclient(){
    Lc->hide();
}

void windowsInstances::show_signin(){
    sign->show();
}
void windowsInstances::hide_signin(){
    sign->hide();
}
void windowsInstances::show_clientmenu(){
    Mc->show();
}
void windowsInstances::hide_clientmenu(){
    Mc->hide();
}
void windowsInstances::add_nume_prenume_titlu(QString n,QString p){
    Mc->nume_prenume(n,p);
}
void windowsInstances::show_lista_locatii(){
    lista_locatii->show();
}
void windowsInstances::hide_lista_locatii(){
    lista_locatii->hide();
}
void windowsInstances::show_listatransport(){
    lista_tr->show();
}
void windowsInstances::hide_listatransport(){
    lista_tr->hide();
}
void windowsInstances::show_istoricClient(){
    ist_client->show();
    ist_client->adauga_lista_ist();
}
void windowsInstances::hide_istoricClient(){
    ist_client->hide();

}
void windowsInstances::show_obiective(){
    ob_tur->show();
}
void windowsInstances::hide_obiective(){
    ob_tur->hide();
}
void windowsInstances::show_del(string str){
    del=new delOb(socket,str);
    del->show();
}
void windowsInstances::hide_del(){
    del->hide();
}
void windowsInstances::show_loc_menu(){
    loc_menu->show();
    if(count_tr<1){
    loc_menu->lista_tr();
    count_tr++;
    }
}
void windowsInstances::hide_loc_menu(){
    loc_menu->hide();
}
void windowsInstances::title_desc_func(string str){
    loc_menu->title_desc_func(str);
}

void windowsInstances::show_dObiective(string str){
    detalii_obiective->show();
    detalii_obiective->detalii_ob(str);
}

void windowsInstances::show_dTrans(string str){
    detalii_trans->show();
    detalii_trans->detalii_tr(str);
}
void windowsInstances::hide_dTrans(){
    detalii_trans->hide();
}
void windowsInstances::restore_after_admin(){
    delete lista_locatii;
    delete lista_tr;
    delete ob_tur;
    delete loc_menu;
    lista_locatii=new listaLocatii(socket);
    lista_tr=new listatransport(socket);
    ob_tur =new oblictiveTuristice(socket);
    loc_menu=new locatiemenu(socket);
}
void windowsInstances::show_add_loc(){
    add_loc->show();
}
void windowsInstances::hide_add_loc(){
    add_loc->hide();
}
void windowsInstances::show_add_ob(){
    add_ob->show();
}
void windowsInstances::hide_add_ob(){
    add_ob ->hide();
}
void windowsInstances::show_add_tr(){
    add_tr->show();
}
void windowsInstances::hide_add_tr(){
    add_tr->hide();
}
