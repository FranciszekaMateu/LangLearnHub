#include "../include/DTInfoCursoDisponible.h"

InfoCursoDisponible::InfoCursoDisponible(string nombre, string descripcion, string dificultad, int promedio, bool habilitado, string profesor, string idioma, int cantLecciones, int cantEjercicios)
    : InfoCurso(nombre, descripcion, dificultad, promedio, habilitado, profesor, idioma), cantLecciones(cantLecciones), cantEjercicios(cantEjercicios)
    {};
int InfoCursoDisponible::getCantLecciones()
{
    return this->cantLecciones;
}
int InfoCursoDisponible::getCantEjercicios()
{
    return this->cantEjercicios;
}
ostream &operator<<(ostream &os, InfoCursoDisponible *info)
{
    cout << dynamic_cast<InfoCurso*>(info);;
    cout << "Cantidad de Lecciones :" << info->getCantLecciones() << endl;
    cout << "Cantidad de Ejercicios :" << info->getCantEjercicios() << endl;
    return os;
}
InfoCursoDisponible::~InfoCursoDisponible(){
    
}
