#include "../include/DTInfoUsuario.h"

InfoUsuario::InfoUsuario(string nombre, string descripcion)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
}

string InfoUsuario::getDescripcion()
{
    return this->descripcion;
}
string InfoUsuario::getNombre()
{
    return this->nombre;
}
InfoUsuario::~InfoUsuario()
{}
