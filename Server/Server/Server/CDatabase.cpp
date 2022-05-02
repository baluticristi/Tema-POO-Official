#include "CDatabase.h"
//#include "stdafx.h"



using namespace std;

void CDatabase::ConnectToDatabase()
{


		//initializations
		ConnectionHandle = NULL;
		StatementHandle = NULL;


		//allocations
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &EnvironmentHandle))
		{
			DisconnectDatabase();
			return;
		}

		if (SQL_SUCCESS != SQLSetEnvAttr(EnvironmentHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		{
			DisconnectDatabase();
			return;
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, EnvironmentHandle, &ConnectionHandle))
		{
			DisconnectDatabase();
			return;
		}

		//TEMPORAR
		cout << "Incercam conexiunea la baza de date...\n";
		//TEMPORAR



		switch (SQLDriverConnect(ConnectionHandle,
			NULL,
			(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=CRISTIAN-PC, 1434;DATABASE=POO;Trusted=true;",
			//AICI SE MODIFICA NUMELE PC-ului
			SQL_NTS,
			CodeLen,
			1024,
			NULL,
			SQL_DRIVER_NOPROMPT))
		{
		case SQL_SUCCESS:
			cout << "Successfully connected to SQL Server";
			cout << "\n";
			break;
		case SQL_SUCCESS_WITH_INFO:
			cout << "Successfully connected to SQL Server";
			cout << "\n";
			break;
		case SQL_INVALID_HANDLE:
			cout << "Could not connect to SQL Server";
			cout << "\n";
			DisconnectDatabase();
			return;
		case SQL_ERROR:
			cout << "Could not connect to SQL Server";
			cout << "\n";
			DisconnectDatabase();
		return;
		default:
			break;
		}

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, ConnectionHandle, &StatementHandle))
		{
			DisconnectDatabase();
			return;
		}	
	
}

void CDatabase::DisconnectDatabase()
{
	SQLFreeHandle(SQL_HANDLE_STMT, StatementHandle);
	SQLDisconnect(ConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, ConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, EnvironmentHandle);
}

string CDatabase::MakeARequestQuery (string str)
{
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, ConnectionHandle, &StatementHandle))
	{
		DisconnectDatabase();
		return "";
	}
	string rezultat="";
	wstring query(str.begin(),str.end());
	if (SQL_SUCCESS != SQLExecDirect(StatementHandle,
		(SQLWCHAR*)query.c_str(),
		SQL_NTS)) {
			cout << "Error querying SQL Server";
			cout << "\n";
	}
	
	else {

		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLLEN ptrSqlVersion;

		while (SQLFetch(StatementHandle) == SQL_SUCCESS) {

			SQLGetData(StatementHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

			string s((const char*)sqlVersion);
			rezultat += s;
			rezultat += "|";
		}
	}
	return rezultat;
}

void CDatabase::MakeASendQuery(string str)
{
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, ConnectionHandle, &StatementHandle))
	{
		DisconnectDatabase();
		return;
	}
	string rezultat = "";
	wstring query(str.begin(), str.end());
	if (SQL_SUCCESS != SQLExecDirect(StatementHandle,
		(SQLWCHAR*)query.c_str(),
		SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
	}

}
