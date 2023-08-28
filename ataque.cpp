/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/



/*#include "ataque.h"
#include "juego.h"
#include "jugador.h"
#include "territorio.h"
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

Jugador jugador;
Juego juego;

void Ataque::buscarTerritorio() {
  list<string>::iterator it;
  do {
    cout << "Ingrese el territorio del que desea atacar: " << endl;
    cin >> territorioAtacante;
    for (it = jugador.listaTerritorios.begin();
         it != jugador.listaTerritorios.end(); it++) {
      if (*it == territorioAtacante) {
        jugadorAtacante = *it;
      }
    }
    if (jugadorAtacante.empty()) {
      cout << "No se ha encontrado el territorio, ingréselo nuevamente" << endl;
    }
  } while (jugadorAtacante.empty());

  do {
    cout << "Ingrese el territorio que desea atacar: " << endl;
    cin >> territorioDefensor;
    vector<vector<string>>::iterator iti;
    vector<string>::iterator itj;
    for (iti = juego.multifronteras.begin();
         iti != juego.multifronteras.end(); iti++) {
      if (*iti == territorioAtacante) {
        for (itj = iti->begin(); itj != iti->end(); itj++) {
          if (*itj == territorioDefensor) {
            jugadorDefensor = *itj;
          }
        }

        if (jugadorDefensor.empty()) {
          cout << "El territorio no es fronterizo al territorio atacante, "
                  "digite un nuevo territorio"
               << endl;
        }
      }
    }
  } while (jugadorDefensor.empty());
}

void Ataque::lanzarDado() {

  srand(time(NULL));
  int resultado, cantAtacante, cantDefensor;

  cout << "Atacante: Digite la cantidad de dados que desea lanzar (2 o 3): "
       << endl;
  cin >> cantAtacante;

  for (int i = 0; i < cantAtacante; i++) {
    resultado = 1 + rand() % 6;
    cout << "Dado " << i + 1 << ": " << resultado << endl;
    dadoAtacante.push_back(resultado);
  }

  cout << "Defensor: Digite la cantidad de dados que desea lanzar (1 o 2): "
       << endl;
  cin >> cantDefensor;

  for (int i = 0; i < cantDefensor; i++) {
    resultado = 1 + rand() % 6;
    cout << "Dado " << i + 1 << ": " << resultado << endl;
    dadoDefensor.push_back(resultado);
  }
}

void Ataque::ordenarLanzamiento() {

  sort(dadoAtacante.begin(), dadoAtacante.end());
  sort(dadoDefensor.begin(), dadoAtacante.end());
}

void Ataque::compararResultado() {

  bool resultado = false;

  if (dadoAtacante[0] > dadoDefensor[0]) {

    resultado =
        jugador.eliminarTerritorioDefensor(list<Territorio> &listaTerritorios);

  } else if (dadoAtacante[0] == dadoDefensor[0]) {

    jugador.eliminarEjercitoAtacante(list<Territorio> &listaTerritorios);

  } else if (dadoAtacante[0] < dadoDefensor[0]) {

    jugador.eliminarEjercitoAtacante(list<Territorio> &listaTerritorios);
  }

  if (cantDefensor == 2) {
    if (dadoAtacante[1] > dadoDefensor[1]) {

      resultado = jugador.eliminarTerritorioDefensor(list<Territorio> &
                                                     listaTerritorios)

    } else if (dadoAtacante[1] == dadoDefensor[1]) {

      jugador.eliminarEjercitoAtacante(list<Territorio>& listaTerritorios);

    } else if (dadoAtacante[1] < dadoDefensor[1]) {

      jugador.eliminarEjercitoAtacante(list<Territorio> & listaTerritorios);
    }
  }

  if (resultado == true) {
    jugador.asignarNuevoTerritorio(territorioDefensor);
  }
}

// Getters y Setters

string Ataque::getTerritorioAtacante() { return territorioAtacante; }

void Ataque::setTerritorioAtacante (string nTerritorioAtacante) {
  territorioAtacante = nTerritorioAtacante;
}

string Ataque::getTerritorioDefensor() { return territorioDefensor; }

void Ataque::setTerritorioDefensor(string nTerritorioDefensor) {
  territorioDefensor = nTerritorioDefensor;
}

string Ataque::getJugadorAtacante(){ return jugadorAtacante; }

void Ataque::setJugadorAtacante(string nJugadorAtacante) {
  jugadorAtacante = nJugadorAtacante;
}

string Ataque::getTerritorioLibre() { return territorioLibre; }

void Ataque::setTerritorioLibre(string nTerritorioLibre) {
  territorioLibre = nTerritorioLibre;
}

string Ataque::getJugadorDefensor() { return jugadorDefensor; }

void Ataque::setJugadorDefensor(string nJugadorDefensor) {
  jugadorDefensor = nJugadorDefensor;
}

vector<int> Ataque::getDadoAtacante() { return dadoAtacante; }

void Ataque::setDadoAtacante(vector<int> nDadoAtacante) {
  dadoAtacante = nDadoAtacante;
}

vector<int> Ataque::getDadoDefensor() { return dadoDefensor; }

void Ataque::setDadoDefensor(vector<int> nDadoDefensor) {
  dadoDefensor = nDadoDefensor;
}*/