#ifndef WINDOWSINSTANCES_H
#define WINDOWSINSTANCES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "adminmeniu.h"
#include "client.h"
#include "loginadmin.h"
#include "mainwindow.h"
class LoginAdmin;
class MainWindow;
class client;

class windowsInstances
{
private:
    windowsInstances(int sock);
    ~windowsInstances();
    static windowsInstances* instance;
    int socket;
    adminmeniu* Ma;
    client* Lc;
    LoginAdmin* LogA;
    MainWindow* ptr;

public:

    void show_adminmeniu();
    void hide_adminmeniu();
    void show_logareclient();
    void hide_logareclient();
    void show_logareadmin();
    void hide_logareadmin();
    void show_MainWindow();
    void hide_MainWindow();
    static windowsInstances* create_Instance(int sock);
    void destroy_Instance();
};

#endif // WINDOWSINSTANCES_H
