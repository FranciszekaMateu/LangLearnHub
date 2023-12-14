#include "../include/ContUsuario.h"
#include "../include/ContCurso.h"
#include "../include/DTFecha.h"

Contusuario *Contusuario::instanciaUsuario;
Contusuario::Contusuario() : IContUsuario()
{
}

Contusuario *Contusuario::getInstancia()
{
    if (instanciaUsuario == NULL)
    {
        instanciaUsuario = new Contusuario();
    }
    return instanciaUsuario;
}
// crear profe

Contusuario *contU = Contusuario::getInstancia();

void Contusuario::altaProfesor(string nick, string password, string nombre, string descripcion, string instituto)
{

    // creo al profe con los datos obtenidos
    Profesor *prof = new Profesor(nick, password, nombre, descripcion, instituto);

    prof->setIdiomas(this->getIdiomaRecordado());
    contU->setusuarioSistema(prof);
    this->idiomaRecordados.clear();
}

void Contusuario::setidiomaSistema(Idioma *i)
{

    this->idiomaSistema.insert(i);
}
// crear estudiante

void Contusuario::altaEstudiante(string nickname, string contrasena, string nombre, string descrp, string pais)
{

    Estudiante *alumno = new Estudiante(nickname, contrasena, nombre, descrp, pais);
    alumno->setFecha(this->fecharecordada);
    contU->setusuarioSistema(alumno);
}

set<string> Contusuario::listarIdiomas(set<Idioma *> idiomas)
{
    set<string> res;
    for (Idioma *idioma : idiomas)
    {
        res.insert(idioma->getNombre());
    }
    return res;
}

void Contusuario::setusuarioSistema(Usuario *usuario)
{

    this->usuarioSistema[usuario->getNickname()] = usuario;
}

map<string, Usuario *> Contusuario::getUsuarioSistema()
{
    return this->usuarioSistema;
}
set<string> Contusuario::listarUsuarios(map<string, Usuario *> usuarios)
{
    set<string> res;
    if (usuarios.empty())
    {
    }
    else
    {
        for (pair<string, Usuario *> usuario : usuarios)
        {
            res.insert(usuario.first);
        }
    }
    return res;
}
InfoProfesor *Contusuario::infoProfesor()
{
    Profesor *profe = dynamic_cast<Profesor *>(this->getUsuarioRecordado());

    InfoProfesor *info = new InfoProfesor(profe->getNombre(), profe->getDescripcion(), profe->getInstituto(), profe->getIdiomas());

    profe->setInfoProfesor(info);

    return info;
}

InfoEstudiante *Contusuario::infoEstudiante()
{
    string nombre, descripcion;
    Estudiante *estudiante = dynamic_cast<Estudiante *>(this->getUsuarioRecordado());
    InfoEstudiante *info = new InfoEstudiante(estudiante->getNombre(), estudiante->getDescripcion(), estudiante->getPais(), estudiante->getFecha());
    return info;
}

set<Idioma *> Contusuario::getIdiomas()
{
    return this->idiomaSistema;
}

void Contusuario::altaIdioma(string nombre)
{

    Idioma *nuevo = new Idioma(nombre);

    contU->setidiomaSistema(nuevo);
}

void Contusuario::setIdiomaRecordado(set<Idioma *> idiomas)
{
    this->idiomaRecordados = idiomas;
}

set<Idioma *> Contusuario::getIdiomaRecordado()
{
    return this->idiomaRecordados;
}

void Contusuario::setusuarioRecordado(Usuario *usuario)
{
    this->usuarioRecorado = usuario;
}

Usuario *Contusuario::getUsuarioRecordado()
{
    return this->usuarioRecorado;
}

void Contusuario::seleccionarIdiomas(set<string> idiomas)
{
    set<Idioma *> idiomasProfe;

    for (string i : idiomas)
    {
        for (Idioma *idioma : this->getIdiomas())
        {
            if (i == idioma->getNombre())
                idiomasProfe.insert(idioma);
        }
    }

    this->setIdiomaRecordado(idiomasProfe);
}
void Contusuario::getFecha(int dia, int mes, int ano)
{
    Fecha *fecha = new Fecha(dia, mes, ano);
    setFecharecordada(fecha);
}

