/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/

#include "comando.h"
#include "tablero.h"
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#define REINICIAR_FORMATO "\033[0m"
#define TEXTO_VERDE "\033[32m"
#endif

using namespace std;

void PonerSimbolo(const string &textoSimbolo) {
#ifdef _WIN32
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleMode(hConsole, ENABLE_PROCESSED_OUTPUT | ENABLE_WRAP_AT_EOL_OUTPUT);
#else
  { cout << TEXTO_VERDE; }
#endif

  cout << textoSimbolo;

#ifndef _WIN32
  { cout << REINICIAR_FORMATO; }
#endif
}

int main() {
  string entradaUsuario;
  int numJugadores;
  bool inicializado = false;
  vector <Jugador> jugadores;
  Tablero tablero;
  PonerSimbolo("$ ");
  
  while (true) {
    getline(cin, entradaUsuario);

    PonerSimbolo("$ ");

    istringstream iss(entradaUsuario);
    string comando, argumento;

    if (iss >> comando) {
      if (comando == "salir") {
        cout << "Comando ingresado con exito." << endl;
        break;
      } else if (comando == "ayuda") {
        iss >> argumento;
        ayuda(argumento);
      } else if (comando == "inicializar") {
        if (iss >> argumento) {
          if (validarComandoInicializar(argumento)) {
            if (argumento.empty()) {
              
              } else {
              inicializarConArgumento(argumento);
            }
          } else {
            cout << "Error: Argumento de comando 'inicializar' invalido."
                 << endl;
          }
        } else {   
          if(!inicializado){
          jugadores = inicializarSinArgumento(numJugadores);
            cout<<"hola";
          tablero.inicializarJuego(numJugadores, jugadores);
          inicializado = true;
          
          }
          else {
            cout<<"Actualmente hay una partida en curso"<<endl;;
          }
         
        }
      } else if (comando == "guardar") {
        if (iss >> argumento && validarComandoGuardar(argumento)) {
          cout << "Comando 'guardar " << argumento << "' ingresado con exito."
               << endl;
        } else {
          cout << "Error: Comando invalido o argumento incorrecto." << endl;
              PonerSimbolo("$ ");

        }
      } else if (comando == "guardar_comprimido") {
        if (iss >> argumento && validarComandoGuardarComprimido(argumento)) {
          cout << "Comando 'guardar_comprimido " << argumento
               << "' ingresado con exito." << endl;
        } else {
          cout << "Error: Comando invalido o argumento incorrecto." << endl;
              PonerSimbolo("$ ");

        }
      } else if (comando == "turno") {
        if (iss >> argumento && validarComandoTurno(argumento)) {
          if(inicializado)
          {
            if(!tablero.asignarTurno(argumento))
            {
              cout<<"No es el turno del jugador "<<argumento<<endl;
              PonerSimbolo("$ ");
            }
            else{
              PonerSimbolo("$ ");
            }
            
          }
          else {
            cout<<"No hay ninguna partida inicializada"<<endl;;
          }
         
        } else {
          cout << "Error: Comando invalido o argumento incorrecto." << endl;
            PonerSimbolo("$ ");

        }
      } else if (comando == "costo_conquista") {
        if (iss >> argumento && validarComandoCostoConquista(argumento)) {
          cout << "Comando 'costo_conquista " << argumento
               << "' ingresado con exito." << endl;
        } else {
          cout << "Error: Comando invalido o argumento incorrecto." << endl;
          PonerSimbolo("$ ");

        }
      } else if (comando == "conquista_mas_barata") {
        cout << "Comando 'conquista_mas_barata ingresado con exito." << endl;
      } else {
        cout << "Error: Comando invalido" << endl;
      PonerSimbolo("$ ");

      }
    }
  }
  return 0;
}