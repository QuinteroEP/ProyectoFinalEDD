/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/

using namespace std;
#include "jugador.h"
#include <iostream>
#include <string>
#include <vector>

Jugador::Jugador(string n, string c, string id)
    : nombre_jugador(n), color_jugador(c), id_jugador(id) {}

string Jugador::getNombre() { return nombre_jugador; }

string Jugador::getColor() { return color_jugador; }

string Jugador::getId() { return id_jugador; }

void Jugador::setId (string id){
  id_jugador = id;
}

int Jugador::getUnidadesDeEjercito() { return unidadesDeEjercito_jugador; }

void Jugador::setUnidadesDeEjercito(int u) { unidadesDeEjercito_jugador = u; }

void Jugador::agregarTarjeta(Tarjeta *t) { tarjetas_jugador.push_back(t); }

vector<Tarjeta *> Jugador::getTarjetas() { return tarjetas_jugador; }

vector<string> Jugador::calcularCombinacionesTarjetas() {}

void Jugador::agregarTerritorio(Territorio *t) {
  territorios_jugador.push_back(t);
}

vector<Territorio *> Jugador::getTerritorios_jugador() {
  return territorios_jugador;
}
void Jugador::agregarUnidadesAdicionales(int cant_adicional)
{
  unidadesDeEjercito_jugador +=cant_adicional;
}
void Jugador::eliminarUnidadesEjercito()
{
    unidadesDeEjercito_jugador -=1;
}


