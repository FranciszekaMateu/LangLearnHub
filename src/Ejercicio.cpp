#include "../include/Ejercicio.h"
#include "../include/Inscripcion.h"
#include <string>
#include <iostream>
using namespace std;

Ejercicio::Ejercicio(string descripcion, int id)
{
    this->descripcion = descripcion;
    this->id = id;
}

string Ejercicio::getDescripcion()
{
    return this->descripcion;
}

int Ejercicio::getId()
{
    return this->id;
}

bool Ejercicio::consultarInscripcion(Inscripcion *inscripcion)
{
    set<Ejercicio *> inscripciones= inscripcion->getAprobados();
    return (inscripciones.find(this) == inscripciones.end());
}
Ejercicio::~Ejercicio()
{
}

DTEjercicio *Ejercicio::getInfo()
{
        DTEjercicio *info = new DTEjercicio(this->id, this->getDescripcion());
    return info;
};
