#include "CUser.h"

void CUser::Connect(string user)
{
	int pos = 0;

	pos = user.find("|");
	id = user.substr(0, pos);
	
	user.erase(0, pos + 1);

	pos = user.find("|");
	username = user.substr(0, pos);
	user.erase(0, pos + 1);

}
