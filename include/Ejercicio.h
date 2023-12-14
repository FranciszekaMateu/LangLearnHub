
#ifndef _EJERCICIO_H
#define _EJERCICIO_H

#include <string>
#include <iostream>

#include "Inscripcion.h"
#include "DTEjercicio.h"
using namespace std;
class Inscripcion;
class Ejercicio
{
private:
    string descripcion;
    int id;

public:
    Ejercicio(string descripcion, int id);
    string getDescripcion();
    int getId();
    DTEjercicio* getInfo();
    bool consultarInscripcion(Inscripcion *inscripcion);
    virtual ~Ejercicio();
};

#endif //_EJERCICIO_H
