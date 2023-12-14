#ifndef _LECCION_H
#define _LECCION_H
#include "Inscripcion.h"
#include "Ejercicio.h"
#include "DTInfoLeccion.h"
#include <string>
#include <DTEjercicio.h>
using namespace std;

class Inscripcion;
class Ejercicio;
class Leccion
{
private:
	string Tema;
	string Objetivo;
	map<int, Ejercicio *> ejs;

public:
	Leccion(string tema, string obj);
	map<int, Ejercicio *> getEjercicios();;
	void agregarEjercicio(string descripcion, string ejercicio, string solucion, int tipo, int id);
	string getTema();
    void setTema(std::string tema);
    string getObjetivo();
    void setObjetivo(std::string obj);
	set<DTEjercicio*> NoAprobadosEjerciciosLecciones(Inscripcion *inscripcion);
	Ejercicio *buscarEjercicioLeccion(int id);
	InfoLeccion* getInfo();
	~Leccion();
};

#endif //_LECCION_H
