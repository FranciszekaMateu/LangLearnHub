#include "../include/Idioma.h"

void Idioma::Agregar(ISuscripto *suscripto)
{
    if (this->Suscriptos.find(suscripto) == this->Suscriptos.end())
    {
        this->Suscriptos.insert(suscripto);
    }
}

void Idioma::eliminar(ISuscripto *suscripto)
{
    set<ISuscripto*>::iterator i;
    i = this->Suscriptos.find(suscripto);
    if (i != this->Suscriptos.end())
    {
        this->Suscriptos.erase(suscripto);
    }
}

void Idioma::modificar(string Curso)
{
    for (ISuscripto* i : this->Suscriptos)
    {
        Usuario* u = dynamic_cast<Usuario*>(i);
        u->notificar(this->getNombre(),Curso);
    }
}

bool Idioma::consultarUsuario(ISuscripto *suscripto)
{
    return (this->Suscriptos.find(suscripto) != this->Suscriptos.end());
}

set<ISuscripto *> Idioma::getSucripciones()
{
    return this->Suscriptos;
}

Idioma::Idioma(string nombre)
{
    this->Nombre = nombre;
}

string Idioma::getNombre()
{
    return this->Nombre;
}

Idioma::~Idioma(){
    this->Suscriptos.clear();
}
