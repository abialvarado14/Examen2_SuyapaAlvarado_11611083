main: Administrador.o Persona.o Mesa.o Repartidor.o Jugador.o Cartas.o Baraja.o main.o
	g++ Administrador.o Persona.o Mesa.o Repartidor.o Jugador.o Cartas.o main.o Baraja.o -o main

main.o: main.cpp Administrador.h Persona.h Mesa.h Repartidor.h Jugador.h Cartas.h Baraja.h
	g++ -c main.cpp

Administrador.o:		Administrador.h Administrador.cpp Persona.h
	g++ -c Administrador.cpp

Jugador.o:	Jugador.h Jugador.cpp Persona.h
	g++ -c Jugador.cpp

Repartidor.o:	Repartidor.h Repartidor.cpp Persona.h
	g++ -c Repartidor.cpp

Persona.o:		Persona.h Persona.cpp 
	g++ -c Persona.cpp

Cartas.o:	Cartas.h Cartas.cpp
	g++ -c Cartas.cpp

Mesa.o:	Mesa.h Mesa.cpp 
	g++ -c Mesa.cpp

Baraja.o:	Baraja.h Baraja.cpp 
	g++ -c Baraja.cpp














