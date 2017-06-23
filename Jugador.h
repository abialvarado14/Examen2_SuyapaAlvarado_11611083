#pragma once
#include "Persona.h"

#include <string>
using namespace std;
class Jugador : public Persona{

protected:

	string Lugar;
	string Apodo;
	double Dinero;


public:

	Jugador(string, string, double, string, int, string);
	string getLugar();
	void setLugar(string Lugar);
	string getApodo();
	void setApodo(string Apodo);
	double getDinero();
	void setDinero(double Dinero);

};