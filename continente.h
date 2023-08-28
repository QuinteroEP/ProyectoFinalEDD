/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include "territorio.h"
#include <string>
#include <vector>
#ifndef CONTINENTE_H
#define CONTINENTE_H

class Continente {
private:
  string nombre_continente;
  string color_contienete;
  vector<Territorio> territorios_contiente;

public:
  Continente(string n, string c);
  string getNombre();
  string getColor();
  vector<Territorio> getTerritoriosContinente();
  void agregarTerritorios(Territorio t);
};
#endif