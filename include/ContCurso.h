#ifndef _CONTCURSO_H
#define _CONTCURSO_H

#include <string>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include "DTInfoCurso.h"
#include "DTEstCurso.h"
#include "Curso.h"
#include "Profesor.h"
#include "Usuario.h"
#include "Idioma.h"
#include "IContCurso.h"
#include "ContUsuario.h"
#include "DTEjercicio.h"
#include "DTTraduccion.h"
#include "DTCompletar.h"
#include "DTInfoLeccion.h"
#include "Completar.h"
#include "Traduccion.h"
#include "DTInscripcion.h"

using namespace std;

class ContCurso : public IContCurso
{
private:
    static ContCurso *instancia;
    ContCurso();
    Curso *cursorecord;
    Estudiante *estrecord;
    Profesor *profrecord;
    Leccion *lecrecord;

    Idioma *idrecord;
    map<string, Curso *> cursosSistema;
    map<string, Curso *> cursosPrevios;
    map<int, Ejercicio *> ejerciciosSistema;
    int IDrecord;
    int IDactual = 0;
    Ejercicio *ejrecord;

public:
    static ContCurso *getInstancia();
    void seleccionarProfesor(string nicknameProfesor);
    set<string> listarNombreCursosNoHabilitados(); // NEW
    void seleccionarCurso(string nombreCurso);     // NEW
    void seleccionarLeccion(string nombreTema);
    void darDeAltaCurso(string nombre, string descripcion, Dificultad dificultad);
    set<string> listarNombreIdiomasDelProfe();
    void seleccionarIdioma(string nombreIdioma);
    set<string> listarCursosHabilitado();
    void agregarPreviasCurso(set<string> nombreCurso);
    void crearLeccion(string Tema, string Objetivo);
    void crearTraduccion(string descripcion, string ejercicio, string solucion);
    void crearCompletar(string descripcion, string ejercicio, string solucion);
    void notificarUsuarios();
    map<string, Curso *> getCursos();
    void agregarCurso(Curso *curso);
    void habilitarCurso();
    Idioma *getIdiomaRec();
    set<string> listarLecciones();
    vector<InfoLeccion *> listarInfoLeccion();
    InfoCurso *infoCurso(string nombreCurso);
    EstCurso *estCurso(string nombreCurso);
    void infoLeccion(string desc, string tema);
    set<InfoCursoDisponible *> listarCursosDisponibles(string nickname);
    void seleccionarEstudiante(string nickname);
    Curso *getCursoRecordado();
    map<string, Curso *> getPreviasRecordado();
    set<string> listarNombreCurso();
    set<string> listarNombreCursosPrevios();
    InfoLeccion *mostrarLeccion();
    void seleccionarEjercicio(int ID);
    DTEjercicio *mostrarEjercicio();
    void seleccionarProfesorRecordado(string nombre);
    void eliminarCurso(string nombreCurso);
    map<int, string> listarEjercicios();
    Profesor *getProfeRecordado();
    bool mostrarParticular(DTEjercicio *ej);
    DTCompletar *mostrarParticularC(DTEjercicio *ej);
    DTTraduccion *mostrarParticularT(DTEjercicio *ej);
    void inscribirseCurso(string nombreCurso);
    set<Infoinscripcion *> getInfoInscripciones();
    set<string> listarCursos();
    void setEjercicioSistema(Ejercicio *ejs);
    // lo estoy haciendo para inscribir los estudiantes en el caso de pruebas
    void agregarinscr(string nombreEstudiante, string nombreCurso, string fecha);

    void agregarAprobados(string nombreEstudiante, string nombreCurso, int id);

    //  set<Ejercicio *> getEjercicios();

    void limpiarCursos();
};

#endif //_CONTCURSO_H
