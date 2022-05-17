#pragma once
#include <iostream>
#include <WS2tcpip.h>
#include "CDatabase.h"
#include "CUser.h"

using namespace std;

class InterpretorMesaje
{
private:
	CDatabase DataDeBaze;
	CUser User;
public:
	InterpretorMesaje(CDatabase &baza, CUser& user) { DataDeBaze = baza; User = user; };
	void Interpreteaza(string buff, SOCKET clientSocket);
	//LogMenu
	string CheckCredentials(string credentials);//Implementat
	string SignUp(string credentials);//Implementat
	string EchoBack(string buff, SOCKET clientSocket);//Implementat
	//Main menu
	string DisplayLocations();//Implementat
	string DisplayObjectives();//Implementat
	string DisplayTransport();//Implementat
	string IstoricUser();//Implementat
	//Context menu
	string DetaliiLoc(string buff);//Implementat
	string DetaliiTran(string buff);//Implementat
	string DetaliiObj(string buff);//Implementat
	string ReserveLoc(string buff);//Implementat
	//Admin Menu
	string AddLoc(string buff);//Implementat
	string AddTrans(string buff);//Implementat
	string AddObj(string buff);//Implementat
	string DelLoc(string buff);//Implementat
	string DelTrans(string buff);//Implementat
	string DelObj(string buff);//Implementat

	void SendAnswer(string response, SOCKET client);
	
	CDatabase getBaza() { return DataDeBaze; };
};

