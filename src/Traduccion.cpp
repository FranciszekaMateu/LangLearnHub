#include "../include/Ejercicio.h"
#include "../include/Traduccion.h"

#include <string>
#include <iostream>
using namespace std;

Traduccion::Traduccion(string descripcion, string palabra, string traduccion, int id) : Ejercicio(descripcion, id)
{
    this->palabra = palabra;
    this->traduccion = traduccion;
}

string Traduccion::getPalabra()
{
    return this->palabra;
}

string Traduccion::getTraduccion()
{
    return this->traduccion;
}

bool Traduccion::verificarSolT(string sol) {
    return (this->traduccion == sol);
}

Traduccion::~Traduccion(){
    
}
