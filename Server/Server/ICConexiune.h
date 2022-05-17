#pragma once

class ICConexiune
{
public:
	virtual void StabilesteConexiuneWinSock()  = 0;
	virtual void CreazaSocketAscultare()  = 0;
	virtual void BindIpPort() = 0;
	virtual void StartListening() = 0;
	virtual void StabilesteConexiuneClient() = 0;
	virtual void InchidePortAscultare() = 0;
	virtual void InchidePortClient() = 0;
	virtual void MentineConexiunea() = 0;

};

