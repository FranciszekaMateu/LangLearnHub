#ifndef _FABRICAINTERFAZ_H
#define _FABRICAINTERFAZ_H
#include "../include/ContUsuario.h"
#include "../include/ContCurso.h"
#include "IContCurso.h"
#include "IContUsuario.h"

class fabricaInterfaz
{
private:
    static fabricaInterfaz *Instancia;
public:
    fabricaInterfaz();
    static fabricaInterfaz *getInstancia();
    IContCurso* getICurso();
    IContUsuario* getIUsuario();
    ~fabricaInterfaz();
};

#endif
