#include "../include/Ejercicio.h"
#include "../include/Completar.h"

#include <string>
#include <iostream>
using namespace std;

/*class Completar: public Ejercicio {
private:
    string frase;
    string fraseCompleta;
public:
    Completar(string descripcion, string frase, string fraseCompleta);
    void verificarSol(string); //Se ingresa la solucion y verifica si está bien
    string getFrase();
    string getFraseCompleta();
    virtual ~Completar();
};*/

Completar::Completar(string descripcion, string frase, string fraseCompleta, int id) : Ejercicio(descripcion, id)
{
    this->frase = frase;
    this->fraseCompleta = fraseCompleta;
}

string Completar::getFrase()
{
    return this->frase;
}

string Completar::getFraseCompleta()
{
    return this->fraseCompleta;
}

bool Completar::verificarSolC(string sol) {
    return (this->fraseCompleta == sol);
}

Completar::~Completar()
{
}
