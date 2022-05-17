#pragma once
#include "ICUser.h"
#include <iostream>

using namespace std;
class CUser :
    public ICUser
{
private:
    string id, username;
public:
    void Connect(string user);
    string getID() { return id; };
    string getName() { return username; };


};

