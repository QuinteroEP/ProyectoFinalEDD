/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/


/*
#ifndef _JUEGO_
#define _JUEGO_

#include "jugador.h"
#include "tarjeta.h"
#include "continente.h"
#include <string>
#include <list>
#include <queue>

using namespace std;

struct Juego {
    int cantJugadores;
    list <Jugador> listJugadores;
    list <Jugador> :: iterator jugadorActual;
    queue <Tarjeta> cartas;
    int contIntercambio = 0;
    vector <vector <string>> multifronteras;
    list<string> territorios;
    list<Continente> multicontinente;
    string ganadorJuego;
    bool juegoIni = false;
    bool ganador = false;

  void llenarContinente(list<Continente> &multicontinente);

  void inicializarJuego(bool &juegoIni, list<string> &territorios, list<Continente> &multicontinente, queue<Tarjeta> &cartas);

  int getContIntercambio();
  void setContIntercambio(int nuevoCont);
  void setGanadorJuego(string ganJuego);
  void setGanador(bool ganador1);
  bool validarListaTerritorios(Jugador jugador, list<string> &territorios);
  bool validarTurno(string nombre);
  void siguienteJugador();
  void determinarGanador(Jugador jugador);
  void inicializarCartas(queue <Tarjeta> &cartas);
  void darCarta(queue <Tarjeta> &cartas, Jugador &jugador);
  bool asignarInfanteria(list <Jugador> &listJugadores, int cantJugadores);
  void recorrerJugadores(list <Jugador> &listJugadores, int cantidad);
  void inicializarTerritorio(list<string> &territorios);
  void inicializarFronteras(vector <vector <string>> &multifronteras);
};
    
#endif // _JUEGO_*/