/**
 * Project Untitled
 */

#ifndef _TRADUCCION_H
#define _TRADUCCION_H

#include "Ejercicio.h"

#include <string>
#include <iostream>
using namespace std;

class Traduccion : public Ejercicio
{
private:
    string palabra;
    string traduccion;

public:
    Traduccion(string descripcion, string palabra, string traduccion, int id);
    // void verificarSol(string); // Se ingresa la solucion y verifica si está bien
    string getPalabra();
    string getTraduccion();
    bool verificarSolT(string sol);
    ~Traduccion();
};

#endif //_TRADUCCION_H
