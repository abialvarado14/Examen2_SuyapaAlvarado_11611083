#pragma once
#include "Persona.h"

#include <string>
using namespace std;
class Administrador : public Persona{

protected:

	int Experiencia;
	string Rango;
	double Sueldo;

public:
	Administrador(int, string, double, string, int, string);
	int getExperiencia();
	void setExperiencia(int Experiencia);
	string getRango();
	void setRango(string Rango);
	double getSueldo();
	void setSueldo(double Sueldo);


};
