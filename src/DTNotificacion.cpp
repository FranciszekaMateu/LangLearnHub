#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(string nombreCurso, string nombreIdioma){
    this->nombreCurso = nombreCurso;
    this->nombreIdioma = nombreIdioma;
};

ostream &operator<<(ostream &os, DTNotificacion* info) {
    cout << "Nombre: "<< info->nombreCurso << endl;
    cout << "Idioma: " << info->nombreIdioma << endl;
    return os;
};

DTNotificacion::~DTNotificacion() {};

