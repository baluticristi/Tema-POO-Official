#include "clientconnection.h"


////FUNCTIA DE CONEXIUNE LA SERVER
int clientConnection::enstablish_Connection()
{

    if (WSAStartup(MAKEWORD(2, 2), &ws) < 0)
    {
        cout << endl << "[ERROR]: WSAStartup fail...";
        WSACleanup();
        EXIT_FAILURE;
    }

    nClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (nClientSocket < 0)
    {
        cout << endl << "[ERROR]: Nu s-a putut apela socket-ul!";
        WSACleanup();
        EXIT_FAILURE;
    }

    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    std::string ip, check;


    srv.sin_addr.s_addr = inet_addr("172.20.10.14");


    memset(&srv.sin_zero, 0, 8);

    nRet = connect(nClientSocket, (struct sockaddr*)&srv, sizeof(srv));




    if (nRet < 0)
    {
        cout << endl << "[ERROR]: Nu s-a putut conecta!";
        WSACleanup();
        EXIT_FAILURE;
    }
    else
    {
        cout<<"M-am conectat"<<endl;
        //Aici incepe conexiunea
        return nClientSocket;
    }

    return 0;
}

//////////////////FUNCTIA DE TRIMITERE MESAJ///////
//int clientConnection::sendInput(string input){

//    int result=0;
//    ////trimite mesajul
//    result=send(nClientSocket, input.c_str(), input.size()+1, 0);

//    if(result!=SOCKET_ERROR){

//        /// asteapta pentru un raspuns
//        int bytesReceived = recv(nClientSocket,buff,255, 0 );

//        /// fa ceva cu raspunsul
//        if(bytesReceived>0){
//            cout<<"\n SERVER SAYS: "<<string(buff, 0, bytesReceived)<<endl;
//        }

//    }
//    else{
//        ///Handle the error
//        cout<<"\n[EROARE]: SOCKET ERROR;\n";
//    }

//    return 0;

//}
