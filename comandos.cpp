/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
#include "comando.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<Comando> comandos = {
    {"inicializar", "Este comando se utiliza para comenzar una nueva partida del juego Risk. Solicita la cantidad de jugadores y sus nombres, y luego les permite ubicar sus unidades de ejército en los territorios de manera consecutiva.\nPara conocer información sobre inicializar desde un archivo ingresa {ayuda inicializar_a}"},
    {"turno", "Este comando permite al jugador con el ID especificado realizar su turno. Durante su turno, el jugador puede obtener unidades adicionales, atacar territorios enemigos y fortificar sus posiciones.\n  -Entrada: turno <id_jugador> \n  -Ejemplo: turno 2"},
    {"salir", " Este comando se utiliza para terminar la ejecución del juego y salir de la aplicación."},
    {"guardar", "Guarda el estado actual del juego en un archivo de texto con el nombre especificado. El archivo contendrá información sobre los jugadores, territorios, cartas y otros detalles del juego.\n  -Entrada: guardar <nombre_archivo> \n  -Ejemplo: guardar partida1.txt"},
    {"guardar_comprimido",
     "Guarda el estado actual del juego en un archivo binario comprimido.\n  -Entrada: guardar_comprimido <nombre_archivo> \n  -Ejemplo: guardar_comprimido partida1.bin"},
    {"inicializar_a", "Inicializa el juego con los datos contenidos en el archivo especificado. Puede ser un archivo generado por el comando guardar o un archivo binario generado por el comando guardar_comprimido\n  -Entrada: inicializar <nombre_archivo> \n  -Ejemplo: inicializar partida_guardada.txt"},
    {"costo_conquista",
     "Calcula el costo y la secuencia de territorios a ser conquistados para controlar el territorio dado. El programa determinará el territorio desde el cual el jugador tiene el control más cercano al territorio objetivo.\n  -Entrada: costo_conquista <territorio> \n  -Ejemplo: costo_conquista Brasil"},
    {"conquista_mas_barata",
     "Calcula el territorio que puede ser conquistado con el menor número de unidades de ejército perdidas. Se evalúan todas las posibles conquistas y se selecciona la que implica un menor riesgo."},
    {"ayuda", "Muestra informacion general o especifica sobre los comandos."},
};

void ayuda(string comando_especifico) {
  if (!comando_especifico.empty()) {
    for (Comando com : comandos) {
      if (com.nombre == comando_especifico) {
        cout << " " << com.nombre << ": " << com.descripcion << endl;
        return;
      }
    }
    cout << "No es un comando valido para brindar ayuda" << endl;
  } else {
    cout << "Listado de comandos" << endl;
    for (Comando com : comandos) {
      cout << "$ " << com.nombre << ": " << com.descripcion << endl;
    }
  }
}

bool validarComandoInicializar(string argumento) {
  return argumento.empty() || argumento.size() > 0;
}

bool validarComandoGuardar(string argumento) {
  return !argumento.empty();
}

bool validarComandoTurno(string argumento) {
  
  return !argumento.empty();
}

bool validarComandoGuardarComprimido(string argumento) {
  return !argumento.empty();
}

bool validarComandoCostoConquista(string argumento) {
  return !argumento.empty();
}

vector<Jugador> inicializarSinArgumento(int &numjug) {
  int numJugadores;
  vector<Jugador> jugadores;
  bool argumento_correcto = false;

  do {
    cout << "Ingrese la cantidad de jugadores: ";

    if (cin >> numJugadores) {
      if (numJugadores >= 3 && numJugadores <= 6) {
        for (int i = 0; i < numJugadores; i++) {
          string nombre, color;
          cout << "Ingrese el nombre del Jugador " << i + 1 << ": ";
          cin >> nombre;
          cout << "Ingrese el color del Jugador " << i + 1 << ": ";
          cin >> color;
          Jugador x(nombre, color, to_string(i));
          jugadores.push_back(x);
        }
        argumento_correcto = true;
      } else {
        cout << "Número de jugadores insuficiente o incorrecto" << endl;
      }
    } else {
      cout << "Entrada inválida. Por favor, ingrese un número válido." << endl;
      cin.clear();               // Limpiar el estado de error
      cin.ignore(10000, '\n');   // Descartar el contenido inválido del búfer
    }

  } while (!argumento_correcto);

  numjug = numJugadores;
  return jugadores;
}


void inicializarConArgumento(const string &argumento) {
  cout << "Comando 'inicializar " << argumento << "' ingresado con exito." << endl;
}