Profesor *Contusuario::seleccionarProfesor(string nicknameProfesor)
{
    Profesor *profesor;
    for (pair<string, Usuario *> it : this->getUsuarioSistema())
    {

        if (it.first == nicknameProfesor)
        {
            profesor = dynamic_cast<Profesor *>(it.second);
            break;
        }
    }
    return profesor;
}

set<string> Contusuario::listarProfesores()
{
    set<string> res;
    for (pair<string, Usuario *> profe : this->getUsuarioSistema())
    {

        Profesor *p = dynamic_cast<Profesor *>(profe.second);
        if (p != NULL)
        {
            res.insert(p->getNickname());
        }
    }
    return res;
}

bool Contusuario::esProfesor()
{
    Usuario *u = this->getUsuarioRecordado();
    bool profesor;
    Profesor *p = dynamic_cast<Profesor *>(u);
    if (p != NULL)
    {
        profesor = true;
    }
    else
    {
        profesor = false;
    }

    return profesor;
}

void Contusuario::seleccionarUsuario(string nombre)
{
    Usuario *u;
    bool encontrado = false;
    for (pair<string, Usuario *> punt : this->getUsuarioSistema())
    {
        if (nombre == punt.first)
        {
            u = punt.second;
            encontrado = true;
            break;
        }
    }
    this->setusuarioRecordado(u);
}
set<string> Contusuario::listarNombreIdiomas()
{
    set<string> aux;
    for (Idioma *id : this->getIdiomas())
    {
        aux.insert(id->getNombre());
    }
    return aux;
};

set<string> Contusuario::listarNicknameUsuarios()
{
    return this->listarUsuarios(this->usuarioSistema);
};

void Contusuario::seleccionarProf(string nicknameProfesor)
{
    this->seleccionarProfesor(nicknameProfesor);
};

set<string> Contusuario::listarNombreIdiomasProfe()
{
    ContCurso *cc = ContCurso::getInstancia();

    Profesor *prof = cc->getProfeRecordado();
    return prof->listarIdiomas();
};
set<DTEjercicio*> Contusuario::listarEjerciciosNoAprobados(string curso)
{
    Estudiante *estudiante = dynamic_cast<Estudiante *>(this->getUsuarioRecordado());
    this->setCursoRecordado(estudiante->buscarCursoEstudiante(curso));
    return estudiante->EjerciciosNoAprobadosEstudiante(curso);
}

void Contusuario::setFecharecordada(Fecha *fecha)
{
    this->fecharecordada = fecha;
}

set<string> Contusuario::listarEstudiantes()
{
    set<string> aux;
    for (pair<string, Usuario *> u : this->getUsuarioSistema())
    {
        Estudiante *est = dynamic_cast<Estudiante *>(u.second);
        if (est != NULL)
            aux.insert(u.first);
    }

    return aux;
}
void Contusuario::setCursoRecordado(Curso *curso)
{
    this->cursoRecordado = curso;
}

Curso *Contusuario::getCursoRecordado()
{
    return this->cursoRecordado;
}

void Contusuario::setEjRecord(Ejercicio * ej) {
    this->ejRecord = ej;
}

Ejercicio * Contusuario::getEjRecord() {
    return this->ejRecord;
}

string Contusuario::tipoEjRecord() {
    Completar * esEjC = dynamic_cast<Completar*>(this->getEjRecord());
    if (esEjC != NULL) {
        return "Completar";
    } else {
        return "Traduccion";
    }
}

set<string> Contusuario::listarCursosEstudianteNoAprobados(string nickname) {
    map<string,Usuario*>::iterator iter = this->getUsuarioSistema().find(nickname);
    Estudiante * est = dynamic_cast<Estudiante *>((*iter).second);
    this->setusuarioRecordado((*iter).second); // Si no anda le paso (*iter).second
    return est->listarCursosNoAprobados();
}

set<ProgresoCurso*> Contusuario::listarProgresoCursosEstudiante(string nickname) {
    map<string,Usuario*>::iterator iter = this->getUsuarioSistema().find(nickname);
    Estudiante * est = dynamic_cast<Estudiante *>((*iter).second);
    set<ProgresoCurso*> res;
    for (pair <string, Inscripcion*> i : est->listarInscripciones()) {
        ProgresoCurso *aux = new ProgresoCurso(i.first, i.second->getProgreso());
        res.insert(aux);
    }
    return res;
}

