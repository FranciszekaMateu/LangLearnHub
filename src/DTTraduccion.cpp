#include "../include/DTTraduccion.h"

DTTraduccion::DTTraduccion(DTEjercicio *ej, string palabra) {
    this->ej = ej;
    this->palabra = palabra;
};

ostream &operator<<(ostream &os, DTTraduccion *info){
    cout << info->ej;
    cout << "Frase a traducir: " << info->palabra << endl;
    return os;
}

DTTraduccion::~DTTraduccion() {
    delete this->ej;
};