#pragma once

#include <string>
#include "Repartidor.h"
#include "Jugador.h"

using namespace std;

class Mesa{

protected:

	int Num;
	string Tipo;
	Repartidor* repart;
	Jugador* gamer;

public:

	Mesa(int, string, Repartidor*, Jugador*);
	int getNum();
	void setNum(int);
	string getTipo();
	void setTipo(string);
	Repartidor* getRepartidor();
	void setRepartidor(Repartidor*);
	Jugador* getJugador();
	void setJugador(Jugador*);


};
