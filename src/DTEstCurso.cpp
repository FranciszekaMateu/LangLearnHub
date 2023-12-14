#include "../include/DTEstCurso.h"
#include <string>
using namespace std;

EstCurso::EstCurso(string nombre, string descripcion, string dificultad, int promedio, bool habilitado, string profesor, string idioma)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->dificultad = dificultad;
    this->promedio = promedio;
    this->habilitado = habilitado;
    this->profesor = profesor;
    this->idioma = idioma;
}

ostream &operator<<(ostream &os, EstCurso *info)
{
    cout << "Nombre :" << info->nombre << endl;
    cout << "Descripcion :" << info->descripcion << endl;
    cout << "Dificultad :" << info->dificultad << endl;
    cout << "Profesor :" << info->profesor << endl;
    cout << "Idioma :" << info->idioma << endl;
    cout << "Promedio: " << info->promedio << "%" << endl;
    if (info->habilitado) {
        cout << "Habilitado : SI" << endl;
    } else {
        cout << "Habilitado : NO" << endl;
    }
    return os;
}

EstCurso::~EstCurso(){
    
}