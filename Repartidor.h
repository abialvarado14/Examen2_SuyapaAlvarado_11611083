#pragma once
#include "Persona.h"

#include <string>
using namespace std;

class Repartidor : public Persona{

protected:

	string Dificultad;
	double Dinero;

public:
	
	Repartidor(string, double, string, int, string);
	string getDificultad();
	void setDificultad(string Dificultad);
	double getDinero();
	void setDinero(double Dinero);


};
