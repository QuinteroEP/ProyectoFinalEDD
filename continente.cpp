/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include "continente.h"
#include <string>
#include <vector>

Continente::Continente(string n, std::string c)
    : nombre_continente(n), color_contienete(c) {}

string Continente::getNombre() { return nombre_continente; }

string Continente::getColor() { return color_contienete; }

vector<Territorio> Continente::getTerritoriosContinente() {
  return territorios_contiente;
}

void Continente::agregarTerritorios(Territorio t) {
  territorios_contiente.push_back(t);
}