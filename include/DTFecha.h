#ifndef _FECHA_H
#define _FECHA_H
#include <iostream>
using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int ano;

public:
    Fecha(int dia, int mes, int ano);
    friend ostream &operator<<(ostream &os, Fecha *fecha);
    string getDia();
    string getMes();
    string getAno();
    ~Fecha();
};
#endif //_FECHA_H