#include "../include/Usuario.h"
#include "../include/Curso.h"
#include "../include/ContCurso.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

Curso::Curso(string Nombre, string Descripcion, Dificultad Dific)
{
  this->Nombre = Nombre;
  this->Descripcion = Descripcion;
  this->Dific = Dific;
  this->Habilitado = false;
  this->cantLecciones = 0;
  this->cantEjercicios = 0;
};

string Curso::getNombre()
{
  return this->Nombre;
}

void Curso::setIdioma(Idioma *idioma)
{
  this->idioma = idioma;
}
map<string, Curso *> Curso::getPrevias()
{
  return this->Previas;
}
Idioma *Curso::idiomaRelacionado()
{
  return this->idioma;
}
string Curso::getDescripcion()
{
  return this->Descripcion;
}

void Curso::setPrevia(map<string, Curso *> nombreCursos)

{
  this->Previas = nombreCursos;
}

void Curso::setProfesor(Profesor *profesor)
{
  this->profesor = profesor;
}

string Curso::getProfesorNombre()
{
  return this->profesor->getNickname();
}

string Curso::getDificultad()
{
  if (this->Dific == Avanzado)
    return "Avanzado";

  if (this->Dific == Medio)
    return "Medio";

  if (this->Dific == Principiante)
    return "Principiante";

  return " ";
}
vector<Leccion *> Curso::getLecciones()
{
  return this->Lecciones;
}

void Curso::setLecciones(Leccion *leccion)
{
  this->Lecciones.push_back(leccion);
}
bool Curso::getHabilitado()
{
  return this->Habilitado;
}

InfoCurso *Curso::getInfo()
{
  int cont = 1;
  int suma = 0;
  for (Inscripcion *it : this->Inscripciones)
  {
    cont++;
    suma += it->getProgreso();
  }
  int promedio = suma / cont;

  InfoCurso *info = new InfoCurso(this->getNombre(), this->getDescripcion(), this->getDificultad(), promedio, this->getHabilitado(), this->profesor->getNombre(), this->idioma->getNombre());
  this->info = info;
  return info;
}

EstCurso *Curso::getEst()
{
  int cont = 1;
  int suma = 0;
  set<Inscripcion*>  inscripciones = this->getInscripciones();
  for (Inscripcion *it : inscripciones)
  {
    cont++;
    suma += it->getProgreso();
  }
  int promedio = suma / cont;

  EstCurso *info = new EstCurso(this->getNombre(), this->getDescripcion(), this->getDificultad(), promedio, this->getHabilitado(), this->profesor->getNombre(), this->idioma->getNombre());
  this->est = info;
  return info;
}

InfoCursoDisponible *Curso::getInfoDisponible()
{
  int cont = 0;
  int suma = 0;
  int promedio = 0;
  set<Inscripcion*>  inscripciones = this->getInscripciones();
  for (Inscripcion *it : inscripciones)
  {
    cont++;
    suma += it->getProgreso();
  }
  if (cont != 0) promedio = suma / cont;
  InfoCursoDisponible *infod = new InfoCursoDisponible(this->getNombre(), this->getDescripcion(), this->getDificultad(), promedio, this->getHabilitado(), this->profesor->getNombre(), this->idioma->getNombre(), this->cantLecciones, this->cantEjercicios);
  return infod;
}

int Curso::getPromedio()
{
  int cont = 0;
  int suma = 0;
  int promedio = 0;
  for (Inscripcion *it : this->Inscripciones)
  {
    cont++;
    suma += it->getProgreso();
  }
  if (cont != 0)
    promedio = suma / cont;
  return promedio;
}

void Curso::setHabilitado()
{
  this->Habilitado = true;
}

set<DTEjercicio*> Curso::NoAprobadosEjerciciosCurso(Inscripcion *inscripcion)
{
  vector<Leccion *> aux = this->getLecciones();
  set<DTEjercicio*> aux2;
  for (vector<Leccion *>::iterator it = aux.begin(); it != aux.end(); ++it)
  {
    aux2 = (*it)->NoAprobadosEjerciciosLecciones(inscripcion);
    if (!(aux2.empty()))
    {
      break;
    }
  }
  return aux2;
}

set<Inscripcion *> Curso::getInscripciones()
{
  return this->Inscripciones;
}

void Curso::removePrevias(string nombreCurso)
{
  this->Previas.erase(nombreCurso);
}

void Curso::setInscripcion(Inscripcion *i)
{
  this->Inscripciones.insert(i);
}

void Curso::masLeccion()
{
  this->cantLecciones++;
}

void Curso::masEjercicio()
{
  this->cantEjercicios++;
}

Ejercicio *Curso::buscarEjercicioCurso(int id)
{
  Ejercicio *ejercicio = NULL;
  vector<Leccion *> lecciones = this->getLecciones();
  for (vector<Leccion *>::iterator it = lecciones.begin(); it != lecciones.end(); ++it)
  {
    ejercicio = (*it)->buscarEjercicioLeccion(id);
    if (ejercicio != NULL)
    {
      return ejercicio;
    }
  }
  return ejercicio;
}


Curso::~Curso()
{
  this->Previas.clear();
  this->Lecciones.clear();
  this->Inscripciones.clear();
  delete this->info;
}
