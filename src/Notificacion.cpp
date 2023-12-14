#include "../include/Notificacion.h"

Notificacion::Notificacion(string curso, string idioma)
{
    this->idiomaCurso = idioma;
    this->nombreCurso = curso;
};

string Notificacion::getNombreCurso()
{
    return this->nombreCurso;
};

string Notificacion::getIdiomaCurso()
{
    return this->idiomaCurso;
};

Notificacion::~Notificacion(){

};