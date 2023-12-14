#ifndef _PROGRESOCURSO_
#define _PROGRESOCURSO_
#include <string>
#include <set>
#include <iostream>

using namespace std;

class ProgresoCurso
{
private:
    string nombreCurso;
    int progreso;

public:
    ProgresoCurso(string nombreCurso, int progreso);
    friend ostream &operator<<(ostream &os, ProgresoCurso *prog);
    ~ProgresoCurso();
};

#endif // _PROGRESOCURSO_