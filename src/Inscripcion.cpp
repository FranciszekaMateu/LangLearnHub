#include "../include/Inscripcion.h"
#include <string>
#include <set>
#include "../include/Completar.h"
#include "../include/Traduccion.h"
#include "../include/Curso.h"
#include "../include/DTEjercicio.h"
using namespace std;
Inscripcion::Inscripcion(Fecha *fechains, Estudiante *estudiante, Curso *curso)
{
    this->Fechainscripcion = fechains;
    this->Progreso = 0;
    this->Estudianteinscr = estudiante;
    this->Cursoinscripto = curso;
}

Curso *Inscripcion::getCurso()
{
    return this->Cursoinscripto;
}

void Inscripcion::setProgreso()
{
    float ejerciciostotales = 0;
    for (Leccion *it : this->getCurso()->getLecciones())
    {

        ejerciciostotales += it->getEjercicios().size();
    }
    if (ejerciciostotales == 0)
        this->Progreso = 0;

    else
        this->Progreso = (this->Aprobados.size() / ejerciciostotales) * 100;
}

float Inscripcion::getProgreso()
{
    setProgreso();
    return this->Progreso;
}

Estudiante *Inscripcion::getEstudiante()
{
    return this->Estudianteinscr;
}

set<Ejercicio *> Inscripcion::getAprobados()
{
    return this->Aprobados;
}

void Inscripcion::addAprobados(Ejercicio *ejer)
{
    this->Aprobados.insert(ejer);
}

bool Inscripcion::getCursoAprobado()
{
    return (this->getProgreso() == 100);
}

Fecha *Inscripcion::getFecha()
{
    return this->Fechainscripcion;
}

bool Inscripcion::getCursoSol(string sol, int id)
{
    bool res = false;
    Ejercicio *ej = this->getCurso()->buscarEjercicioCurso(id);
    Completar *ejC = dynamic_cast<Completar *>(ej);
    if (ejC != NULL)
    {
        if (ejC->verificarSolC(sol))
        {
            res = true;
            this->addAprobados(ej);
        }
    }
    else
    {
        Traduccion *ejT = dynamic_cast<Traduccion *>(ej);
        if (ejT->verificarSolT(sol))
        {
            res = true;
            this->addAprobados(ej);
        }
    }

    return res;
}

Inscripcion::~Inscripcion()
{
    this->Aprobados.clear();
}
