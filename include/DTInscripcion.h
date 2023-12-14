#ifndef _INFOINSCRIPCION_H
#define _INFOINSCRIPCION_H
#include <string>
#include <iostream>
#include "DTFecha.h"

using namespace std;

class Infoinscripcion
{
private:
    string nombre;
    Fecha *fechains;

public:
    Infoinscripcion(string nombre, Fecha *fecha);
    friend ostream &operator<<(ostream &os, Infoinscripcion *info);
    ~Infoinscripcion();
};

#endif // INFOINSCRIPCION_H
