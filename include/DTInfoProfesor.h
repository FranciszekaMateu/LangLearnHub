#ifndef _INFPROFE_H
#define _INFPROFE_H
#include "Idioma.h"
#include <string>
#include <set>
#include "DTInfoUsuario.h"
using namespace std;

class Idioma;

class InfoProfesor: public InfoUsuario
{
private:
    string nombre;
    string descripcion;
    string instituto;
    set<Idioma *> idiomas;

public:
    InfoProfesor(string nombre, string descripcion, string instituto, set<Idioma *> idiomas);
    string getInstuto();
    set<Idioma *> getIdiomas();
    ~InfoProfesor();
    friend ostream &operator<<(ostream &os, InfoProfesor *info);
};

#endif // INFPROFE_H