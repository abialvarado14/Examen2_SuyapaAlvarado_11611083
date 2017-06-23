#include "Mesa.h"
#include "Repartidor.h"
#include "Jugador.h"


Mesa::Mesa( int Num,  string Tipo,  Repartidor* repart,  Jugador* gamer) {
	this-> Num=Num;
	this-> Tipo=Tipo;
	this-> repart=repart;
	this-> gamer=gamer;
}


int Mesa::getNum(){

return Num;
}

void Mesa::setNum(int Num){
	this->Num =Num;
}

string Mesa::getTipo(){

return Tipo;
}

void Mesa::setTipo(string Tipo){
	this->Tipo =Tipo;
}

Repartidor* Mesa::getRepartidor(){

return repart;
}

void Mesa::setRepartidor(Repartidor* repart){
	this->repart =repart;
}

Jugador* Mesa::getJugador(){

return gamer;
}

void Mesa::setJugador(Jugador* gamer){
	this->gamer =gamer;
}
