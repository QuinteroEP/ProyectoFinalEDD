/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include "territorio.h"
#include <string>
#include <vector>

Territorio::Territorio(string n, string c)
    : nombre_territorio(n), color_territorio(c) {}

string Territorio::getNombre() { return nombre_territorio; }

string Territorio::getPropietario() { return propietario_territorio; }

void Territorio:: setPropietario(string idJug){
  propietario_territorio = idJug;
}
void Territorio::establecerPropietario(string prop) {
  propietario_territorio = prop;
}

bool Territorio::verificarExistenciaPropietario() {
  if (propietario_territorio.empty()) {
    return false;
  } else {
    return true;
  }
}

void Territorio::agregarTerritorioAlrededor(Territorio *ter) {
  territorios_alrededor.push_back(ter);
}

vector<Territorio *> Territorio::getTerritorioAlrededor() {
  return territorios_alrededor;
}

int Territorio::getUnidadesDeEjercito_territorio() {
  return unidaesDeEjercito_territorio;
}

void Territorio::setUnidadesDeEjercito_territorio(int cantidad_unidades) {
  unidaesDeEjercito_territorio = cantidad_unidades;
}
void Territorio::agregarUnidadesTerritorioAdicional(int cantidad_adicional)
{
  unidaesDeEjercito_territorio += cantidad_adicional;
}
void Territorio::eliminarUnidadesTerritorio()
{
  unidaesDeEjercito_territorio -=1;
}
