#pragma once

#include <string>
using namespace std;
class Persona{

protected:

	string Nombre;
	int Edad;
	string ID;

public:

	Persona(string, int, string);
	string getNombre();
	void setNombre(string Nombre);
	int getEdad();
	void setEdad(int Edad);
	string getID();
	void setID(string ID);


};
