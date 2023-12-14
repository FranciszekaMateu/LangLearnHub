#ifndef _INFOCURSO_H
#define _INFOCURSO_H
#include <string>
#include <iostream>
#include "Dificultad.h"

using namespace std;

class InfoCurso
{
private:
    string nombre;
    string descripcion;
    string dificultad;
    int promedio;
    bool habilitado;
    string profesor;
    string idioma;

public:
    InfoCurso(string nombre, string descripcion, string dificultad, int promedio, bool habilitado, string profesor, string idioma);
    friend ostream &operator<<(ostream &os, InfoCurso *info);
    string getNombre() ;
    string getDescripcion() ;
    string getDificultad() ;
    int getPromedio() ;
    bool getHabilitado() ;
    string getProfesor() ;
    string getIdioma() ;
    ~InfoCurso();
};

#endif // INFOCURSO_H
