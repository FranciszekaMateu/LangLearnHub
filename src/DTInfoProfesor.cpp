#include "../include/DTInfoProfesor.h"
#include <string>
#include "../include/DTInfoUsuario.h"
#include <set>
#include <iostream>

using namespace std;

InfoProfesor::InfoProfesor(string nombre, string descripcion, string instituto, set<Idioma *> idiomas)
    : InfoUsuario(nombre, descripcion)
{
    this->instituto = instituto;
    this->idiomas = idiomas;
}
string InfoProfesor::getInstuto()
{
    return this->instituto;
}
set<Idioma *> InfoProfesor::getIdiomas()
{
    return this->idiomas;
}
ostream &operator<<(ostream &os, InfoProfesor *info)
{
    cout << "Nombre :" << info->getNombre() << endl;
    cout << "Descripcion :" << info->getDescripcion() << endl;
    cout << "Instituto :" << info->getInstuto() << endl;
    cout << "Idiomas :" << endl;
    for (Idioma *id : info->idiomas)
        cout << "   " << id->getNombre() << endl;

    return os;
}
InfoProfesor::~InfoProfesor()
{
    this->idiomas.clear();
}