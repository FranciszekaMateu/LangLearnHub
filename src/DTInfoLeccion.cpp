#include "../include/DTInfoLeccion.h"
#include <string>
using namespace std;

InfoLeccion::InfoLeccion(string tema, string objetivo)
{
    this->tema = tema;
    this->objetivo = objetivo;
}

string InfoLeccion::getTema(){
    return this->tema;
}

ostream &operator<<(ostream &os, InfoLeccion *info){
    cout << "Tema: " << info->tema << endl;
    cout << "Ojbetivo: " << info->objetivo << endl;
    return os;
}
InfoLeccion::~InfoLeccion() {};
