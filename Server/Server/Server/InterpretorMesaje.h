#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include "CDatabase.h"

using namespace std;

class InterpretorMesaje
{
private:
	CDatabase DataDeBaze;
public:
	InterpretorMesaje(CDatabase &baza) { DataDeBaze = baza; };
	void Interpreteaza(string buff, SOCKET clientSocket);
	string CheckCredentials(string credentials);
	string SignUp(string credentials);
	string EchoBack(string buff, SOCKET clientSocket);
	void SendAnswer(string response, SOCKET client);
};

