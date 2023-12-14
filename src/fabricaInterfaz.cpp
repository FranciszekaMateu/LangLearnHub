#include "../include/fabricaInterfaz.h"
fabricaInterfaz *fabricaInstance = fabricaInterfaz::getInstancia();
fabricaInterfaz *fabricaInterfaz::Instancia;

fabricaInterfaz* fabricaInterfaz::getInstancia()
{
    if (Instancia == NULL)
    {
        Instancia = new fabricaInterfaz();
    }
    return Instancia;
}

fabricaInterfaz::fabricaInterfaz() {};

IContCurso* fabricaInterfaz::getICurso() {
    return ContCurso::getInstancia();
};

IContUsuario* fabricaInterfaz::getIUsuario() {
    return Contusuario::getInstancia();
};

fabricaInterfaz::~fabricaInterfaz() {};