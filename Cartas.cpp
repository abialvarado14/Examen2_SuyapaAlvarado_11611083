#include "Cartas.h"

Cartas::Cartas( string Valor,  string Simbolo,  string Color) {
	this-> Valor=Valor;
	this-> Simbolo=Simbolo;
	this-> Color=Color;
}


string Cartas::getValor(){

return Valor;
}

void Cartas::setValor(string Valor){
	this->Valor =Valor;
}

string Cartas::getSimbolo(){

return Simbolo;
}

void Cartas::setSimbolo(string Simbolo){
	this->Simbolo =Simbolo;
}

string Cartas::getColor(){

return Color;
}

void Cartas::setColor(string Color){
	this->Color =Color;
}
