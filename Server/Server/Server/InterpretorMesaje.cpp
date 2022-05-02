#define _CRT_SECURE_NO_WARNINGS
#include "InterpretorMesaje.h"
#include "CCodificator.h"

void InterpretorMesaje::Interpreteaza(string buff, SOCKET clientSocket)
{
	string checker= buff.substr(0, buff.find("|"));
	if (checker == "Auth") SendAnswer("Autentificare", clientSocket);
	else if (checker == "Reg") SendAnswer(SignUp(buff), clientSocket);
	else if (checker == "Log") SendAnswer(CheckCredentials(buff),clientSocket);
	else EchoBack(buff, clientSocket);

}

string InterpretorMesaje::CheckCredentials(string credentials)
{
	CCodificator cryptoman;
	string connectionDetails;
	int pos = 0;
	string username, password;
	//Scoatem username si password
	for (int i = 0; i < 2; i++)
	{
		pos = credentials.find("|");
		username = credentials.substr(0, pos);
		credentials.erase(0, pos + 1);
	}
	pos = credentials.find("|");
	password = credentials.substr(0, pos);
	credentials.erase(0, pos + 1);

    //Pull from database, whenever we'll have one...
	string dpassword;

	//cerem parola apoi comparam str cu password pentru username.
	string querystring= "SELECT parola FROM DateConectare WHERE username='";
	querystring += username;
	querystring += "'";

	dpassword = DataDeBaze.MakeARequestQuery(querystring);
	cout << "User "<<username<<" conectat cu succes\n";

	//verify if same
	password += "|";
	if (password == dpassword) connectionDetails = "connected";
	else connectionDetails = "denied";


	/*
	bool ok = false;
	string checker ;
	while ((pos = credentials.find("|")) != std::string::npos) {
		checker = credentials.substr(0, pos);
		credentials.erase(0, pos + 1);
		if(ok) {
			if (checker == "admin") checker = "ADMINISTRATOR";
			connectionDetails += checker;
			connectionDetails += "|";
		}
		ok = true;//ca sa nu luam prima parte
		//codul pentru comanda
	}
	*/
	
	return connectionDetails;
}

string InterpretorMesaje::SignUp(string credentials)
{
	CCodificator cryptoman;
	string Verdict;
	int pos = 0;
	string username, password,Nume, Prenume;
	//Scoatem username si password

	for (int i = 0; i < 2; i++)
	{
		pos = credentials.find("|");
		username = credentials.substr(0, pos);
		credentials.erase(0, pos + 1);
	}

	pos = credentials.find("|");
	password = credentials.substr(0, pos);
	credentials.erase(0, pos + 1);

	pos = credentials.find("|");
	Nume = credentials.substr(0, pos);
	credentials.erase(0, pos + 1);

	pos = credentials.find("|");
	Prenume = credentials.substr(0, pos);
	credentials.erase(0, pos + 1);
	string querystring = "SELECT parola FROM DateConectare WHERE username='";
	querystring += username;
	querystring += "'";
	string verify = DataDeBaze.MakeARequestQuery(querystring);

	//verificam daca exista username, parola, nume si returnam pe baza a ce am zis
	if (verify==""){
		if (username.size() > 3) {
			if(password.size() > 3){
				if (Nume.size() != 0) {
					querystring = "INSERT INTO DateConectare ( username, parola, Nume, Prenume ) VALUES ( '";//admin', 'admin', 'Administrator', 'Sistem')";
					querystring += username;
					querystring += "', '";
					querystring += password;
					querystring += "', '";
					querystring += Nume;
					querystring += "', '";
					querystring += Prenume;
					querystring += "' )";
					DataDeBaze.MakeASendQuery(querystring);

					Verdict = "created";
				}
				else Verdict = "nume";
			}
			else Verdict = "parola";
		}
		else Verdict = "username";
	}

	else Verdict = "denied";

	return Verdict;
}

string InterpretorMesaje::EchoBack(string buff, SOCKET clientSocket)
{
	//echo back data
	SendAnswer(buff, clientSocket);
	return string();
}

void InterpretorMesaje::SendAnswer(string response, SOCKET client)
{
	cout << "Am trimis: " << response << endl;
	send(client, response.c_str(), response.size() + 1, 0);
}
