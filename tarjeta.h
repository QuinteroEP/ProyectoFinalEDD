/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#ifndef TARJETA_H
#define TARJETA_H
#include "territorio.h"
#include <string>
#include <list>

class Tarjeta {
  private:
  string tipo;
  Territorio* territorio;
  int unidadesDeEjercito_tarjeta;
  bool utilizada;
  public:
  Tarjeta(string t, Territorio* te, int e);
  Tarjeta(string t, int e);
  string getTipo();
  Territorio* getTerritorio();
  int getEjercito();
  void setUtilizada(bool v);
  bool getUtilizada();

};

#endif