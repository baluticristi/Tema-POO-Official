#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H
#pragma once
#include <iostream>
#include <winsock.h>

#define PORT 54000      ///portul pentru listening

using namespace std;

class clientConnection
{
private:
    int nClientSocket;
    struct sockaddr_in srv;
    int nRet = 0;
    WSADATA ws;
    char buff[256] = { 0, };

public:
    clientConnection(){;}
    int enstablish_Connection();

};

#endif // CLIENTCONNECTION_H

