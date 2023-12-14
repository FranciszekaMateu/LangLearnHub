#ifndef _PROMEDIOCURSO_H
#define _PROMEDIOCURSO_H
#include <string>
#include <set>
#include <iostream>
using namespace std;

class PromedioCurso
{
private:
  string nombreCurso;
  int promedio;

public:
  PromedioCurso(string nombreCurso, int promedio);
  friend ostream &operator<<(ostream &os, PromedioCurso *prom);
  ~PromedioCurso();
};

#endif // __PROMEDIOCURSO_H