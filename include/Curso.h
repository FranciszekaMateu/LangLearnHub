#ifndef _CURSO_H
#define _CURSO_H

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include "Idioma.h"
#include "Profesor.h"
#include "Leccion.h"
#include "DTInfoCurso.h"
#include "DTEstCurso.h"
#include "DTInfoCursoDisponible.h"
#include "Inscripcion.h"
#include <DTEjercicio.h>
using namespace std;

class Inscripcion;
class InfoCurso;
class Profesor;
class Leccion;

class Curso
{
private:
    string Nombre;
    string Descripcion;
    Dificultad Dific;
    bool Habilitado;
    Idioma *idioma;
    Profesor *profesor;
    map<string, Curso *> Previas;
    vector<Leccion *> Lecciones;
    set<Inscripcion *> Inscripciones;
    int cantLecciones;
    int cantEjercicios;
    InfoCurso *info;
    EstCurso *est;

public:
    Curso(string Nombre, string Descripcion, Dificultad Dific);
    void setIdioma(Idioma *idioma);
    void setPrevia(map<string, Curso *> nombreCurso);
    void setProfesor(Profesor *profesor);
    void setLecciones(Leccion *leccion);
    string getNombre();
    map<string, Curso *> getPrevias();
    string getDescripcion();
    string getProfesorNombre();
    string getDificultad();
    bool getHabilitado();
    vector<Leccion *> getLecciones();
    InfoCurso *getInfo();
    EstCurso *getEst();
    InfoCursoDisponible *getInfoDisponible();
    Idioma *idiomaRelacionado();
    void setHabilitado();
    set<string> listarLecciones();
    set<DTEjercicio*> NoAprobadosEjerciciosCurso(Inscripcion *inscripcion);
    set<Inscripcion *> getInscripciones();
    void removePrevias(string nombreCurso);
    void setInscripcion(Inscripcion *i);
    int getPromedio();
    void masLeccion();
    void masEjercicio();
    Ejercicio * buscarEjercicioCurso(int id);
    ~Curso();
};

#endif //_CURSO_H
