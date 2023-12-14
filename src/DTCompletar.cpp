#include "../include/DTCompletar.h"

DTCompletar::DTCompletar(DTEjercicio *ej, string frase) {
    this->ej = ej;
    this->frase = frase;
};

ostream &operator<<(ostream &os, DTCompletar *info){
    cout << info->ej;
    cout << "Frase a completar: " << info->frase << endl;
    return os;
}

DTCompletar::~DTCompletar() {
    delete this->ej;
};
