/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
using namespace std;
#include <string>
#include <vector>
#include "jugador.h"
#ifndef COMANDOS_H
#define COMANDOS_H

struct Comando {
  string nombre;
  string descripcion;
};

extern const std::vector<Comando> comandos;

void ayuda(string comando_especifico ="");

bool validarComandoInicializar(string argumento);

bool validarComandoGuardar(string argumento);

bool validarComandoTurno(string argumento);

bool validarComandoGuardarComprimido(string argumento);

bool validarComandoCostoConquista(string argumento);

vector <Jugador> inicializarSinArgumento(int& numjug);

void inicializarConArgumento(const string &argumento);

#endif