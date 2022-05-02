#pragma once
#include <iostream>

using namespace std;

class ICodificator
{
	virtual string Cripteaza(string passw) = 0;
	virtual string Decripteaza(string passw) = 0;
};

