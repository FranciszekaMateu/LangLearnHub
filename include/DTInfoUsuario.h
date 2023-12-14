#ifndef _DTINFOUSUARIO_H
#define _DTINFOUSUARIO_H

#include <string>
using namespace std;

class InfoUsuario {
private:
    string nombre;
    string descripcion;

public:
    InfoUsuario(string nombre, string descripcion);
    string getNombre();
    string getDescripcion();
    virtual ~InfoUsuario();
};

#endif // _DTINFOUSUARIO_H
