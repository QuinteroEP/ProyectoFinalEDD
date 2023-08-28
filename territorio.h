/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include <string>
#include <vector>
#ifndef TERRITORIO_H
#define TERRITORIO_H

class Territorio {
private:
  string nombre_territorio;
  string color_territorio;
  string propietario_territorio;
  vector<Territorio *> territorios_alrededor;
  int unidaesDeEjercito_territorio;

public:
  Territorio(string n, string c);
  string getNombre();
  string getPropietario();
  void setPropietario(string idJug);
  void establecerPropietario(string prop);
  bool verificarExistenciaPropietario();
  void agregarTerritorioAlrededor(Territorio *ter);
  vector<Territorio *> getTerritorioAlrededor();
  int getUnidadesDeEjercito_territorio();
  void setUnidadesDeEjercito_territorio(int cantidad_unidades);
  void eliminarUnidadesTerritorio();
  void agregarUnidadesTerritorioAdicional(int cantidad_adicional);
};

#endif