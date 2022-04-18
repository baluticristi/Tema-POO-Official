#pragma comment(lib, "Ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <WS2tcpip.h>

using namespace std;

void main() {

	//Facem o conexiune cu winsock 

	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	
	int wsok = WSAStartup(ver, &wsData);
	if (wsok != 0)
	{
		cerr << "Nu se mai poate cu winsock-ul asta, domne. Il terminam."<<endl;
		return;
	}

	//Cream un socket
	
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		cerr << "Nu merge cu socke-urile astea, domne"<<endl;
		return;
	}

	//Bind, legam socket la un ip si port

	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind(listening, (sockaddr*)&hint, sizeof(hint));

	//Spunem la wiwnsock socket-ul e de ascultat
	
	listen(listening, SOMAXCONN);

	//Asteptam conexiunea conexiunea
	
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];	 //numele clientului
	char service[NI_MAXSERV];//service port-client connection

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		cout << host << " connected on port " << service << endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		cout << host << " connected on port " << ntohs(client.sin_port) << endl;
	}

	//Inchidem socket-ul de ascultare

	closesocket(listening);

	//While loot, accemptam mesajele de la client si facem ceva

	char buff[4096];
	while (true) {
		ZeroMemory(buff, 4096);
		
		//wait for data
		int bytesReceived = recv(clientSocket, buff, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << " Eroare la recv()" << endl;
			break;
		}
		if (bytesReceived == 0) {
			cout << "Client disconnected" << endl;
			break;
		}


		//echo back data
				
		char response[4096];
		if (strcmp(buff, "Ce faci?")==0) strcpy(response, "Nimic coaie, tu?");
		else if(strcmp(buff, "Bine")==0) strcpy(response, "Nu mai vorbesc cu tine, uratule");
		else strcpy(response, buff);
		//echo back data
		bytesReceived = strlen(response);
		//cout << buff << " mesaj: BytesReceived: " << bytesReceived<<endl;
		send(clientSocket, response, bytesReceived + 1, 0);

	}

	//Inchidem socket
	closesocket(clientSocket);
	// Inchidem winsock

	WSACleanup();



}