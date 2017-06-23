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
	int opc, rangopc, difopc;
	string lugar, apodo, nombre, ID, rango, dificultad;
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
						cout << "---BIENVENIDO A BLACKJACK!!";
					}else{
						if (i==Jugadores.size()-1)
							cout << "USUARIO INCORRECTO";
					}//FIN IF, VALIDACION USUARIOS IGUALES
					
				}//FIN FOR, LOGIN..
				break;
			}//FIN CASO 4, LOGIN JUGADOR
		}//FIN SWITCH MENU GENERAL
		cout << "-----BIENVENIDO A BLACK JACK-----" << endl << endl;
		cout << "Ingrese la opción que desea: \n1.Crear Jugador\n2.Crear Administrador\n3.Crear Repartidor\n4.Login como jugador\n5.Login como Administrador:\n6.Salir ";
		cin >> opc;
	}//FIN WHILE, MENU GENERAL








}