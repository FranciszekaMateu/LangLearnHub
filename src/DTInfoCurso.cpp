#include "../include/DTInfoCurso.h"
#include <string>
using namespace std;

InfoCurso::InfoCurso(string nombre, string descripcion, string dificultad, int promedio, bool habilitado, string profesor, string idioma)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->promedio = promedio;
    this->habilitado = habilitado;
    this->profesor = profesor;
    this->idioma = idioma;
}

ostream &operator<<(ostream &os, InfoCurso *info)
{
    cout << "Nombre :" << info->nombre << endl;
    cout << "Descripcion :" << info->descripcion << endl;
    cout << "Dificultad :" << info->dificultad << endl;
    cout << "Profesor :" << info->profesor << endl;
    cout << "Idioma :" << info->idioma << endl;
    if (info->habilitado) {
        cout << "Habilitado : SI" << endl;
    } else {
        cout << "Habilitado : NO" << endl;
    }
    return os;
}
string InfoCurso::getNombre()  {
    return this->nombre;
}

string InfoCurso::getDescripcion()  {
    return this->descripcion;
}

string InfoCurso::getDificultad()  {
    return this->dificultad;
}

int InfoCurso::getPromedio()  {
    return this->promedio;
}

bool InfoCurso::getHabilitado()  {
    return this->habilitado;
}

string InfoCurso::getProfesor()  {
    return this->profesor;
}

string InfoCurso::getIdioma()  {
    return this->idioma;
}

InfoCurso::~InfoCurso(){
    
}