#ifndef _DTEJERCICIO_H
#define _DTEJERCICIO_H
#include <string>
#include <iostream>

using namespace std;

class DTEjercicio
{
private:
    int id;
    string descripcion;
public:
    DTEjercicio(int id, string descripcion);
    virtual ~DTEjercicio();
    string getDescripcion();
    int getId();
    friend ostream &operator<<(ostream &os, DTEjercicio *info);
    bool operator<(const DTEjercicio& other) const {
        return id < other.id;
    }
};

#endif 