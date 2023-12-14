#ifndef _INFOESTUDIANTE_H
#define _INFOESTUDIANTE_H
#include <string>
#include "DTFecha.h"
#include "DTInfoUsuario.h"
using namespace std;

class InfoEstudiante : public InfoUsuario
{
private:
    string nombre;
    string descripcion;
    string pais;
    Fecha *fecha;

public:
    InfoEstudiante(string nombre, string descripcion, string pais, Fecha *fecha);
    string getPais();
    Fecha *getFecha();
    ~InfoEstudiante();
    friend ostream &operator<<(ostream &os, InfoEstudiante *info);
};

#endif // INFOESTUDIANTE