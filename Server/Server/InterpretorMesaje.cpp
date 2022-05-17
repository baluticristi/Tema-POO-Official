#define _CRT_SECURE_NO_WARNINGS
#include "InterpretorMesaje.h"
#include "CCodificator.h"
#include <sstream>

string separa(string& old) {
	int pos = 0;
	pos = old.find("|");
	string ret = old.substr(0, pos);
	old.erase(0, pos + 1);
	return ret;
}
//FUNCTION OVERLOAD pe Select
string select(string select, string from, string where, string equals) {
	string querystring = "SELECT ";
	querystring += select;
	querystring += " FROM ";
	querystring += from;
	querystring += " WHERE ";
	querystring += where;
	querystring +="= '";
	querystring += equals;
	querystring += "'";

	return querystring;
}


string select(string select, string from) {
	string querystring = "SELECT ";
	querystring += select;
	querystring += " FROM ";
	querystring += from;

	return querystring;
}

string DeleteSQL(string del, string id, string nume) {
	string querystring = "DELETE FROM ";
	querystring += del;
	querystring += " WHERE " +del+"."+id+"='"+nume+"'";

	return querystring;

}
string insert(string insert, string campuri, string Valori) {
	string querystring = "INSERT INTO ";
	querystring += insert;
	querystring += "(";
	querystring += campuri;
	querystring += ") VALUES (";
	querystring += Valori;
	querystring += ")";

	return querystring;

}

void schimbaFormat(string& data) {
	string zi, luna, an;
	int pos = 0;
	pos = data.find(".");
	luna = data.substr(0, pos);
	data.erase(0, pos + 1);
	
	pos = data.find(".");
	zi = data.substr(0, pos);
	data.erase(0, pos + 1);
	an = data;
	if (zi.size() == 1) zi = "0" + zi;
	if (luna.size() == 1) luna = "0" + luna;
	data = an + "-" + luna + "-" + zi;


}

bool CheckDates(CDatabase& baza, string dataSosire, string dataPlecare, string idlocatie) {
	string DataS, DataP, check1, check2;
	int count = 0;
	DataS = baza.MakeARequestQuery(select("LocatiiDS", "Rezervari", "IDLocatie", idlocatie));
	DataP = baza.MakeARequestQuery(select("LocatiiDP", "Rezervari", "IDLocatie", idlocatie));
	
	schimbaFormat(dataSosire);
	schimbaFormat(dataPlecare);

	while (DataS.size() > 0) {
		check1 = separa(DataS);
		check2 = separa(DataP);
		if (check1 >= dataSosire && check2 <= dataPlecare) count++;
	}
	int camere;
	check1 = baza.MakeARequestQuery(select("NrCamere", "Locatii", "IDLocatie", idlocatie));
	if (count < stoi(check1))	return true;
	return false;
}


void InterpretorMesaje::Interpreteaza(string buff, SOCKET clientSocket)
{
	string checker= buff.substr(0, buff.find("|"));
	//LogMenu
	if (checker == "Reg") SendAnswer(SignUp(buff), clientSocket);
	else if (checker == "Log") SendAnswer(CheckCredentials(buff), clientSocket);
	//Main menu
	else if (checker == "Locatii") SendAnswer(DisplayLocations(), clientSocket); 
	else if (checker == "Obiective") SendAnswer(DisplayObjectives(), clientSocket); 
	else if (checker == "Transport") SendAnswer(DisplayTransport(), clientSocket);
	else if (checker == "Istoric") SendAnswer(IstoricUser(), clientSocket);
	//Context menu
	else if (checker == "DetaliiLoc") SendAnswer(DetaliiLoc(buff), clientSocket);
	else if (checker == "DetaliiTran") SendAnswer(DetaliiTran(buff), clientSocket);
	else if (checker == "DetaliiOb") SendAnswer(DetaliiObj(buff), clientSocket);
	else if (checker == "RLoc") SendAnswer(ReserveLoc(buff), clientSocket);
	//Admin Menu
	else if (checker == "AddLoc") SendAnswer(AddLoc(buff), clientSocket);
	else if (checker == "AddTrans") SendAnswer(AddTrans(buff), clientSocket);
	else if (checker == "AddObj") SendAnswer(AddObj(buff), clientSocket);
	else if (checker == "DelLoc") SendAnswer(DelLoc(buff), clientSocket);
	else if (checker == "DelTrans") SendAnswer(DelTrans(buff), clientSocket);
	else if (checker == "DelObj") SendAnswer(DelObj(buff), clientSocket);
	else EchoBack(buff, clientSocket);
}

