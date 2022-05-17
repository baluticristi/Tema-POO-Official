#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include "ICConexiune.h"
#pragma comment(lib, "Ws2_32.lib")
#include <WS2tcpip.h>
#include "CDatabase.h"
#include "CUser.h"

class CConexiune :
	public ICConexiune
{
private:
	SOCKET listening;
	SOCKET clientSocket;
	sockaddr_in client;
	CDatabase DataDeBaza;
	CUser User;
public:
	CConexiune(CDatabase& baza, CUser& user) { DataDeBaza = baza; User = user; };
	void StabilesteConexiuneWinSock();
	void CreazaSocketAscultare();
	void BindIpPort();
	void StartListening();
	void StabilesteConexiuneClient();
	void InchidePortAscultare();
	void InchidePortClient();
	void MentineConexiunea();

};

