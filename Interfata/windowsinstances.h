#ifndef WINDOWSINSTANCES_H
#define WINDOWSINSTANCES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "adminmeniu.h"
#include "client.h"
#include "sign_in.h"
#include "clientmenu.h"
#include "listalocatii.h"
#include  "listatransport.h"
#include "istoricclient.h"
#include "oblictiveturistice.h"
#include "delob.h"
#include "locatiemenu.h"
#include "dobiective.h"
#include "dtrans.h"
#include "addloc.h"
#include "addobiective.h"
#include "addtrans.h"
class client;
class sign_in;
class clientmenu;
class listaLocatii;
class listatransport;
class istoricClient;
class oblictiveTuristice;
class delOb;
class adminmeniu;
class locatiemenu;
class dObiective;
class dTrans;
class addloc;
class addobiective;
class addtrans;

class windowsInstances
{
private:
    windowsInstances(int sock);
    ~windowsInstances();
    int socket;
    static windowsInstances* instance;
    adminmeniu* Ma;
    client* Lc;
    sign_in* sign;
    clientmenu* Mc;
    listaLocatii* lista_locatii;
    listatransport*lista_tr;
    istoricClient* ist_client;
    oblictiveTuristice* ob_tur;
    delOb *del;
    locatiemenu * loc_menu;
    dObiective* detalii_obiective;
    dTrans* detalii_trans;
    addloc* add_loc;
    addobiective* add_ob;
    addtrans*add_tr;
    int count_tr;
    int count_ist;

public:

    void show_adminmeniu();
    void hide_adminmeniu();
    void show_logareclient();
    void hide_logareclient();
    void show_clientmenu();
    void hide_clientmenu();
    void add_nume_prenume_titlu(QString n,QString p);
    void show_signin();
    void hide_signin();
    void show_lista_locatii();
    void hide_lista_locatii();
    void show_listatransport();
    void hide_listatransport();
    void show_istoricClient();
    void hide_istoricClient();
    void show_obiective();
    void hide_obiective();
    void show_del(string str);
    void hide_del();
    static windowsInstances* create_Instance(int sock);
    void destroy_Instance();
    void show_loc_menu();
    void hide_loc_menu();
    void show_dObiective(string str);
    void hide_dObiective();

    void show_dTrans(string str);
    void hide_dTrans();

    void show_add_loc();
    void hide_add_loc();
    void show_add_ob();
    void hide_add_ob();
    void show_add_tr();
    void hide_add_tr();

    void restore_after_admin();

    void title_desc_func(string str);
};

#endif // WINDOWSINSTANCES_H
