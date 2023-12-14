#ifndef _CONTUSUARIO_H
#define _CONTUSUARIO_H

#include "Idioma.h"

#include <string>
#include <list>
#include <set>
#include <map>

class Usuario;

#include "Profesor.h"
#include "Estudiante.h"
#include "IContUsuario.h"
#include "DTProgresoCurso.h"
#include "DTPromedioCurso.h"
#include "DTNotificacion.h"

class Contusuario : public IContUsuario
{
private:
    Contusuario();
    Usuario *usuarioRecorado;
    set<Idioma *> idiomaRecordados;
    Fecha *fecharecordada;
    static Contusuario *instanciaUsuario;
    map<string, Usuario *> usuarioSistema;
    set<Idioma *> idiomaSistema;
    Curso *cursoRecordado;
    Ejercicio *ejRecord;

public:
    static Contusuario *getInstancia();

    // setters
    void setusuarioSistema(Usuario *usuario);
    void setidiomaSistema(Idioma *i);
    void setIdiomaRecordado(set<Idioma *> idiomas);
    void setusuarioRecordado(Usuario *usuario);
    void setFecharecordada(Fecha *fecha);
    void setCursoRecordado(Curso *curso);
    void setEjRecord(Ejercicio *ej);

    // getters
    set<Idioma *> getIdiomas();
    map<string, Usuario *> getUsuarioSistema();
    set<Idioma *> getIdiomaRecordado();
    Usuario *getUsuarioRecordado();
    Curso *getCursoRecordado();
    Ejercicio *getEjRecord();
    void getFecha(int dia, int mes, int ano);

    // metodos listar
    set<string> listarNombreIdiomasProfe();
    set<string> listarNicknameUsuarios();
    set<string> listarProfesores();
    set<DTEjercicio *> listarEjerciciosNoAprobados(string curso);
    set<string> listarEstudiantes();
    set<string> listarCursosEstudianteNoAprobados(string nickname);
    set<string> listarNombreIdiomasNoSuscritos();
    set<string> listarIdiomas(set<Idioma *> idiomaSistema);
    set<string> listarUsuarios(map<string, Usuario *> usuarios);
    set<string> listarNombreIdiomas();
    set<ProgresoCurso *> listarProgresoCursosEstudiante(string nickname);
    set<PromedioCurso *> listarPromedioCursosProfesor(string nickname);
    bool ingresarSol(string sol);
    set<DTNotificacion *> listarNotificacionesUsuario();
    set<string> listarIdiomasSuscritos();

    // metodos seleciconarios
    Profesor *seleccionarProfesor(string nicknameProfesor);
    void seleccionarUsuario(string nombre) override;
    void seleccionarIdiomas(set<string> idiomas) override;
    void seleccionarProf(string nicknameProfesor);
    void seleccionarEjercicio(int id);
    void seleccionarIdiomasASuscribirse(set<string> idiomas);

    // metodos de alta
    void altaProfesor(string nombre, string nick, string password, string descripcion, string instituto) override;
    void altaEstudiante(string nickname, string contrasena, string nombre, string descrp, string pais) override;
    void altaIdioma(string nombre) override;

    // infos
    InfoProfesor *infoProfesor() override;
    InfoEstudiante *infoEstudiante() override;

    // metodos utils
    bool esProfesor() override;
    string tipoEjRecord(); // Retorna el nombre del ejercicio
    void eliminarNotificacionesUsuario();
    void eliminarSuscripcion(set<string> idiomas);
    bool tieneInscripciones();

    string mostrarParticular2();

    void limpiarIdiomas();
    void limpiarUsuarios();
};

#endif // _CONTUSUARIO_H
