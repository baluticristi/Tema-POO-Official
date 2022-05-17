#pragma once
class IDatabase
{
	virtual void ConnectToDatabase()=0;
	virtual void DisconnectDatabase()=0;
};

