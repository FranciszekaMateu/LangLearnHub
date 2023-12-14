#include "../include/Profesor.h"

Profesor::Profesor(string nickname, string contrasena, string nombre, string descrp, string instituto) : Usuario(nombre, nickname, contrasena, descrp)
{
    this->Instituto = instituto;
}

set<Idioma *> Profesor::getIdiomas()
{
    return this->idiomas;
}

set<string> Profesor::listarIdiomas()
{
    set<string> res;
    for (set<Idioma *>::iterator it = this->idiomas.begin(); it != this->idiomas.end(); it++)
    {
        res.insert((*it)->getNombre());
    }
    return res;
}

string Profesor::getNickname()
{
    return this->Usuario::getNickname();
}

void Profesor::setIdiomas(set<Idioma *> idiomasAgregar)
{
    this->idiomas = idiomasAgregar;
}

InfoProfesor Profesor::getDatos()
{
    string nombre = this->getNombre();
    string descripcion = this->getNickname();
    string instituto = this->Instituto;
    set<Idioma *> idiomas = this->idiomas;
    InfoProfesor ret = InfoProfesor(nombre, descripcion, instituto, idiomas);
    return ret;
}
string Profesor::getInstituto()
{
    return this->Instituto;
}

void Profesor::infoUsuario()
{
}

void Profesor::setInfoProfesor(InfoProfesor* info) {
    this->info = info;
}

void Profesor::setCurso(Curso *curso){
    this->cursos.insert(curso);
}

void Profesor::removeCurso(Curso* curso){
    this->cursos.erase(curso);
}

set<Curso *> Profesor::listarCursos() {
    return this->cursos;
}

Profesor::~Profesor(){
    delete this->info;
    this->cursos.clear();
    this->idiomas.clear();
}
