#include "../include/Usuario.h"
#include "../include/Notificacion.h"

Usuario::Usuario(string name, string nick, string contra, string descrp) : ISuscripto()
{
    nombre = name;
    nickname = nick;
    contrasena = contra;
    descripcion = descrp;
};

string Usuario::getNickname()
{
    return this->nickname;
};
string Usuario::getNombre()
{
    return this->nombre;
};
string Usuario::getContrasena()
{
    return this->contrasena;
};

string Usuario::getDescripcion()
{
    return this->descripcion;
};

Usuario *Usuario::seleccionarUsuario()
{
    return this;
};

void Usuario::crearNotificacion(string curso, string idioma)
{
    Notificacion *noti = new Notificacion(curso, idioma);
    this->Notificaciones.insert(this->Notificaciones.begin(), noti);
};

void Usuario::borrarNotificacionCurso(string nombreCurso)
{
    vector<Notificacion *>::iterator i;
    i = this->Notificaciones.begin();
    while (i != this->Notificaciones.end() && (*i)->getNombreCurso().compare(nombreCurso) != 0)
        i++;
    if (i != this->Notificaciones.end())
    {
        Notificacion *borrar = *i;
        this->Notificaciones.erase(i);
        delete borrar;
    }
};

vector<Notificacion *> Usuario::getNotificaciones()
{
    return this->Notificaciones;
};

void Usuario::eliminarNotificaciones()
{
    vector<Notificacion *>::iterator i;
    i = this->Notificaciones.begin();
    while (i != this->Notificaciones.end())
    {
        Notificacion *borrar = *i;
        this->Notificaciones.erase(i);
        delete borrar;
        // i++;
    }
};
void Usuario::notificar(string Idioma, string Curso)
{
    Notificacion *notificar = new Notificacion(Curso, Idioma);
    this->Notificaciones.push_back(notificar);
}

Usuario::~Usuario()
{
    this->Notificaciones.clear();
    
}