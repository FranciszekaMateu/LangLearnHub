#ifndef _PROFESOR_H
#define _PROFESOR_H

#include "Usuario.h"
#include "Curso.h"
#include "Idioma.h"
#include "DTInfoProfesor.h"
#include <string>

using namespace std;
class Curso;
class Profesor : public Usuario
{
private:
	string Instituto;
	set<Curso *> cursos;
	set<Idioma *> idiomas;
	InfoProfesor* info;

public:
	Profesor(string nickname, string contrasena, string nombre, string descrp, string instituto);
	set<string> listarIdiomas();
	string getNickname();
	void setIdiomas(set<Idioma *> idiomasAgregar);
	set<Idioma *> getIdiomas();
	InfoProfesor getDatos();
	string getInstituto();
	void setInfoProfesor(InfoProfesor *info);
	void infoUsuario() override;
	void setCurso(Curso* curso);
	void removeCurso(Curso* curso);
	set<Curso *> listarCursos();
	//  Set PromedioCurso promedios(); Terminar
	~Profesor();
};

#endif // _PROFESOR_H
