#include "Repartidor.h"

Repartidor::Repartidor(Baraja* baraj, string Dificultad,  double Dinero, string Nombre, int Edad, string ID) : Persona(Nombre, Edad, ID){
	this-> Dificultad=Dificultad;
	this-> Dinero=Dinero;
	this-> Nombre=Nombre;
	this-> Edad=Edad;
	this-> ID=ID;
	this-> baraj=baraj;
}


string Repartidor::getDificultad(){

return Dificultad;
}

void Repartidor::setDificultad(string Dificultad){
this->Dificultad =Dificultad;
}

double Repartidor::getDinero(){

return Dinero;
}

void Repartidor::setDinero(double Dinero){
this->Dinero =Dinero;
}
