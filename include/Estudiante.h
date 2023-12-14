#ifndef _ESTUDIANTE_H
#define _ESTUDIANTE_H

#include "Usuario.h"
#include "DTFecha.h"
#include "Inscripcion.h"
#include "Ejercicio.h"
#include "DTInfoEstudiante.h"
#include "DTProgresoCurso.h"
#include <DTEjercicio.h>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include "Curso.h"
using namespace std;
class Curso;
class Inscripcion;
class Estudiante : public Usuario
{
private:
    Fecha *fechaNacimiento;
    string pais;
    map<string, Inscripcion *> inscripciones;
    InfoEstudiante *info;
    /*    map<string, Curso *> Aprobado; */

public:
    Estudiante(string nickname, string contrasena, string nombre, string descrp, string pais);
    string getPais();
    void addInscripcion(string nombreCurso, Inscripcion *ficha);
    Inscripcion *getInscripcion(string nombreCurso);
    map<string, Inscripcion *> getInscripciones();
    set<string> listarCursosNoAprobados();
    InfoEstudiante getDatos();
    map<string, int> getProgresoCursos();
    void infoUsuario() override; // -> hay que borrarla
    Fecha *getFecha();
    void setInfoEstudiante(InfoEstudiante *info);
    bool aptoParaCursar(Curso *curso);
    set<DTEjercicio*>  EjerciciosNoAprobadosEstudiante(string Curso);
    void setFecha(Fecha *fecha);
    void removeInscripcion(string nombreInscripcion);
    Curso *buscarCursoEstudiante(string Curso);
    map<string, Inscripcion *> listarInscripciones();
    bool ingresarSolEst(string sol, string nombreCurso, int id);
    ~Estudiante();
};

#endif
