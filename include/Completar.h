/**
 * Project Untitled
 */

#ifndef _COMPLETAR_H
#define _COMPLETAR_H

#include "Ejercicio.h"

#include <string>
#include <iostream>
using namespace std;

class Completar : public Ejercicio
{
private:
    string frase;
    string fraseCompleta;

public:
    Completar(string descripcion, string frase, string fraseCompleta, int id);
    // void verificarSol(string); // Se ingresa la solucion y verifica si está bien
    string getFrase();
    string getFraseCompleta();
    bool verificarSolC(string sol);
    ~Completar();
};

#endif //_COMPLETAR_H
