#include "Administrador.h"

Administrador::Administrador( int Experiencia,  string Rango,  double Sueldo, string Nombre, int Edad, string ID) : Persona(Nombre, Edad, ID){
	this-> Experiencia=Experiencia;
	this-> Rango=Rango;
	this-> Sueldo=Sueldo;
	this-> Nombre=Nombre;
	this-> Edad=Edad;
	this-> ID=ID;
}


int Administrador::getExperiencia(){

return Experiencia;
}

void Administrador::setExperiencia(int Experiencia){
	this->Experiencia =Experiencia;
}

string Administrador::getRango(){

return Rango;
}

void Administrador::setRango(string Rango){
	this->Rango =Rango;
}

double Administrador::getSueldo(){

return Sueldo;
}

void Administrador::setSueldo(double Sueldo){
	this->Sueldo =Sueldo;
}
