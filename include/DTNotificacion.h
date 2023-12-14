#ifndef _DTNOTIFICACION_H
#define _DTNOTIFICACION_H
#include <string>
#include <iostream>

using namespace std;

class DTNotificacion
{
private:
    string nombreCurso;
    string nombreIdioma;

public:
    DTNotificacion(string nombreCurso, string nombreIdioma);
    friend ostream &operator<<(ostream &os, DTNotificacion* info);
    ~DTNotificacion();
};

#endif 
