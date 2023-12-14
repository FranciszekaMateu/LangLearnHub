#ifndef _INTERFAZCURSO_H
#define _INTERFAZCURSO_H

#include <iostream>
#include "Dificultad.h"
#include <string>
#include <list>
#include <set>
#include <vector>
#include <map>
#include "DTInfoCurso.h"
#include "DTEstCurso.h"
#include "DTInfoLeccion.h"
#include "DTInfoEstudiante.h"
#include "DTInfoProfesor.h"
#include "DTInfoCursoDisponible.h"
#include "DTInfoEstudiante.h"
#include "DTInfoProfesor.h"
#include "DTPromedioCurso.h"
#include "DTEjercicio.h"
#include "DTInscripcion.h"
#include "DTCompletar.h"
#include "DTTraduccion.h"
using namespace std;

class IContCurso
{
private:
public:
    IContCurso();
    virtual void darDeAltaCurso(string nombre, string descripcion, Dificultad dificultad) = 0;
    virtual set<string> listarNombreCursosPrevios() = 0; // si tiene previas el curso recordado las retorna
    virtual void agregarPreviasCurso(set<string> nombreCursos) = 0;
    virtual void crearLeccion(string Tema, string Objetivo) = 0; // es infoleccion
    virtual void crearTraduccion(string descripcion, string ejercicio, string solucion) = 0;
    virtual void crearCompletar(string descripcion, string ejercicio, string solucion) = 0;
    virtual void seleccionarCurso(string nombreCurso) = 0;
    virtual set<string> listarLecciones() = 0;
    virtual vector<InfoLeccion *> listarInfoLeccion() = 0;
    virtual void seleccionarLeccion(string nombreTema) = 0;
    virtual void seleccionarIdioma(string nombreIdioma) = 0;
    virtual InfoLeccion *mostrarLeccion() = 0;
    virtual DTEjercicio *mostrarEjercicio() = 0;
    // virtual string mostrarInfoParticularCompletar() = 0;
    // virtual string mostrarInfoParticularTraduccion() = 0;
    virtual set<string> listarNombreCursosNoHabilitados() = 0;
    virtual set<InfoCursoDisponible *> listarCursosDisponibles(string nickname) = 0;
    // Lista todos los cursos del sistema
    virtual set<string> listarNombreCurso() = 0;
    virtual void habilitarCurso() = 0;
    virtual void seleccionarEjercicio(int ID) = 0;
    virtual void eliminarCurso(string nombreCurso) = 0;
    virtual void seleccionarProfesorRecordado(string nombre) = 0;
    virtual map<int, string> listarEjercicios() = 0;
    virtual InfoCurso *infoCurso(string nombreCurso) = 0;
    virtual EstCurso *estCurso(string nombreCurso) = 0;
    virtual set<string> listarCursosHabilitado() = 0;
    virtual bool mostrarParticular(DTEjercicio *ej) = 0;
    virtual DTCompletar *mostrarParticularC(DTEjercicio *ej) = 0;
    virtual DTTraduccion *mostrarParticularT(DTEjercicio *ej) = 0;
    virtual void inscribirseCurso(string nombreCurso) = 0;
    virtual set<Infoinscripcion *> getInfoInscripciones() = 0;
    virtual set<string> listarCursos() = 0;
    virtual void agregarinscr(string nombreEstudiante, string nombreCurso, string fecha) = 0;
    virtual void agregarAprobados(string nombreEstudiante, string nombreCurso, int id) = 0;
    virtual void limpiarCursos() = 0;
    virtual ~IContCurso();
};

/* NUEVAS - ANDANDO
virtual set<InfoCursoDisponible *> listarCursosDisponibles(string nickname) = 0;
virtual void seleccionarEstudiante(string nickname) = 0;
//bool altaCurso(string nombre, string descripcion, Dificultad dificultad); //hace el daigram de secuencia*/
#endif
