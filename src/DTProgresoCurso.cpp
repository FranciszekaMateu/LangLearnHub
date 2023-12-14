#include "../include/DTProgresoCurso.h"
#include <string>
#include <set>
using namespace std;

ProgresoCurso::ProgresoCurso(string nombreCurso, int progreso)
{
    this->nombreCurso = nombreCurso;
    this->progreso = progreso;
}

ostream &operator<<(ostream &os, ProgresoCurso *prog)
{
    cout << "Curso: " << prog->nombreCurso << endl;
    cout << "Progreso: " << prog->progreso << "%" << endl;
    return os;
}

ProgresoCurso::~ProgresoCurso(){}