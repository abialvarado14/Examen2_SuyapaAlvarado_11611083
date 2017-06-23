#include "Administrador.h"
#include "Cartas.h"
#include "Jugador.h"
#include "Mesa.h"
#include "Persona.h"
#include "Repartidor.h"
#include "Baraja.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

bool SimuladorJuego();

int main(){
	vector <Mesa*> Mesas;
	vector <Repartidor*> Repartidores;
	vector <Administrador*> Administradores;
	vector <Jugador*> Jugadores;
	int opc, rangopc, difopc, opc2, num, tipopc, posjug, posrep, posmesa;
	string lugar, apodo, nombre, ID, rango, dificultad, tipo;
	int edad, year, posjuego;
	double dineroj, sueldo, apuesta;
	bool habilitado, ganador;
	srand(time(NULL));
	

	cout << "-----BIENVENIDO A BLACK JACK-----" << endl << endl;
	cout << "Ingrese la opción que desea: \n1.Crear Jugador\n2.Crear Administrador\n3.Crear Repartidor\n4.Login como jugador\n5.Login como Administrador:\n6.Salir ";
	cin >> opc;

	while (opc!=6){
		switch(opc){
			case 1:{
				cout << "----Crear Jugador----" << endl << endl;
				cout << "Ingrese el lugar de procedencia: ";
				cin >> lugar;
				cout << "Ingrese el apodo del jugador: ";
				cin >> apodo;
				cout << "Ingrese la cantidad de dinero del jugador: ";
				cin >> dineroj;
				cout << "Ingrese nombre del jugador: ";
				cin >> nombre;
				cout << "Ingrese edad del jugador: ";
				cin >> edad;
				cout << "Ingrese ID del jugador: ";
				cin >> ID;
				while (ID.size()!=4){
					cout << "---ERROR, ID DEBE TENER 4 NUMEROS." << endl;
					cout << "Ingrese ID del jugador: ";
					cin >> ID;

				}//VALIDACION ID

				Jugador* jug = new Jugador(lugar, apodo, dineroj, nombre, edad, ID);
				Jugadores.push_back(jug);
				break;
			}//FIN CASO1, CREAR JUGADOR

			case 2:{
				cout << "-----Crear Administrador------" << endl << endl;
				cout << "Ingrese años de experiencia: ";
				cin >> year;
				cout << "Rango: \n1.Gerente a tiempo completo\n2.Gerente Medio tiempo\n3.Generente General: ";
				cin >> rangopc;
				if (rangopc==1)
					rango = "GerenteTiempoCompleto";
				else if (rangopc==2)
					rango = "GerenteMedioTiempo";
				else
					rango = "GerenteGeneral";

				cout << "Ingrese el sueldo deseado: ";
				cin >> sueldo;

				cout << "Ingrese nombre del Administrador: ";
				cin >> nombre;
				cout << "Ingrese edad del Administrador: ";
				cin >> edad;
				cout << "Ingrese ID del Administrador: ";
				cin >> ID;
				while (ID.size()!=4){
					cout << "---ERROR, ID DEBE TENER 4 NUMEROS." << endl;
					cout << "Ingrese ID del Administrador: ";
					cin >> ID;

				}//VALIDACION ID
				Administrador* admi = new Administrador(year,rango,sueldo,nombre,edad,ID);
				Administradores.push_back(admi);

				break;
			}//FIN CASO2, CREAR ADMINISTRADOR

			case 3:{
				cout << "-------Crear Repartidor----" << endl << endl;
				cout << "Dificultad: \n1.Dificil\n2.Intermedio\3.Facil: ";
				cin >> difopc;
				if (difopc==1)
					dificultad = "Dificil";
				else if (difopc==2)
					dificultad = "Intermedio";
				else
					dificultad = "Facil";


				cout << "Dinero dado al casino: ";
				cin >> dineroj;

				cout << "Ingrese nombre del Repartidor: ";
				cin >> nombre;
				cout << "Ingrese edad del Repartidor: ";
				cin >> edad;
				cout << "Ingrese ID del Repartidor: ";
				cin >> ID;
				while (ID.size()!=4){
					cout << "---ERROR, ID DEBE TENER 4 NUMEROS." << endl;
					cout << "Ingrese ID del Repartidor: ";
					cin >> ID;

				}//VALIDACION ID
				Baraja* baraj = new Baraja();
				Repartidor* repart = new Repartidor(baraj, dificultad, dineroj, nombre, edad, ID);
				Repartidores.push_back(repart);

				break;
			}//FIN CASO3, CREAR REPARTIDOR

			case 4:{
				cout << "---LOGIN JUGADORES---" << endl << endl;
				cout << "Ingrese su nombre: ";
				cin >> nombre;
				cout << "Ingrese su ID: ";
				cin >> ID;

				for (int i = 0; i < Jugadores.size(); ++i)
				{
					if (Jugadores[i]->getNombre()==nombre && Jugadores[i]->getID() == ID){
						int posjugador = i;
						cout << "---BIENVENIDO AL JUEGO BLACKJACK!!" << endl << endl;
						
						for (int i = 0; i < Mesas.size(); ++i)
						{
							if (Mesas[i]->getJugador()->getNombre()==nombre){
								habilitado = true;
								posjuego = i;
								i = Mesas.size();
							}else{ 
								habilitado = false;
							}
						}
						if (habilitado==true){
							cout << "Ingrese su apuesta: ";
							cin >> apuesta;

							while (apuesta > Jugadores[posjugador]->getDinero()){
							cout << "No tiene suficiente dinero, para apostar esa cantidad!" << endl;
							cout << "Ingrese su apuesta: ";
							cin >> apuesta;
							}//VALIDACION DEL DINERO
							ganador = SimuladorJuego();

							if (ganador==true){
								cout << "Has ganado!!! " << apuesta*2 << " Lps" << endl;
								Jugadores[posjugador]->setDinero(Jugadores[posjugador]->getDinero()+apuesta*2);
								cout << "Tu saldo actual es: " << Jugadores[posjugador]->getDinero() << "Lps" << endl;
							}else{
								cout << "Has perdido!! " << apuesta << "Lps" << endl;
								Jugadores[posjugador]->setDinero(Jugadores[posjugador]->getDinero()-apuesta);
								cout << "Tu saldo actual es: " << Jugadores[posjugador]->getDinero() << "Lps" << endl;
								Mesas[posjuego]->getRepartidor()->setDinero(Mesas[posjuego]->getRepartidor()->getDinero()+apuesta);

							}


						}else{
							cout << "Lo sentimos, no esta asignado a ninguna mesa, consulte al administrador para asignarlo a una.. " << endl << endl;
						}

						

					}else{
						if (i==Jugadores.size()-1)
							cout << "USUARIO INCORRECTO" << endl << endl;
					}//FIN IF, VALIDACION USUARIOS IGUALES
					
				}//FIN FOR, LOGIN..
				break;
			}//FIN CASO 4, LOGIN JUGADOR

			case 5:{
				cout << "-----LOGIN ADMINISTRADOR---" << endl << endl;
				cout << "Ingrese nombre del administrador: ";
				cin >> nombre;
				cout << "Ingrese el ID del administrador: ";
				cin >> ID;

				for (int i = 0; i < Administradores.size(); ++i)
				{
					if (Administradores[i]->getNombre()==nombre && Administradores[i]->getID() == ID){
						cout << "---MENU PARA ADMINISTRADORES--" << endl << endl;
						i= Administradores.size();
						cout << "Ingrese la opcion que desea:\n1.Agregar Mesa\n2.Modificar Mesa\n3.Eliminar Mesa: ";
						cin >> opc2;
						if (opc2==1){
							if(Repartidores.size()==0||Jugadores.size()==0){
								cout << "Lo sentimos, en este momento no hay disponibles jugadores ni repartidores " << endl;
							}else{
								//AGREGAR MESA, CON VALIDACIÓN
								cout << "Ingrese numero de mesa: ";
								cin >> num;
								cout << "Ingrese tipo de mesa: \n1.VIP\n2.Clasica\n3.Viajero: ";
								cin >> tipopc;

								if (tipopc==1)
									tipo = "VIP";
								else if (tipopc==2)
									tipo = "Clasica";
								else
									tipo = "Viajero";

								cout << "--REPARTIDORES--" << endl;
								for (int i = 0; i < Repartidores.size(); ++i)
								{
									cout << i << " " << Repartidores[i]->getNombre() << " " << Repartidores[i]->getDificultad() << " " << Repartidores[i]->getDinero() << endl;
								}

								cout << "Ingrese la posicion del repartidor que desea: ";
								cin >> posrep;

								while (posrep>Repartidores.size() || posrep<0){
									cout << "ERROOR.. posicion inexistente" << endl;
									cout << "Ingrese la posicion del repartidor que desea: ";
									cin >> posrep;
								}
								cout << "---JUGADORES--" << endl;
								for (int i = 0; i < Jugadores.size(); ++i)
								{
									cout << i << " " << Jugadores[i]->getNombre() << " " << Jugadores[i]->getEdad() << " " << Jugadores[i]->getDinero() << endl;
								}
								cout << "Ingrese la posicion del jugador que desea: ";
								cin >> posjug;

								Mesa* mes = new Mesa(num, tipo, Repartidores[posrep], Jugadores[posjug]);
								Mesas.push_back(mes);
							//FIN AGREGAR MESAS VALIDADAS...
							}


						} else if (opc2==2){
							cout << "---MODIFICAR MESAS---" << endl << endl;
							for (int i = 0; i < Mesas.size(); ++i)
							{
								cout << i << " " << Mesas[i]->getNum() << " " << Mesas[i]->getTipo() << " " << Mesas[i]->getRepartidor()->getNombre() << " " << Mesas[i]->getJugador()->getNombre() << endl;
							}

							cout << "Que posicion desea cambiar: ";
							cin >> posmesa;

							cout << "Ingrese numero de mesa: ";
								cin >> num;
								cout << "Ingrese tipo de mesa: \n1.VIP\n2.Clasica\n3.Viajero: ";
								cin >> tipopc;

								if (tipopc==1)
									tipo = "VIP";
								else if (tipopc==2)
									tipo = "Clasica";
								else
									tipo = "Viajero";

								cout << "--REPARTIDORES--" << endl;
								for (int i = 0; i < Repartidores.size(); ++i)
								{
									cout << i << " " << Repartidores[i]->getNombre() << " " << Repartidores[i]->getDificultad() << " " << Repartidores[i]->getDinero() << endl;
								}

								cout << "Ingrese la posicion del repartidor que desea: ";
								cin >> posrep;

								while (posrep>Repartidores.size() || posrep<0){
									cout << "ERROOR.. posicion inexistente" << endl;
									cout << "Ingrese la posicion del repartidor que desea: ";
									cin >> posrep;
								}
								cout << "---JUGADORES--" << endl;
								for (int i = 0; i < Jugadores.size(); ++i)
								{
									cout << i << " " << Jugadores[i]->getNombre() << " " << Jugadores[i]->getEdad() << " " << Jugadores[i]->getDinero() << endl;
								}
								cout << "Ingrese la posicion del jugador que desea: ";
								cin >> posjug;

								Mesas[posmesa]->setNum(num);
								Mesas[posmesa]->setTipo(tipo); 
								Mesas[posmesa]->setRepartidor(Repartidores[posrep]);
								Mesas[posmesa]->setJugador(Jugadores[posjug]);

								cout << "MESA MODIFICADA CON EXITO!!" << endl << endl;

								//FIN MODIFICAR MESAS
						}else{
							//ELIMINAR MESAS
							cout << "---ELIMINAR MESAS---" << endl << endl;
							for (int i = 0; i < Mesas.size(); ++i)
							{
								cout << i << " " << Mesas[i]->getNum() << " " << Mesas[i]->getTipo() << " " << Mesas[i]->getRepartidor()->getNombre() << " " << Mesas[i]->getJugador()->getNombre() << endl;
							}

							cout << "Que posicion desea eliminar?: ";
							cin >> posmesa;
							Mesas.erase(posmesa+Mesas.begin());
						}
							
					}else{
						if (i==Administradores.size()-1)
							cout << "USUARIO INCORRECTO" << endl << endl;
					}//FIN IF, VALIDACION USUARIOS IGUALES
				}//FIN FOR.. LOGIN

			}//FIN CASO 5, LOGIN ADMINISTRADOR
		}//FIN SWITCH MENU GENERAL
		cout << "-----BIENVENIDO A BLACK JACK-----" << endl << endl;
		cout << "Ingrese la opción que desea: \n1.Crear Jugador\n2.Crear Administrador\n3.Crear Repartidor\n4.Login como jugador\n5.Login como Administrador:\n6.Salir ";
		cin >> opc;
	}//FIN WHILE, MENU GENERAL


}

