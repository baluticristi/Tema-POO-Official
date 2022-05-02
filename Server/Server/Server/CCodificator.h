#pragma once
#include "ICodificator.h"
class CCodificator :
    public ICodificator
{
public:
    string Cripteaza(string passw);
    string Decripteaza(string passw);

};

