#include "../include/DTEjercicio.h"

DTEjercicio::DTEjercicio(int id, string descripcion)
{
    this->descripcion = descripcion;
    this->id = id;
}

string DTEjercicio::getDescripcion()
{
    return this->descripcion;
};

ostream &operator<<(ostream &os, DTEjercicio *info)
{
    cout << "ID del ejercicio:" << info->getId() << endl;
    cout << "Descripcion: " << info->getDescripcion() << endl;
    return os;
};

int DTEjercicio::getId()
{
    return this->id;
};

DTEjercicio::~DTEjercicio(){};
