#include "../include/DTPromedioCurso.h"
#include <string>
#include <set>
using namespace std;

PromedioCurso::PromedioCurso(string nombreCurso, int promedio)
{
    this->nombreCurso = nombreCurso;
    this->promedio = promedio;
}

ostream &operator<<(ostream &os, PromedioCurso *prom)
{
    cout << "Curso: " << prom->nombreCurso << endl;
    cout << "Promedio: " << prom->promedio << "%" << endl;
    return os;
}

PromedioCurso::~PromedioCurso(){}