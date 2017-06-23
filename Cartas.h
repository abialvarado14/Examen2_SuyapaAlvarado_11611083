#pragma once

#include <string>
using namespace std;

class Cartas{

protected:
	string Valor;
	string Simbolo;
	string Color;

public:
	Cartas(string, string, string);
	string getValor();
	void setValor(string Valor);
	string getSimbolo();
	void setSimbolo(string Simbolo);
	string getColor();
	void setColor(string Color);


};
