#include <string>
#include <iostream>
#include "../include/DTInscripcion.h"

using namespace std;

Infoinscripcion::Infoinscripcion(string nombre, Fecha *fecha)
{
    this->nombre = nombre;
    this->fechains = fecha;
}
ostream &operator<<(ostream &os, Infoinscripcion *info)
{
    cout << info->nombre << endl;
    cout << info->fechains << endl;
    return os;
}

Infoinscripcion::~Infoinscripcion(){
    delete this->fechains;
}