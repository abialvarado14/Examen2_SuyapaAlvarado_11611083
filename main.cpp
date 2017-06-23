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

int main(){
	vector <Mesa*> Mesas;
	vector <Repartidor*> Repartidores;
	vector <Administrador*> Administradores;
	vector <Jugador*> Jugadores;
	int opc, rangopc, difopc, opc2, num, tipopc, posjug, posrep, posmesa;
	string lugar, apodo, nombre, ID, rango, dificultad, tipo;
	int edad, year;
	double dineroj, sueldo;
	

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
					dificultad = "GerenteTiempoCompleto";
				else if (difopc==2)
					dificultad = "GerenteMedioTiempo";
				else
					dificultad = "GerenteGeneral";


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
						cout << "---BIENVENIDO AL JUEGO BLACKJACK!!" << endl << endl;
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

						}//FIN MODIFICAR MESAS..
							
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