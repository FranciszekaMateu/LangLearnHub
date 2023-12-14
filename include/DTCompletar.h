#ifndef _DTCOMPLETAR_H
#define _DTCOMPLETAR_H
#include <string>
#include <iostream>
#include "DTEjercicio.h"

using namespace std;

class DTCompletar
{
private:
    DTEjercicio *ej;
    string frase;
    
public:
    DTCompletar(DTEjercicio *ej, string frase);
    friend ostream &operator<<(ostream &os, DTCompletar *info);
    ~DTCompletar();
};

#endif 