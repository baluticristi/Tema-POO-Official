#pragma once
#include "CConexiune.h"
#include "CUser.h"

using namespace std;

void main() {

	CUser user;
	CDatabase baza;
	baza.ConnectToDatabase();
	CConexiune con(baza,user);

	//Facem o conexiune cu winsock 
	con.StabilesteConexiuneWinSock();
	
	//Cream un socket
	con.CreazaSocketAscultare();

	//Bind, legam socket la un ip si port
	con.BindIpPort();

	//Spunem la wiwnsock socket-ul e de ascultat
	con.StartListening();
	while (true) {
		//Asteptam conexiunea conexiunea
		con.StabilesteConexiuneClient();

		//While loop, accemptam mesajele de la client si facem ceva
		con.MentineConexiunea();

		//Inchidem socket
		con.InchidePortClient();

	}
	// Inchidem winsock

	WSACleanup();



}