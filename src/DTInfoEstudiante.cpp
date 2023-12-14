#include "../include/DTInfoEstudiante.h"
#include "../include/DTInfoUsuario.h"
#include <string>
#include <iostream>
using namespace std;

InfoEstudiante::InfoEstudiante(string nombre, string descripcion, string pais, Fecha *fecha)
    : InfoUsuario(nombre, descripcion)
{
    this->pais = pais;
    this->fecha = fecha;
}
string InfoEstudiante::getPais()
{
    return this->pais;
}
Fecha *InfoEstudiante::getFecha()
{
    return this->fecha;
}
ostream &operator<<(ostream &os, InfoEstudiante *info)
{
    cout << "Nombre :" << info->getNombre() << endl;
    cout << "Descripcion :" << info->getDescripcion() << endl;
    cout << "Pais :" << info->getPais() << endl;
    cout << "Fecha :" << info->getFecha() << endl;

    return os;
}
InfoEstudiante::~InfoEstudiante()
{
}
