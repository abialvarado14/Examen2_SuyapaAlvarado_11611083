#include "Jugador.h"

Jugador::Jugador( string Lugar,  string Apodo,  double Dinero,  string Nombre,  int Edad,  string ID) : Persona(Nombre, Edad, ID) {
	this-> Lugar=Lugar;
	this-> Apodo=Apodo;
	this-> Dinero=Dinero;
	this-> Nombre=Nombre;
	this-> Edad=Edad;
	this-> ID=ID;
}


string Jugador::getLugar(){

return Lugar;
}

void Jugador::setLugar(string Lugar){
this->Lugar =Lugar;
}

string Jugador::getApodo(){

return Apodo;
}

void Jugador::setApodo(string Apodo){
this->Apodo =Apodo;
}

double Jugador::getDinero(){

return Dinero;
}

void Jugador::setDinero(double Dinero){
this->Dinero =Dinero;
}
