#ifndef _INSCRIPCION_H

#define _INSCRIPCION_H

#include <string>
#include <iostream>
#include <set>
#include "Estudiante.h"
#include "DTFecha.h"
#include "Ejercicio.h"

using namespace std;

class Curso;
class Estudiante;
class Inscripcion
{
private:
    float Progreso;
    Fecha *Fechainscripcion;
    Estudiante *Estudianteinscr;
    Curso *Cursoinscripto;
    set<Ejercicio *> Aprobados;

public:
    Inscripcion(Fecha *fecha, Estudiante *estudiante, Curso *cursoinscri);
    Estudiante *getEstudiante();
    Curso *getCurso();
    float getProgreso();
    void setProgreso();
    set<Ejercicio *> getAprobados();
    void addAprobados(Ejercicio *ejer);
    bool getCursoAprobado();
    Fecha *getFecha();
    bool getCursoSol(string sol, int id);
    ~Inscripcion();
};

#endif //_INSCRIPCION_H
