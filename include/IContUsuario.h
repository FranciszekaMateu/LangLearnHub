#ifndef _INTERFAZUSUARIO_H
#define _INTERFAZUSUARIO_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "DTInfoEstudiante.h"
#include "DTInfoProfesor.h"
#include "DTPromedioCurso.h"
#include "DTEjercicio.h"
#include "DTProgresoCurso.h"
#include "DTNotificacion.h"
using namespace std;

class IContUsuario
{
private:
public:
    IContUsuario();
    virtual void altaProfesor(string nombre, string nick, string password, string descripcion, string instituto) = 0;
    virtual set<string> listarNombreIdiomas() = 0;
    virtual void seleccionarIdiomas(set<string> idiomas) = 0;
    virtual void altaEstudiante(string nickname, string contrasena, string nombre, string descrp, string pais) = 0;
    virtual set<string> listarNicknameUsuarios() = 0;
    virtual void seleccionarUsuario(string nombre) = 0;
    virtual InfoProfesor *infoProfesor() = 0;
    virtual InfoEstudiante *infoEstudiante() = 0;
    virtual void altaIdioma(string nombreIdioma) = 0;
    virtual set<string> listarProfesores() = 0;
    virtual void seleccionarProf(string nicknameProfesor) = 0;
    virtual set<string> listarNombreIdiomasProfe() = 0;
    virtual bool esProfesor() = 0;
    virtual void getFecha(int dia, int mes, int ano) = 0;
    virtual set<string> listarEstudiantes() = 0;
    // virtual set<PromedioCurso> listarCursosProfesor(string nickname) = 0;
    virtual set<DTEjercicio *> listarEjerciciosNoAprobados(string curso) = 0;
    // virtual void seleccionarEjercicio(int ID) = 0;
    virtual set<ProgresoCurso *> listarProgresoCursosEstudiante(string nickname) = 0;
    virtual set<PromedioCurso *> listarPromedioCursosProfesor(string nickname) = 0;
    virtual set<string> listarCursosEstudianteNoAprobados(string nickname) = 0;
    virtual void seleccionarEjercicio(int id) = 0;
    virtual bool ingresarSol(string sol) = 0;
    virtual string mostrarParticular2() = 0;
    virtual set<string> listarNombreIdiomasNoSuscritos() = 0;
    virtual void seleccionarIdiomasASuscribirse(set<string> idiomas) = 0;
    virtual string tipoEjRecord() = 0;
    virtual set<DTNotificacion *> listarNotificacionesUsuario() = 0;
    virtual set<string> listarIdiomasSuscritos() = 0;
    virtual void eliminarNotificacionesUsuario() = 0;
    virtual void eliminarSuscripcion(set<string> idiomas) = 0;
    virtual bool tieneInscripciones() = 0;
    virtual void limpiarIdiomas() = 0;
    virtual void limpiarUsuarios() = 0;
    virtual ~IContUsuario();
};

#endif