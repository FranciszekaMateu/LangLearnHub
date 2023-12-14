#include "../include/ContCurso.h"
#include "../include/Leccion.h"
#include <ctime>
#include <iostream>
#include <sstream>

Contusuario *ContUsuario = Contusuario::getInstancia();
ContCurso *ContCurso::instancia;

ContCurso::ContCurso() : IContCurso(){};

ContCurso *ContCurso::getInstancia()
{
    if (instancia == NULL)
        instancia = new ContCurso();
    return instancia;
};

set<string> ContCurso::listarNombreIdiomasDelProfe()
{

    set<string> idiomas;

    for (Idioma *i : this->profrecord->getIdiomas())
    {
        idiomas.insert(i->getNombre());
    }
    return idiomas;
};
void ContCurso::seleccionarProfesorRecordado(string nicknameProfesor)
{
    this->profrecord = ContUsuario->seleccionarProfesor(nicknameProfesor);
};

void ContCurso::seleccionarIdioma(string nombreIdioma)
{
    Contusuario *cc = Contusuario::getInstancia();

    Idioma *idioma;
    for (Idioma *i : cc->getIdiomas())
    {
        if (i->getNombre() == nombreIdioma)
        {
            idioma = i;
            break;
        }
    }

    this->idrecord = idioma;
};
void ContCurso::darDeAltaCurso(string nombre, string descripcion, Dificultad dificultad)
{
    Curso *curso = new Curso(nombre, descripcion, dificultad);
    curso->setIdioma(this->idrecord);
    curso->setPrevia(this->cursosPrevios);
    curso->setProfesor(this->profrecord);
    this->profrecord->setCurso(curso);
    this->agregarCurso(curso);
    this->cursosPrevios.clear();
    this->seleccionarCurso(curso->getNombre());
    this->notificarUsuarios();
}

map<string, Curso *> ContCurso::getCursos()
{
    return this->cursosSistema;
}

void ContCurso::agregarPreviasCurso(set<string> nombreCurso)
{
    map<string, Curso *> aux = this->getCursos();

    this->cursosPrevios.clear();

    for (string i : nombreCurso)
    {
        this->cursosPrevios[this->getCursos().find(i)->first] = this->getCursos().find(i)->second;
    }
}

set<string> ContCurso::listarCursosHabilitado()
{
    set<string> res;
    for (pair<string, Curso *> it : this->getCursos())
    {
        if (it.second->getHabilitado())
            res.insert(it.first);
    }
    return res;
}

Profesor *ContCurso::getProfeRecordado()
{
    return this->profrecord;
}

void ContCurso::agregarCurso(Curso *curso)
{
    this->cursosSistema[curso->getNombre()] = curso;
}

void ContCurso::habilitarCurso()
{
    Curso *c = this->getCursoRecordado();
    c->setHabilitado();
}

Idioma *ContCurso::getIdiomaRec()
{
    return this->idrecord;
}

map<string, Curso *> ContCurso::getPreviasRecordado()
{
    return this->cursosPrevios;
}

/*


*/
InfoCurso *ContCurso::infoCurso(string nombreCurso)
{
    seleccionarCurso(nombreCurso);
    return this->cursorecord->getInfo();
}

EstCurso *ContCurso::estCurso(string nombreCurso)
{
    seleccionarCurso(nombreCurso);
    return this->cursorecord->getEst();
}
/*void ContCurso::agregarCursos(Curso *curso)
{
    this->cursos[curso->getNombre()] = curso;
} */

set<string> ContCurso::listarNombreCursosNoHabilitados()
{
    set<string> res;
    for (map<string, Curso *>::iterator aux = this->cursosSistema.begin(); aux != this->cursosSistema.end(); aux++)
    {
        if (!(aux->second)->getHabilitado())
            res.insert(aux->second->getNombre());
    }
    return res;
}

void ContCurso::seleccionarCurso(string nombreCurso)
{
    /*map<string, Curso *>::iterator i = this->cursosSistema.begin();
    while (i != this->cursosSistema.end() && (*i).second->getNombre().compare(nombreCurso) != 0) {
        i++;
    }
    this->cursorecord = (*i).second;*/
    map<string, Curso *>::iterator it = this->cursosSistema.find(nombreCurso);
    this->cursorecord = (*it).second;
}

set<InfoCursoDisponible *> ContCurso::listarCursosDisponibles(string nickname)
{
    seleccionarEstudiante(nickname);
    set<InfoCursoDisponible *> res;
    for (pair<string, Curso *> i : this->getCursos())
    {
        if (this->estrecord->aptoParaCursar(i.second))
        {
            res.insert(i.second->getInfoDisponible());
        }
    }
    return res;
};

