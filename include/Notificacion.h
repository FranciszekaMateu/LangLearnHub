#ifndef _NOTIFICACION_H
#define _NOTIFICACION_H

#include <string>

using namespace std;

class Notificacion
{
private:
    string nombreCurso;
    string idiomaCurso;

public:
    Notificacion(string curso, string idioma);
    string getNombreCurso();
    string getIdiomaCurso();
    virtual ~Notificacion();
};

#endif //_NOTIFICACION_H
