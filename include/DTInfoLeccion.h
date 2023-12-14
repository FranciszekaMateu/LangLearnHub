#ifndef _INFOLECCION_H
#define _INFOLECCION_H
#include <string>
#include <iostream>

using namespace std;

class InfoLeccion
{
private:
    string tema;
    string objetivo;
public:
    InfoLeccion(string tema, string objetivo);
    string getTema();
    friend ostream &operator<<(ostream &os, InfoLeccion *info);
    ~InfoLeccion();
};

#endif // INFOLECCION_H