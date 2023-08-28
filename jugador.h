/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include <list>
#include "tarjeta.h"
#include <string>
#ifndef JUGADOR_H
#define JUGADOR_H

class Jugador {
private:
  string nombre_jugador;
  string id_jugador;
  string color_jugador;
  int unidadesDeEjercito_jugador;
  vector<Tarjeta*> tarjetas_jugador;
  vector<Territorio*> territorios_jugador; 
public:
  Jugador(string n, string c, string id);
  string getNombre();
  string getColor();
  string getId();
  void setId (string id);
  int getUnidadesDeEjercito();
  void setUnidadesDeEjercito(int u);
  void agregarUnidadesEnTerritorio();
  void agregarTarjeta (Tarjeta* t);
  vector<Tarjeta*> getTarjetas ();
  vector<string> calcularCombinacionesTarjetas();
  void agregarTerritorio(Territorio* t);
  vector<Territorio*> getTerritorios_jugador();
  void agregarUnidadesAdicionales(int cant_adicional);
  void eliminarUnidadesEjercito();
};

#endif