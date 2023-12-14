#ifndef _ESTCURSO_H
#define _ESTCURSO_H
#include <string>
#include <iostream>
#include "Dificultad.h"

using namespace std;

class EstCurso
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
    EstCurso(string nombre, string descripcion, string dificultad, int promedio, bool habilitado, string profesor, string idioma);
    friend ostream &operator<<(ostream &os, EstCurso *info);
    ~EstCurso();
};

#endif // ESTCURSO_H