bool SimuladorJuego(){
	string* valor = new string[13];
	bool ganador;
	string* palo = new string[4];
	string CartTemp, ValorTemp; //Guarda el string de la carta, para mostrarla.
	vector <string> baraja; //Guarda las cartas que ya se han repartido
	bool turnopc = true; //Valida si la pc puede tomar turno o no, dependiendo si gana o no el humano
	vector <string> player1;
	vector <string> player2;
	int contplayer1, contplayer2;
	char resp;

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

	contplayer2=0;
			contplayer1=0;
			ValorTemp = valor[rand()%12];
			CartTemp = ValorTemp + palo[rand()%3];
			player1.push_back(CartTemp);
			baraja.push_back(CartTemp);

			if (CartTemp == "A")
				contplayer1 = contplayer1+11;
			else if (ValorTemp == "J" || ValorTemp == "Q" || ValorTemp== "K")
				contplayer1 = contplayer1+10;
			 else
				contplayer1 = atoi(CartTemp.c_str());

			cout << "----Juego de Cliente" << "----" << endl;
			cout << "\n\nCarta: " << CartTemp << endl;
			cout << "Suman:" << contplayer1 << endl;

			do{
				ValorTemp = valor[rand()%12];
				CartTemp = ValorTemp + palo[rand()%3];

				for (int i = 0; i < baraja.size(); ++i)
				{
					if (CartTemp==baraja[i]){
						ValorTemp = valor[rand()%12];
						CartTemp = ValorTemp + palo[rand()%3];
						i=0;
					}
				}
				baraja.push_back(CartTemp);
				player1.push_back(CartTemp);

				if (ValorTemp == "A"){
					if (contplayer1+11>21)
						contplayer1= contplayer1+1;
					else
						contplayer1 = contplayer1+11;
					
				} else if ((ValorTemp == "J") || (ValorTemp == "Q") || (ValorTemp== "K"))
				contplayer1 = contplayer1+10;
				else
				contplayer1 = contplayer1+atoi(CartTemp.c_str());
				
				//Imprime el resumen de su juego
				cout << "\n\nCarta: " << CartTemp << endl;
				cout << "Suman:" << contplayer1 << endl;

				if (contplayer1==21){
					cout << " JUGADOR HAS SIDO EL GANADOR!!" << endl;
					ganador = true; // GANO JUGADOR
					resp = 'n'; 
					turnopc = false;
				}else if (contplayer1>21){
					cout << "EL REPARTIDOR HA GANADO!!" << endl;
					ganador = false;
					resp = 'n';
					turnopc = false;
				}else{
					cout << "Quieres pedir mas cartas?? [s/n] ";
					cin >> resp;
					turnopc = true;
				}
			}
			while (resp == 's' || resp == 'S');
			//TURNO PC

			if (turnopc==true){

				ValorTemp = valor[rand()%12];
				CartTemp = ValorTemp + palo[rand()%3];
				//VALIDACIÓN SI HAY CARTAS REPETIDAS
				for (int i = 0; i < baraja.size(); ++i)
				{
					if (CartTemp==baraja[i]){
						ValorTemp = valor[rand()%12];
						CartTemp = ValorTemp + palo[rand()%3];
						i=0;
					}
				}
				baraja.push_back(CartTemp);
				player2.push_back(CartTemp);

				if (ValorTemp == "A")
					contplayer2 = 11;
				else if ((ValorTemp == "J") || (ValorTemp == "Q") || (ValorTemp== "K"))
					contplayer2 = 10;
				else
					contplayer2 = atoi(CartTemp.c_str());

				cout << "----Juego de " << "Repartidor " << "----" << endl;
				cout << "\n\nCarta: " << CartTemp << endl;
				cout << "Suman: " << contplayer2 << endl;

			do{
				ValorTemp = valor[rand()%12];
				CartTemp = ValorTemp + palo[rand()%3];
				//VALIDACION CARTA REPETIDA
				for (int i = 0; i < baraja.size(); ++i)
				{
					if (CartTemp==baraja[i]){
						ValorTemp = valor[rand()%12];
						CartTemp = ValorTemp + palo[rand()%3];
						i=0;
					}
				}

				baraja.push_back(CartTemp);
				player2.push_back(CartTemp);

				if (ValorTemp == "A"){
					if (contplayer2+11>21)
						contplayer2= contplayer2+1;
					else
						contplayer2 = contplayer2+11;
					
				} else if ((ValorTemp == "J") || (ValorTemp == "Q") || (ValorTemp== "K"))
				contplayer2 = contplayer2+10;
				 else
				contplayer2 = contplayer2+atoi(CartTemp.c_str());
				
				//Imprime el resumen de su juego
				cout << "\n\nCarta: " << CartTemp << endl;
				cout << "Suman:" << contplayer2 << endl;

				if (contplayer2==21){
					cout << "EL REPARTIDOR HA GANADO!!" << endl;
					ganador = false;
					
				}else if (contplayer2>21){
					cout << " JUGADOR HAS SIDO EL GANADOR!!" << endl;
					ganador = true;

				}else{
					if (contplayer2==20 || contplayer2==19)//El repartidor abandona, porque sus oportunidades de ganar son mayores si no agarra mas cartas
						resp = 'E';		
				}
			}
			while (contplayer2<21 && resp != 'E');
		}
				
			
			if (turnopc==true && resp== 'E'){
				if(contplayer2>contplayer1){
					cout << "EL REPARTIDOR HA GANADO!!" << endl;
					ganador = false; //GANO REPARTIDOR

				}else if (contplayer2<contplayer1){
					cout << " JUGADOR HAS SIDO EL GANADOR!!" << endl;
					ganador = true; // GANO JUGADOR
				}else{
					cout << "EMPATE!!" << endl;
					ganador = false;
				}
			}

	
	




}