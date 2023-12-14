#ifndef _ISUSCRIPTO_H
#define _ISUSCRIPTO_H
#include <string>
using namespace std;
class ISuscripto
{
public:
    ISuscripto();
    virtual void notificar(string Idioma,string Curso) = 0; // función virtual pura
    virtual ~ISuscripto();        // virtual ~ISuscripto();
};

#endif