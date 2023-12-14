#ifndef _USUARIO_H
#define _USUARIO_H

#include <string>
#include <set>
#include <vector>
#include "Notificacion.h"
#include "ISuscripto.h"
#include "Idioma.h"
using namespace std;

class Usuario : public ISuscripto
{
private:
    string nombre;
    string nickname;
    string contrasena;
    string descripcion;
    vector<Notificacion *> Notificaciones;

public:
    Usuario(string name, string nick, string contra, string descrp);
    void eliminarNotificaciones();
    vector<Notificacion *> getNotificaciones();
    void borrarNotificacionCurso(string nombreCurso);
    void crearNotificacion(string curso, string idioma);
    Usuario *seleccionarUsuario();
    string getNickname();
    string getNombre();
    string getContrasena();
    string getDescripcion();
    virtual void infoUsuario() = 0;
    void notificar(string Idioma,string Curso);
    virtual ~Usuario();
};

#endif //_USUARIO_H
