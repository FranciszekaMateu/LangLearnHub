#ifndef _IDIOMA_H
#define _IDIOMA_H

#include "Usuario.h"
#include <string>
#include <map>
#include <iostream>
#include "ISuscripto.h"
using namespace std;

class ISuscripto;

class Idioma
{
private:
    set<ISuscripto *> Suscriptos;
    string Nombre;

public:
    Idioma(string nombre);
    void Agregar(ISuscripto *suscripto);
    void eliminar(ISuscripto *suscripto);
    void modificar(string Curso);
    string getNombre();
    bool consultarUsuario(ISuscripto *suscripto);
    set<ISuscripto *> getSucripciones();
    ~Idioma();
};

#endif //_IDIOMA_H
