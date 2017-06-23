#include "Baraja.h"


Baraja::Baraja(){

	int cont=0;
	int cont2=0;
	int cont3=0;
	string* palo = new string[4];
	string* valor = new string[13];
	string* color = new string[2];
	valor[0] = "A";
	valor[1] = "2";
	valor[2] = "3";
	valor[3] = "4";
	valor[4] = "5";
	valor[5] = "6";
	valor[6] = "7";
	valor[7] = "8";
	valor[8] = "9";
	valor[9] = "10";
	valor[10] = "J";
	valor[11] = "Q";
	valor[12] = "K";

	palo[0] = "♥";
	palo[1] = "♠";
	palo[2] = "♦";
	palo[3] = "♣";

	color[0] = "negro";
	color[1] = "rojo";

	for (int i = 0; i < 52; ++i)
	{
		if (cont<13){
			this->bar.push_back(new Cartas(valor[cont], palo[cont2], color[cont3]));
			cont++;
		}else{
			cont=0;
			cont2++;
			if (i==26){
				cont3++;
			}
		}
	
	}

}


