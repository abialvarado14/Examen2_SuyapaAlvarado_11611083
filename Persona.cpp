#include "Persona.h"

Persona::Persona( string Nombre,  int Edad,  string ID) {
	this-> Nombre=Nombre;
	this-> Edad=Edad;
	this-> ID=ID;
}


string Persona::getNombre(){

return Nombre;
}

void Persona::setNombre(string Nombre){
	this->Nombre =Nombre;
}

int Persona::getEdad(){

return Edad;
}

void Persona::setEdad(int Edad){
	this->Edad =Edad;
}

string Persona::getID(){

return ID;
}

void Persona::setID(string ID){
	this->ID =ID;
}