string InterpretorMesaje::CheckCredentials(string credentials)
{
	string connectionDetails;
	int pos = 0;
	string username, password;
	//Scoatem username si password

	for (int i = 0; i < 2; i++)
	{
		username = separa(credentials);
	}
	password = separa(credentials);
	password = Cripteaza(password);
	string dpassword;
	//cerem parola apoi comparam str cu password pentru username.
	dpassword = DataDeBaze.MakeARequestQuery(select("parola", "DateConectare", "username", username));

	string id;
	id = DataDeBaze.MakeARequestQuery(select("IDUser","DateConectare","username",username));

	//verify if same
	password += "|";
	if (password == dpassword) {
		connectionDetails = "connected|";
		string Nume;

		Nume = DataDeBaze.MakeARequestQuery(select("Nume", "DateConectare", "username", username));

		connectionDetails += Nume;

		Nume = DataDeBaze.MakeARequestQuery(select("Prenume", "DateConectare", "username", username));

		connectionDetails += Nume;

		cout << "User " << username << " conectat cu succes\n";
		id += username + "|";
		User.Connect(id);
	}

	else connectionDetails = "denied";

	return connectionDetails;
}

string InterpretorMesaje::SignUp(string credentials)
{
	string Verdict;
	int pos = 0;
	string username, password,Nume, Prenume;
	//Scoatem username si password

	for (int i = 0; i < 2; i++)
	{
		username = separa(credentials);
	}
	password = separa(credentials);

	Nume = separa(credentials);
	
	Prenume = separa(credentials);

	string verify = DataDeBaze.MakeARequestQuery(select("parola", "DateConectare", "username", username));

	//verificam daca exista username, parola, nume
	if (verify==""){
		if (username.size() > 3) {
			if(password.size() > 3){
				if (Nume.size() != 0) {
					password =Cripteaza(password);
					string querystring = "INSERT INTO DateConectare ( username, parola, Nume, Prenume ) VALUES ( '";
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

string InterpretorMesaje::DisplayLocations()
{
	//Afisam toate locatiile

	// NrLocatii|Nume1|NrCamere1|Stele1|Judet1|Nume2|NrCamere2|Stele2|Judet2|....
	int count=0;
	string output;
	string Nume, Locuri, Stele, Judet;

	Nume = DataDeBaze.MakeARequestQuery(select("Nume", "Locatii"));
	Locuri = DataDeBaze.MakeARequestQuery(select("NrCamere", "Locatii"));
	Stele = DataDeBaze.MakeARequestQuery(select("Stele", "Locatii"));
	Judet = DataDeBaze.MakeARequestQuery(select("Judet", "Locatii"));

	while (Nume.size()>1)
	{
		output += separa(Nume) + "|"+ separa(Locuri) + "|" + separa(Stele) + "|" + separa(Judet) + "|";
		count++;
	}
	output = to_string(count) + "|" + output;

	return output;
}
string InterpretorMesaje::DisplayObjectives()
{
	//Afisam toate obiectivele
	int count = 0;
	string output;
	string Nume, Judet;

	Nume = DataDeBaze.MakeARequestQuery(select("Nume", "Obiective"));
	Judet = DataDeBaze.MakeARequestQuery(select("Judet", "Obiective"));

	while (Nume.size() > 1)
	{
		output += separa(Nume) + "|" + separa(Judet) + "|";
		count++;
	}
	output = to_string(count) + "|" + output;

	return output;
}
string InterpretorMesaje::DisplayTransport()
{
	//Afisam toate mijloacele de transport
	int count = 0;
	string output;
	string Nume, Viteza;

	Nume = DataDeBaze.MakeARequestQuery(select("Nume", "MijTransport"));
	Viteza = DataDeBaze.MakeARequestQuery(select("Viteza", "MijTransport"));

	while (Nume.size() > 1)
	{
		output += separa(Nume) + "|" + separa(Viteza) + "|";
		count++;
	}
	output = to_string(count) + "|" + output;

	return output;
}

string InterpretorMesaje::IstoricUser()
{
	string output;
	string iduser=User.getID(),idlocatie,NumeLocatie,dataSosire,dataPlecare,TransportR,DataTrans;
	
	idlocatie = DataDeBaze.MakeARequestQuery(select("IDLocatie", "Rezervari", "IDUser", iduser));
	if (idlocatie != "") {
		dataSosire = DataDeBaze.MakeARequestQuery(select("LocatiiDS", "Rezervari", "IDUser", iduser));
		dataPlecare = DataDeBaze.MakeARequestQuery(select("LocatiiDP", "Rezervari", "IDUser", iduser));
		TransportR = DataDeBaze.MakeARequestQuery(select("TransportR", "Rezervari", "IDUser", iduser));
		DataTrans = DataDeBaze.MakeARequestQuery(select("TransportD", "Rezervari", "IDUser", iduser));
		
		//extrag numele locatie
		while (idlocatie.size() > 1) {
			string id = separa(idlocatie);
			NumeLocatie += DataDeBaze.MakeARequestQuery(select("Nume", "Locatii", "IDLocatie", id));
		}
		
		int count=0;
		//le concatenam in functie de cate sunt si verificam daca exista transport sau nu
		while (NumeLocatie.size() > 1) {
			string aux,auxd;

			output += separa(NumeLocatie) + "|" + separa(dataSosire) + "|" + separa(dataPlecare) + "|";
			aux = separa(TransportR);
			auxd = separa(DataTrans);

			if (aux == "") {
				aux = "NoTransport";
				auxd = "NoData";
			}

			output += aux + "|" + auxd + "|";

			count++;
		}
		output = to_string(count) + "|" + output;
	}//daca nu avem intrari in tabela, eroare
	else output = "error";

	return output;
}

string InterpretorMesaje::DetaliiLoc(string buff)
{
	/// Detalii despre ce ar trebui afisat in
	string Nume, output;
	string Locuri, Stele, Judet, Descriere;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	Locuri = DataDeBaze.MakeARequestQuery(select("NrCamere", "Locatii","Nume",Nume));
	Stele = DataDeBaze.MakeARequestQuery(select("Stele", "Locatii", "Nume", Nume));
	Judet = DataDeBaze.MakeARequestQuery(select("Judet", "Locatii", "Nume", Nume));
	Descriere = DataDeBaze.MakeARequestQuery(select("Descriere", "Locatii", "Nume", Nume));

	output += separa(Nume) + "|" + separa(Locuri) + "|" + separa(Stele) + "|" + separa(Judet) + "|" + separa(Descriere) + "|";


	return output;
}

string InterpretorMesaje::DetaliiTran(string buff)
{
	//Detalii Transport
	string Nume, output;
	string Viteza, Descriere;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	Viteza = DataDeBaze.MakeARequestQuery(select("Viteza", "MijTransport", "Nume", Nume));
	Descriere = DataDeBaze.MakeARequestQuery(select("Descriere", "MijTransport", "Nume", Nume));
	
	output += separa(Nume) + "|" + separa(Viteza) + "|" + separa(Descriere) + "|";


	return output;
}

string InterpretorMesaje::DetaliiObj(string buff)
{
	//Detalii obiecte
	string Nume, output;
	string Judet, Descriere;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	Judet = DataDeBaze.MakeARequestQuery(select("Judet", "Obiective", "Nume", Nume));
	Descriere = DataDeBaze.MakeARequestQuery(select("Descriere", "Obiective", "Nume", Nume));

	output += separa(Nume) + "|" + separa(Judet) + "|" + separa(Descriere) + "|";


	return output;
}

string InterpretorMesaje::ReserveLoc(string buff)
{
	//Rezerva update in baza de date 
	string Nume, output;
	string iduser, idlocatie, NumeLocatie, dataSosire, dataPlecare, TransportR, DataTrans;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	iduser = User.getID();
	idlocatie = DataDeBaze.MakeARequestQuery(select("IDLocatie", "Locatii", "Nume", Nume));
	dataSosire = separa(buff);
	dataPlecare = separa(buff);
	TransportR = separa(buff);
	DataTrans = separa(buff);
	idlocatie.pop_back();

	schimbaFormat(DataTrans);
	schimbaFormat(dataSosire);
	schimbaFormat(dataPlecare);
	if (CheckDates(DataDeBaze,dataSosire,dataPlecare,idlocatie))
	{

		if (dataPlecare > dataSosire) {
			if (dataSosire <= DataTrans && dataPlecare >= DataTrans) {
				string valori = "'" + iduser + "','" + idlocatie + "','" + dataSosire + "','" + dataPlecare + "','" + TransportR + "','" + DataTrans + "'";
				DataDeBaze.MakeASendQuery(insert("Rezervari", "IDUser,IDLocatie,LocatiiDS,LocatiiDP,TransportR,TransportD", valori));
				output = "good";
			}
			else output = "transport";
		}
		else output = "data";

	}
	else output = "locuri";

	return output;
}

string InterpretorMesaje::AddLoc(string buff)
{
	//ADD insert in baza de date
	string Nume, output;
	string NrCamere, Stele, Descriere, Judet;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	NrCamere = separa(buff);
	Stele = separa(buff);
	Judet = separa(buff);
	Descriere = separa(buff);

	if (Nume.size()>3)
	{
		if (stoi(NrCamere) > 3) {
			
			if (Judet.size() > 3)
			{

				if (stoi(Stele) > 1) {


					if (Descriere.size() > 10) {

						string valori = "'" + Nume + "','" + NrCamere + "','" + Stele + "','" + Judet + "','" + Descriere + "'";
						DataDeBaze.MakeASendQuery(insert("Locatii", "Nume,NrCamere,Stele,Judet,Descriere", valori));
						output = "yes";

					}
					else output = "descriere";

				}
				else output = "stele";

			}
			else output = "judet";

		}
		else output = "camere";

	}
	else output = "nume";

	return output;

 }

string InterpretorMesaje::AddTrans(string buff)
{
	//ADD insert in baza de date
	string Nume, output;
	string Viteza, Descriere;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	Viteza = separa(buff);
	Descriere = separa(buff);

	if (Nume.size() > 3)
	{

			if (stoi(Viteza) > 15) {

				if (Descriere.size() > 10) {

					string valori = "'" + Nume + "','" + Viteza + "','" + Descriere + "'";
					DataDeBaze.MakeASendQuery(insert("MijTransport", "Nume,Viteza,Descriere", valori));
					output = "yes";

				}
				else output = "descriere";

			}
			else output = "viteza";

	}
	else output = "nume";

	return output;
}

string InterpretorMesaje::AddObj(string buff)
{	
	//ADD insert in baza de date
	string Nume, output;
	string Judet, Descriere;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}
	Judet = separa(buff);
	Descriere = separa(buff);

	if (Nume.size() > 3)
	{

		if (Judet.size() > 2) {

			if (Descriere.size() > 10) {

				string valori = "'" + Nume + "','" + Judet + "','" + Descriere + "'";
				DataDeBaze.MakeASendQuery(insert("Obiective", "Nume,Judet,Descriere", valori));
				output = "yes";

			}
			else output = "descriere";

		}
		else output = "judet";

	}
	else output = "nume";

	return output;
}

string InterpretorMesaje::DelLoc(string buff)
{
	//Delete in baza de date
	string Nume, output;
	
	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}

	if (Nume.size() > 3)
	{
		string del;
		del = "DELETE FROM Rezervari WHERE Rezervari.IDLocatie IN (SELECT IDLocatie from Locatii WHERE Locatii.Nume='"+Nume+"')";
			DataDeBaze.MakeASendQuery(del);
		DataDeBaze.MakeASendQuery(DeleteSQL("Locatii","Nume",Nume));
		output = "yes";
	}
	else output = "eroare";

	return output;

}

string InterpretorMesaje::DelTrans(string buff)
{
	//Delete in baza de date
	string Nume, output;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}

	if (Nume.size() > 3)
	{
		DataDeBaze.MakeASendQuery(DeleteSQL("MijTransport", "Nume", Nume));
		output = "yes";
	}
	else output = "eroare";

	return output;

}

string InterpretorMesaje::DelObj(string buff)
{
	//Delete in baza de date
	string Nume, output;

	for (int i = 0; i < 2; i++)
	{
		Nume = separa(buff);
	}

	if (Nume.size() > 3)
	{
		DataDeBaze.MakeASendQuery(DeleteSQL("Obiective", "Nume", Nume));
		output = "yes";
	}
	else output = "eroare";

	return output;
}

void InterpretorMesaje::SendAnswer(string response, SOCKET client)
{
	cout << "Am trimis: " << response << endl<<endl;
	send(client, response.c_str(), response.size() + 1, 0);
}
