#include "../include/Leccion.h"
#include "../include/Traduccion.h"
#include "../include/Completar.h"
#include "../include/DTEjercicio.h"
#include "../include/ContCurso.h"

Leccion::Leccion(string tema, string obj)
{
    this->Tema = tema;
    this->Objetivo = obj;
}

void Leccion::agregarEjercicio(string descripcion, string ejercicio, string solucion, int opcion, int id)
{
    Completar *ejC = nullptr;
    Traduccion *ejT = nullptr;
    ContCurso *c = ContCurso::getInstancia();

    switch (opcion)
    {
    case 0:
        ejC = new Completar(descripcion, ejercicio, solucion, id);
        this->ejs.insert({id, ejC});  //[id] = ejC;
        c->setEjercicioSistema(ejC);
        break;
    case 1:
        ejT = new Traduccion(descripcion, ejercicio, solucion, id);
        this->ejs.insert({id, ejT}); //[id] = ejT;
        c->setEjercicioSistema(ejT);

        break;
    default:
        cout << "Error"; // por ahora
        break;
    }
}

map<int, Ejercicio *> Leccion::getEjercicios()
{
    return this->ejs;
}

string Leccion::getTema()
{
    return this->Tema;
}

void Leccion::setTema(std::string tema)
{
    this->Tema = tema;
}

std::string Leccion::getObjetivo()
{
    return this->Objetivo;
}

void Leccion::setObjetivo(std::string obj)
{
    this->Objetivo = obj;
}

InfoLeccion *Leccion::getInfo()
{
    InfoLeccion *i = new InfoLeccion(this->Tema, this->Objetivo);
    return i;
}
set<DTEjercicio*> Leccion::NoAprobadosEjerciciosLecciones(Inscripcion *inscripcion)
{
    set<DTEjercicio*> aux;
    map<int, Ejercicio *> ejercicios = this->getEjercicios();
    for (map<int, Ejercicio *>::iterator it = ejercicios.begin(); it != ejercicios.end(); ++it)
    {
        if ((it->second->consultarInscripcion(inscripcion)))
        {
            DTEjercicio *ejercicio = new DTEjercicio(it->first, it->second->getDescripcion());
            aux.insert(ejercicio);
        }
    }
    return aux;
}


Leccion::~Leccion()
{
    this->ejs.clear();
}

Ejercicio *Leccion::buscarEjercicioLeccion(int id)
{
    map<int, Ejercicio *> ejercicios = this->getEjercicios();
    for(map<int, Ejercicio *>::iterator it = ejercicios.begin(); it != ejercicios.end(); ++it) {
        if(it->second->getId() == id)
        {
            return it->second;
        }
    }
    return NULL;
}
