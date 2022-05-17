#include "CConexiune.h"
#include "InterpretorMesaje.h"

void CConexiune::CreazaSocketAscultare()
{
	listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET) {
		std::cout << "Socket invalid, nu merge" << std::endl;
		return;
	}
}

void CConexiune::StabilesteConexiuneWinSock()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);

	int wsok = WSAStartup(ver, &wsData);
	if (wsok != 0)
	{
		std::cout << "Winsock-ul asta. Il terminam." << std::endl;
	}
}

void CConexiune::BindIpPort()
{
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	bind(listening, (sockaddr*)&hint, sizeof(hint));
}

void CConexiune::StartListening()
{
	listen(listening, SOMAXCONN);
}

void CConexiune::StabilesteConexiuneClient()
{
	int clientSize = sizeof(client);

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	char host[NI_MAXHOST];	 //numele clientului
	char service[NI_MAXSERV];//service port-client connection

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
	{
		std::cout << host << " connected on port " << service << std::endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
		std::cout << host << " connected on port " << ntohs(client.sin_port) << std::endl;
	}

}

void CConexiune::InchidePortAscultare()
{
	closesocket(listening);
}

void CConexiune::MentineConexiunea()
{	
	
	InterpretorMesaje postas(DataDeBaza,User);

	char buff[4096];
	//realizam conexiunea la baza de date

	while (true) {
		ZeroMemory(buff, 4096);
		//wait for data
		int bytesReceived = recv(clientSocket, buff, 4096, 0);
		if (bytesReceived == SOCKET_ERROR)
		{
			break;
		}
		if (bytesReceived == 0) {
			break;
		}
		
		//interpretam ceea ce am primit
		cout << "Am primit : " << buff << endl;
		postas.Interpreteaza(buff, clientSocket);
			

	}


}

void CConexiune::InchidePortClient()
{
	std::cout << "Client disconnected" << std::endl;
	closesocket(clientSocket);

}
