#pragma once
#include "CConexiune.h"


using namespace std;

void main() {

	CDatabase baza;
	baza.ConnectToDatabase();
	CConexiune con(baza);

	//Facem o conexiune cu winsock 
	con.StabilesteConexiuneWinSock();
	
	//Cream un socket
	con.CreazaSocketAscultare();

	//Bind, legam socket la un ip si port
	con.BindIpPort();

	//Spunem la wiwnsock socket-ul e de ascultat
	con.StartListening();

	//Asteptam conexiunea conexiunea
	con.StabilesteConexiuneClient();

	//Inchidem socket-ul de ascultare
	con.InchidePortAscultare();

	//While loop, accemptam mesajele de la client si facem ceva
	con.MentineConexiunea();

	//Inchidem socket
	con.InchidePortClient();

	// Inchidem winsock

	WSACleanup();



}