set<PromedioCurso*> Contusuario::listarPromedioCursosProfesor(string nickname){
    map<string,Usuario*>::iterator iter = this->getUsuarioSistema().find(nickname);
    Profesor * prof = dynamic_cast<Profesor *>((*iter).second);
    set<PromedioCurso*> res;
    for (Curso* i : prof->listarCursos()){
        PromedioCurso *aux = new PromedioCurso(i->getNombre(), i->getPromedio());
        res.insert(aux);
    }
    return res;
}

bool Contusuario::ingresarSol(string sol) {
    Estudiante * est = dynamic_cast<Estudiante *>(this->getUsuarioRecordado());
    int id = this->getEjRecord()->getId();
    return est->ingresarSolEst(sol,this->cursoRecordado->getNombre(),id); // cambiar por el getter de curso
}

string Contusuario::mostrarParticular2()
{
    Completar *c = dynamic_cast<Completar *>(this->ejRecord);
    if (c != NULL)
    {
        return c->getFrase();
    } else {
        Traduccion *t = dynamic_cast<Traduccion *>(this->ejRecord);
        return t->getPalabra();
    }
}

void Contusuario::seleccionarEjercicio(int id)
{
    Curso *curso = this->getCursoRecordado();
    Ejercicio *ejercicio = curso->buscarEjercicioCurso(id);
    cout << ejercicio->getId() << endl; 
    this->setEjRecord(ejercicio);
}

set<string> Contusuario::listarNombreIdiomasNoSuscritos() {
    set<string> res;
    ISuscripto* s = dynamic_cast<ISuscripto*>(this->usuarioRecorado);
    for (Idioma* i : this->idiomaSistema) {
        if (!i->consultarUsuario(s)) {
            res.insert(i->getNombre());
        }
    }
    return res;
};


void Contusuario::seleccionarIdiomasASuscribirse(set<string> idiomas) {
    for (string n : idiomas) {
        Idioma *aux;
        for(Idioma *i : this->idiomaSistema){
            if (i->getNombre() == n){
                aux = i;
            ISuscripto* s = dynamic_cast<ISuscripto*>(this->usuarioRecorado);
            aux->Agregar(s);
            }
        }
    }
};

set<DTNotificacion*> Contusuario::listarNotificacionesUsuario() {
    set<DTNotificacion*> res;
    for (Notificacion* n : this->usuarioRecorado->getNotificaciones()) {
        DTNotificacion* d = new DTNotificacion (n->getNombreCurso(), n->getIdiomaCurso());
        res.insert(d);
    };
    return res;
};

void Contusuario::eliminarNotificacionesUsuario() {
    this->usuarioRecorado->eliminarNotificaciones();
};

set<string> Contusuario::listarIdiomasSuscritos() {
    set<string> res;
    ISuscripto* s = dynamic_cast<ISuscripto*>(this->usuarioRecorado);
    for (Idioma* i : this->idiomaSistema) {
        if (i->consultarUsuario(s)) {
            res.insert(i->getNombre());
        }
    }
    if (res.empty()) {
        res.insert("No se ha suscrito a ningun Idioma.");
    }
    return res;
};

void Contusuario::eliminarSuscripcion(set<string> idiomas) {
    for (string i : idiomas) {
        set<Idioma*>::iterator id = this->idiomaSistema.begin();
        while (id != this->idiomaSistema.end() && i.compare((*id)->getNombre()) != 0) {
            id++;
        }
        if (id != this->idiomaSistema.end()) {
            ISuscripto* s = dynamic_cast<ISuscripto*>(this->usuarioRecorado);
            (*id)->eliminar(s);
        }
    }
} 

bool Contusuario::tieneInscripciones() {
    Estudiante* est = dynamic_cast<Estudiante*>(this->getUsuarioRecordado());
    return (est->getInscripciones().empty());
}

void Contusuario::limpiarIdiomas() {
    set <Idioma*> langs = this->idiomaSistema;
    for (set<Idioma*>::iterator it = langs.begin(); it != langs.end(); it++) {
        Idioma* borrar = *it;
        this->idiomaSistema.erase(*it);
        delete borrar;
    }
    this->idiomaSistema.clear();
}

void Contusuario::limpiarUsuarios() {
    map<string, Usuario*> users = this->usuarioSistema;
    for (map<string, Usuario*>::iterator it = users.begin(); it != users.end(); it++) {
        Usuario * borrar = (*it).second;
        this->usuarioSistema.erase((*it).first);
        delete borrar;
    }
    this->usuarioSistema.clear();
}
