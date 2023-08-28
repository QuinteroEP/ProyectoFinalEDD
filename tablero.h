using namespace std;
#include "continente.h"
#include "jugador.h"
#include "tarjeta.h"
#include <list>
#include <string>
#ifndef TABLERO_H
#define TABLERO_H

class Tablero {
private:
  list<Continente> continentes_tablero;
  vector<Jugador> jugadores_tablero;
  vector<Tarjeta> tarjetas_tablero;
  vector<Jugador>::iterator iterador_jugadores;
  Jugador jugador_en_turno;

public:
  Tablero();
  void inicializarJuego(int cantJug, vector<Jugador> jugadores);
  void inicializarContientes();
  void inicializarJugadores(vector<Jugador>jugadores) ;
  void inicializarTarjetas();
  void agregarContinentes();
  int tirarDados();
  int calcularCantUnidadesNuevas(string idJug);
  int calcularCantUnidadesCartas(Jugador* jugAuxs);
  void setJugadorEnTurno(Jugador j);
  Jugador getJugadorEnTurno();
  bool asignarTurno (string idJug);
  void faseDraft(string idJug);
  void faseAtacar(string idJug);
  void faseFortalecer(string idJug);
  void asignarNuevasTropas ();
};

#endif