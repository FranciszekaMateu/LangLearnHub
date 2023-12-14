#ifndef _DTTRADUCCION_H
#define _DTTRADUCCION_H
#include <string>
#include <iostream>
#include "DTEjercicio.h"

using namespace std;

class DTTraduccion
{
private:
    DTEjercicio *ej;
    string palabra;
public:
    DTTraduccion(DTEjercicio *ej, string palabra);
    friend ostream &operator<<(ostream &os, DTTraduccion *info);
    ~DTTraduccion();
};

#endif 