set<string> ContCurso::listarCursos()
{
    set<string> res;
    for (pair<string, Curso *> i : this->cursosSistema)
    {
        res.insert(i.first);
    }
    return res;
}

void ContCurso::seleccionarEstudiante(string nickname)
{
    Contusuario *cu = Contusuario::getInstancia();
    map<string, Usuario *> m = cu->getUsuarioSistema();
    map<string, Usuario *>::iterator i = m.find(nickname);
    this->estrecord = dynamic_cast<Estudiante *>(i->second);
};

void ContCurso::crearLeccion(string Tema, string Objetivo)
{
    Leccion *nuevaLeccion = new Leccion(Tema, Objetivo);
    this->cursorecord->setLecciones(nuevaLeccion);
    this->lecrecord = nuevaLeccion;
    this->cursorecord->masLeccion();
}

void ContCurso::crearCompletar(string descripcion, string ejercicio, string solucion)
{
    this->IDactual++;
    this->lecrecord->agregarEjercicio(descripcion, ejercicio, solucion, 0, this->IDactual); // 0 es completar por ahora
    this->cursorecord->masEjercicio();
}

void ContCurso::crearTraduccion(string descripcion, string ejercicio, string solucion)
{
    this->IDactual++;
    this->lecrecord->agregarEjercicio(descripcion, ejercicio, solucion, 1, this->IDactual); // 1 es traduccion por ahora
    this->cursorecord->masEjercicio();
}

Curso *ContCurso::getCursoRecordado()
{
    return this->cursorecord;
};

set<string> ContCurso::listarLecciones()
{
    set<string> aux;
    Curso *curso = this->cursorecord;
    for (Leccion *l : curso->getLecciones())
    {
        aux.insert(l->getTema());
    }
    return aux;
}

vector<InfoLeccion *> ContCurso::listarInfoLeccion()
{
    vector<InfoLeccion *> res;
    Curso *curso = this->cursorecord;
    for (Leccion *l : curso->getLecciones())
    {
        InfoLeccion *aux = l->getInfo();
        res.push_back(aux);
    }
    return res;
}

void ContCurso::seleccionarLeccion(string nombreTema)
{
    vector<Leccion *> aux = this->cursorecord->getLecciones();
    vector<Leccion *>::iterator it = aux.begin();
    while (it != aux.end() && (*it)->getTema() != nombreTema)
    {
        it++;
    }
    if (it != aux.end())
        this->lecrecord = *it;
}
void ContCurso::notificarUsuarios()
{
    this->idrecord->modificar(this->cursorecord->getNombre());
}

void ContCurso::infoLeccion(string desc, string tema) {}

set<string> ContCurso::listarNombreCurso()
{
    set<string> aux;
    for (pair<string, Curso *> it : this->getCursos())
    {
        aux.insert(it.first);
    }
    return aux;
}

set<string> ContCurso::listarNombreCursosPrevios()
{
    set<string> aux;
    return aux;
}

InfoLeccion *ContCurso::mostrarLeccion()
{
    return this->lecrecord->getInfo();
}

void ContCurso::seleccionarEjercicio(int ID)
{
    map<int, Ejercicio *>::iterator it = this->ejerciciosSistema.find(ID);
    this->ejrecord = it->second;
};

void ContCurso::setEjercicioSistema(Ejercicio *ejs)
{
    this->ejerciciosSistema.insert({ejs->getId(), ejs});
}

/*string ContCurso::mostrarInfoParticularCompletar()
{
    Completar *com = dynamic_cast<Completar *>(this->ejrecord);
    if (com != NULL)
        return com->getFrase();
    else
        return "";
}*/

/*string ContCurso::mostrarInfoParticularTraduccion()
{
    Traduccion *com = dynamic_cast<Traduccion *>(this->ejrecord);
    if (com != NULL)
        return com->getPalabra();
    else
        return "";
}*/

