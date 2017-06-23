#pragma once
#include "Persona.h"
#include "Baraja.h"

#include <string>
using namespace std;

class Repartidor : public Persona{

protected:

	string Dificultad;
	double Dinero;
	Baraja* baraj;


public:
	
	Repartidor(Baraja*, string, double, string, int, string);
	string getDificultad();
	void setDificultad(string Dificultad);
	double getDinero();
	void setDinero(double Dinero);



};
