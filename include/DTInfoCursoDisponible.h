#ifndef _INFOCURSODISPONIBLE_H
#define _INFOCURSODISPONIBLE_H
#include <string>
#include "Dificultad.h"
#include "DTInfoCurso.h"
#include <iostream>

using namespace std;

class InfoCursoDisponible : public InfoCurso
{
private:
    int cantLecciones;
    int cantEjercicios;
public:
        InfoCursoDisponible(string nombre, string descripcion, string dificultad, int promedio, bool habilitado, string profesor, string idioma, int cantLecciones, int cantEjercicios);
    friend ostream &operator<<(ostream &os, InfoCursoDisponible *info);
    int getCantLecciones();
    int getCantEjercicios();
    ~InfoCursoDisponible();
};

#endif // INFOCURSO_H