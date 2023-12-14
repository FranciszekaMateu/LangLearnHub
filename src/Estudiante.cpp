#include "../include/Estudiante.h"
#include "../include/DTEjercicio.h"
#include "../include/Inscripcion.h"

Estudiante::Estudiante(string nickname, string contrasena, string nombre, string descrp, string pais) : Usuario(nombre, nickname, contrasena, descrp)
{
    this->pais = pais;
}

string Estudiante::getPais()
{
    return this->pais;
}

void Estudiante::addInscripcion(string nombreCurso, Inscripcion *ficha)
{
    this->inscripciones.insert({nombreCurso, ficha});
}

Inscripcion *Estudiante::getInscripcion(string nombreCurso)
{
    map<string, Inscripcion *>::iterator it = this->inscripciones.begin();
    while (it->first != nombreCurso && it != this->inscripciones.end())
    {
        it++;
    }
    if (it == this->inscripciones.end())
        return NULL;
    else 
    return it->second;
}

set<string> Estudiante::listarCursosNoAprobados()
{
    set<string> aux;

    map<string, Inscripcion *>::iterator it = this->inscripciones.begin();
    while (it != this->inscripciones.end())
    {
        int p = (*it->second).getProgreso();
        if (p < 100)
        {
            aux.insert((it->first));
        }
        it++;
    }

    return aux;
}
/*InfoEstudiante Estudiante::getDatos()
{
}*/

Fecha *Estudiante::getFecha()
{
    return this->fechaNacimiento;
}

map<string, int> Estudiante::getProgresoCursos()
{
    map<string, int> aux;
    return aux;
}

bool Estudiante::aptoParaCursar(Curso *curso)
{
    bool res = false;
    if (curso->getHabilitado()){
        if (this->getInscripcion(curso->getNombre()) == NULL){
            if (curso->getPrevias().empty()){
                
                res = true;
            }
            else {
                for (pair<string, Curso *> it : curso->getPrevias()){
                    Inscripcion *aux = this->getInscripcion(it.second->getNombre());
                    if (aux != NULL) {
                        res = aux->getCursoAprobado();
                        if (!res)
                        break;
                    }
                    else {
                        res = false;
                        break;
                    }
                }
            }
        }
    }
    return res;
}
/*
bool Estudiante::aptoParaCursar(Curso * curso) {
    map<string, Curso* > previasCurso = curso->getPrevias();
    map<string, Curso*>::iterator it = previasCurso.begin();
    int cursar = 0;
    int total = 0;
    while (it != previasCurso.end()) {
        map<string, Inscripcion *>::iterator iterIns = this->inscripciones.begin();
        while(iterIns != this->inscripciones.end() && (*iterIns).second->getCurso() != (*it).second) {
            iterIns++;
        }
        if ((*iterIns).second->getCurso() == (*it).second && (*iterIns).second->getProgreso() == 100) {
            cursar++;
        }
        total++;
        it++;
    }
    return (total == cursar);
} */

void Estudiante::infoUsuario()
{
}

void Estudiante::setInfoEstudiante(InfoEstudiante *info)
{
    this->info = info;
}
set<DTEjercicio*>  Estudiante::EjerciciosNoAprobadosEstudiante(string Curso)
{
    Inscripcion  *aux = this->getInscripcion(Curso);
    return aux->getCurso()->NoAprobadosEjerciciosCurso(aux);
}


void Estudiante::setFecha(Fecha *fecha)
{
    this->fechaNacimiento = fecha;
}

void Estudiante::removeInscripcion(string nombreInscripcion){
    this->inscripciones.erase(nombreInscripcion);
}
Curso *Estudiante::buscarCursoEstudiante(string Curso)
{
    return this->getInscripcion(Curso)->getCurso();
}

map<string, Inscripcion *> Estudiante::listarInscripciones(){
    return this->inscripciones;
}

bool Estudiante::ingresarSolEst(string sol, string nombreCurso, int id) {
    return this->getInscripcion(nombreCurso)->getCursoSol(sol, id);
}

map<string, Inscripcion *> Estudiante::getInscripciones() {
    return this->inscripciones;
}

Estudiante::~Estudiante(){
    delete this->fechaNacimiento;
    delete this->info;
    this->inscripciones.clear();
}