void ContCurso::eliminarCurso(string nombreCurso)
{
    Contusuario *cu = Contusuario::getInstancia();
    Curso *auxC = (this->cursosSistema.find(nombreCurso))->second;
    set<Inscripcion *> auxI = auxC->getInscripciones();
    for (Inscripcion *i : auxI)
    {
        Estudiante *auxE = i->getEstudiante();
        auxE->removeInscripcion(i->getCurso()->getNombre());
        delete i;
    }
    vector<Leccion *> auxL = auxC->getLecciones();
    for (Leccion *l : auxL)
    {
        map<int, Ejercicio *> auxE = l->getEjercicios();
        for (pair<int, Ejercicio *> e : auxE)
        {
            this->ejerciciosSistema.erase(e.first);
            delete e.second;
        }
        delete l;
    }
    for (pair<string, Curso *> c : this->cursosSistema)
    {
        c.second->removePrevias(nombreCurso);
    }
    //.....Eliminar suscripciones.....//
    for (string prof : cu->listarProfesores())
    {
        cu->seleccionarProfesor(prof)->removeCurso(auxC);
    }
    this->cursosSistema.erase(nombreCurso);
    delete auxC;
}

map<int, string> ContCurso::listarEjercicios()
{
    map<int, string> aux;
    for (pair<int, Ejercicio *> i : this->lecrecord->getEjercicios())
    {

        aux[i.first] = i.second->getDescripcion();
    }
    return aux;
}

DTEjercicio *ContCurso::mostrarEjercicio()
{

    return this->ejrecord->getInfo();
}

bool ContCurso::mostrarParticular(DTEjercicio *ej)
{
    Completar *c = dynamic_cast<Completar *>(this->ejrecord);
    if (c != NULL)
    {
        return true;
    }
    else
    {
        Traduccion *t = dynamic_cast<Traduccion *>(this->ejrecord);
        return false;
    }
}

DTCompletar *ContCurso::mostrarParticularC(DTEjercicio *ej)
{
    Completar *c = dynamic_cast<Completar *>(this->ejrecord);
    if (c != NULL)
    {
        DTCompletar *res1 = new DTCompletar(ej, c->getFrase());
        return res1;
    }
    else
    {
        return NULL;
    }
}

DTTraduccion *ContCurso::mostrarParticularT(DTEjercicio *ej)
{
    Traduccion *t = dynamic_cast<Traduccion *>(this->ejrecord);
    if (t != NULL)
    {
        DTTraduccion *res2 = new DTTraduccion(ej, t->getPalabra());
        return res2;
    }
    else
    {
        return NULL;
    }
}

void ContCurso::inscribirseCurso(string nombreCurso)
{
    time_t actual = time(0);

    tm *tiempo = localtime(&actual);

    int dia = tiempo->tm_mday;
    int mes = tiempo->tm_mon + 1;
    int anio = tiempo->tm_year + 1900;

    this->seleccionarCurso(nombreCurso);
    Fecha *fecha = new Fecha(dia, mes, anio);
    Inscripcion *i = new Inscripcion(fecha, this->estrecord, this->cursorecord);
    this->estrecord->addInscripcion(nombreCurso, i);
    this->cursorecord->setInscripcion(i);
}

set<Infoinscripcion*> ContCurso::getInfoInscripciones()
{
    Curso *curso = this->cursorecord;
    set<Infoinscripcion*> res;
    for (Inscripcion *i : curso->getInscripciones())
    {
        Infoinscripcion * aux = new Infoinscripcion(i->getEstudiante()->getNombre(), i->getFecha());
        res.insert(aux);
    }
    return res;
}

void ContCurso::agregarinscr(string nombreEstudiante, string nombreCurso, string fecha)
{
    this->seleccionarEstudiante(nombreEstudiante);
    this->seleccionarCurso(nombreCurso);
    int dia, mes, ano;
    istringstream fechaseparada(fecha);
    char delim;
    fechaseparada >> dia >> delim >> mes >> delim >> ano;

    Fecha *fechadeins = new Fecha(dia, mes, ano);
    Inscripcion *i = new Inscripcion(fechadeins, this->estrecord, this->cursorecord);
    this->estrecord->addInscripcion(nombreCurso, i);
    this->cursorecord->setInscripcion(i);
}

void ContCurso::agregarAprobados(string nombreEstudiante, string nombreCurso, int id)
{
    this->seleccionarEstudiante(nombreEstudiante);

    map<int, Ejercicio *>::iterator it = this->ejerciciosSistema.find(id);
    this->estrecord->getInscripcion(nombreCurso)->addAprobados(it->second);
}

void ContCurso::limpiarCursos() {
    map<string, Curso *> deleteCursos = this->cursosSistema;
    for (map<string, Curso *>::iterator it = deleteCursos.begin(); it != deleteCursos.end(); it++) {
        eliminarCurso((*it).first);
    }
    this->cursosSistema.clear();
    this->cursosPrevios.clear();
    this->ejerciciosSistema.clear();
}