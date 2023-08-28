/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include "tarjeta.h"
#include <iostream>
#include <vector>

Tarjeta::Tarjeta(string t, Territorio* te, int e)
    : tipo(t), territorio(te), unidadesDeEjercito_tarjeta(e) {}

Tarjeta::Tarjeta(string t, int e)
    : tipo(t),unidadesDeEjercito_tarjeta(e) {}

string Tarjeta::getTipo() { return tipo; }

Territorio* Tarjeta::getTerritorio() { return territorio; }

int Tarjeta::getEjercito() { return unidadesDeEjercito_tarjeta; }

void Tarjeta::setUtilizada(bool v) { utilizada = v;}

bool Tarjeta::getUtilizada() {return utilizada;}
