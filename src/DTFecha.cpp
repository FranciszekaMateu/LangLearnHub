#include "../include/DTFecha.h"
#include <iostream>
#include <string>
using namespace std;

Fecha::Fecha(int dia, int mes, int ano)
{
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

string Fecha ::getDia()
{
    return to_string(this->dia);
}
string Fecha ::getMes()
{
    return to_string(this->mes);
}
string Fecha ::getAno()
{
    return to_string(this->ano);
}
ostream &operator<<(ostream &os, Fecha *fecha)
{
    os << fecha->getDia() << "/" << fecha->getMes() << "/" << fecha->getAno() << endl;
    return os;
};

Fecha::~Fecha(){}