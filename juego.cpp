/*
	Estructura de Datos - Proyecto de clase
	Jair Santiago Vargas Saenz - Juan Pablo Hernandez Ceballos - Pablo Enrique Quintero
	Universidad Javeriana - Tercer periodo 2023
*/
/*
#include "juego.h"
#include "continente.h"
#include "jugador.h"
#include "tarjeta.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

void Juego::inicializarJuego() {
  solicitarDatosJugadores();
  llenarContinente();
  inicializarTerritorio();
  inicializarFronteras();
  asignarInfanteria();
  inicializarCartas();
  jugadorActual = listaJugadores.begin();

  /*cout << "Lista de jugadores y su infantería inicial:" << endl;
  for (Jugador &jugador : listaJugadores) {
    cout << "Jugador: " << jugador.getNombre()
         << ", Infantería Inicial: " << jugador.getInfanteriaInicial() << endl;
  }
}

void Juego::llenarContinente() {
  Continente americaNor;
  americaNor.setNombreContinente("America del Norte");
  americaNor.agregarTerritorio("Alaska");
  americaNor.agregarTerritorio("Alberta");
  americaNor.agregarTerritorio("América Central");
  americaNor.agregarTerritorio("Estados Unidos Orientales");
  americaNor.agregarTerritorio("Groenlandia");
  americaNor.agregarTerritorio("Territorio Noroccidental");
  americaNor.agregarTerritorio("Ontario");
  americaNor.agregarTerritorio("Quebec");
  americaNor.agregarTerritorio("Estados Unidos Occidentales");
  multicontinente.push_back(americaNor);

  Continente americaSur;
  americaSur.setNombreContinente("América del Sur");
  americaSur.agregarTerritorio("Argentina");
  americaSur.agregarTerritorio("Brasil");
  americaSur.agregarTerritorio("Perú");
  americaSur.agregarTerritorio("Venezuela");
  multicontinente.push_back(americaSur);

  Continente europa;
  europa.setNombreContinente("Europa");
  europa.agregarTerritorio("Gran Bretaña");
  europa.agregarTerritorio("Islandia");
  europa.agregarTerritorio("Europa del Norte");
  europa.agregarTerritorio("Escandinavia");
  europa.agregarTerritorio("Europa del Sur");
  europa.agregarTerritorio("Ucrania");
  europa.agregarTerritorio("Europa Occidental");
  multicontinente.push_back(europa);

  Continente africa;
  africa.setNombreContinente("África");
  africa.agregarTerritorio("Congo");
  africa.agregarTerritorio("África Oriental");
  africa.agregarTerritorio("Egipto");
  africa.agregarTerritorio("Madagascar");
  africa.agregarTerritorio("África del Norte");
  africa.agregarTerritorio("África del sur");
  multicontinente.push_back(africa);

  Continente asia;
  asia.setNombreContinente("Asia");
  asia.agregarTerritorio("Afghanistán");
  asia.agregarTerritorio("China");
  asia.agregarTerritorio("India");
  asia.agregarTerritorio("Irkutsk");
  asia.agregarTerritorio("Japón");
  asia.agregarTerritorio("Kamchatka");
  asia.agregarTerritorio("Medio Oriente");
  asia.agregarTerritorio("Mongolia");
  asia.agregarTerritorio("Siam");
  asia.agregarTerritorio("Siberia");
  asia.agregarTerritorio("Ural");
  asia.agregarTerritorio("Yakutsk");
  multicontinente.push_back(asia);

  Continente australia;
  australia.setNombreContinente("Australia");
  australia.agregarTerritorio("Australia Oriental");
  australia.agregarTerritorio("Indonesia");
  australia.agregarTerritorio("Nueva Guinea");
  australia.agregarTerritorio("Australia Occidental");
  multicontinente.push_back(australia);
}

void Juego::inicializarTerritorio() {
  territorios.push_back("Alaska");
  territorios.push_back("Alberta");
  territorios.push_back("América Central");
  territorios.push_back("Estados Unidos Orientales");
  territorios.push_back("Groenlandia");
  territorios.push_back("Territorio Noroccidental");
  territorios.push_back("Ontario");
  territorios.push_back("Quebec");
  territorios.push_back("Estados Unidos Occidentales");
  territorios.push_back("Argentina");
  territorios.push_back("Brasil");
  territorios.push_back("Perú");
  territorios.push_back("Venezuela");
  territorios.push_back("Gran Bretaña");
  territorios.push_back("Islandia");
  territorios.push_back("Europa del Norte");
  territorios.push_back("Escandinavia");
  territorios.push_back("Europa del Sur");
  territorios.push_back("Ucrania");
  territorios.push_back("Europa Occidental");
  territorios.push_back("Congo");
  territorios.push_back("África Oriental");
  territorios.push_back("Egipto");
  territorios.push_back("Madagascar");
  territorios.push_back("África del Norte");
  territorios.push_back("África del sur");
  territorios.push_back("Afghanistán");
  territorios.push_back("China");
  territorios.push_back("India");
  territorios.push_back("Irkutsk");
  territorios.push_back("Japón");
  territorios.push_back("Kamchatka");
  territorios.push_back("Medio Oriente");
  territorios.push_back("Mongolia");
  territorios.push_back("Siam");
  territorios.push_back("Siberia");
  territorios.push_back("Ural");
  territorios.push_back("Yakutsk");
  territorios.push_back("Australia Oriental");
  territorios.push_back("Indonesia");
  territorios.push_back("Nueva Guinea");
  territorios.push_back("Australia Occidental");
}

void Juego::solicitarDatosJugadores() {
  int cant;
  do {
    cout << "Ingrese la cantidad de jugadores: ";
    cin >> cant;
    if (cant <= 2 || cant >= 7) {
      cout << "Cantidad de jugadores inavlida\n";
    }
  } while (cant <= 2 || cant >= 7);
  setCantJugadores(cant);
  cout << endl;
  for (int i = 0; i < cant; ++i) {
    string nombre;
    cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
    cin >> nombre;
    Jugador jugador(nombre);
    listaJugadores.push_back(jugador);
  }
}

void Juego::inicializarFronteras() {
  multifronteras.push_back(
      {"Alaska", "Alberta", "Territorio Noroccidental", "Kamchatka"});
  multifronteras.push_back({"Alberta", "Alaska", "Territorio Noroccidental",
                            "Ontario", "Estados Unidos Occidentales"});
  multifronteras.push_back({"América Central", "Estados Unidos Orientales",
                            "Estados Unidos Occidentales", "Venezuela"});
  multifronteras.push_back({"Estados Unidos Orientales", "Ontario", "Quebec",
                            "Estados Unidos Occidentales"});
  multifronteras.push_back({"Groenlandia", "Territorio Noroccidental",
                            "Ontario", "Quebec", "Islandia"});
  multifronteras.push_back({"Territorio Noroccidental", "Alaska", "Alberta",
                            "Groenlandia", "Ontario"});
  multifronteras.push_back({"Ontario", "Alberta", "Estados Unidos Orientales",
                            "Groenlandia", "Territorio Noroccidental", "Quebec",
                            "Estados Unidos Occidentales"});
  multifronteras.push_back(
      {"Quebec", "Estados Unidos Orientales", "Groenlandia", "Ontario"});
  multifronteras.push_back({"Estados Unidos Occidentales", "Alberta",
                            "America Central", "Estados Unidos Orientales",
                            "Ontario"});

  multifronteras.push_back({"Argentina", "Brasil", "Perú"});
  multifronteras.push_back(
      {"Brasil", "Argentina", "Perú", "Venezuela", "África del Norte"});
  multifronteras.push_back({"Perú", "Argentina", "Brasil", "Venezuela"});
  multifronteras.push_back({"Venezuela", "Brasil", "Perú", "América Central"});

  multifronteras.push_back({"Gran Bretaña", "Islandia", "Europa del Norte",
                            "Escandinavia", "Europa Occidental"});
  multifronteras.push_back(
      {"Islandia", "Gran Bretaña", "Escandinavia", "Groenlandia"});
  multifronteras.push_back({"Europa del Norte", "Gran Bretaña", "Escandinavia",
                            "Europa del Sur", "Ucrania", "Europa Occidental"});
  multifronteras.push_back({"Escandinavia", "Gran Bretaña", "Islandia",
                            "Europa del Norte", "Ucrania"});
  multifronteras.push_back({"Europa del Sur", "Europa del Norte", "Ucrania",
                            "Europa Occidental", "Egipto", "África del Norte",
                            "Medio Oriente"});
  multifronteras.push_back({"Ucrania", "Europa del Norte", "Escandinavia",
                            "Europa del Sur", "Afghanistán", "Medio Oriente",
                            "Ural"});
  multifronteras.push_back({"Europa Occidental", "Gran Bretaña",
                            "Europa del Norte", "Europa del Sur",
                            "África del Norte"});

  multifronteras.push_back(
      {"Congo", "África del sur", "Áfria Oriental", "África del Norte"});
  multifronteras.push_back({"África Oriental", "Egipto", "Madagascar",
                            "África del Norte", "África del sur", "Congo"});
  multifronteras.push_back({"Egipto", "Áfria Oriental", "África del Norte",
                            "Medio Oriente", "Europa del Sur"});
  multifronteras.push_back({"Madagascar", "África del sur", "Áfria Oriental"});
  multifronteras.push_back({"África del Norte", "Congo", "Áfria Oriental",
                            "Egipto", "Brasil", "Europa del Sur",
                            "Europa Occidental"});
  multifronteras.push_back(
      {"África del sur", "Congo", "Madagascar", "Áfria Oriental"});

  multifronteras.push_back(
      {"Afghanistán", "Medio Oriente", "India", "China", "Ural", "Ucrania"});
  multifronteras.push_back(
      {"China", "Siam", "India", "Afghanistán", "Ural", "Siberia", "Mongolia"});
  multifronteras.push_back(
      {"India", "Medio Oriente", "Afghanistán", "China", "Siam"});
  multifronteras.push_back(
      {"Irkutsk", "Mongolia", "Siberia", "Yakutsk", "Kamchatka"});
  multifronteras.push_back({"Japón", "Mongolia", "Kamchatka"});
  multifronteras.push_back(
      {"Kamchatka", "Irkutsk", "Yakutsk", "Mongolia", "Japón", "Alaska"});
  multifronteras.push_back({"Medio Oriente", "Europa del Sur", "Ucrania",
                            "Afghanistán", "India", "Egipto"});
  multifronteras.push_back(
      {"Mongolia", "China", "Siberia", "Irkutsk", "Kamchatka"});
  multifronteras.push_back({"Siam", "India", "China", "Indonesia"});
  multifronteras.push_back(
      {"Siberia", "Ural", "Yakutsk", "Irkutsk", "Mongolia", "China"});
  multifronteras.push_back(
      {"Ural", "Afghanistán", "Ucrania", "Siberia", "China"});
  multifronteras.push_back({"Yakutsk", "Siberia", "Irkutsk", "Kamchatka"});

  multifronteras.push_back(
      {"Australia Oriental", "Nueva Guinea", "Australia Occidental"});
  multifronteras.push_back(
      {"Indonesia", "Nueva Guinea", "Australia Occidental", "Siam"});
  multifronteras.push_back({"Nueva Guinea", "Australia Oriental", "Indonesia",
                            "Australia Occidental"});
  multifronteras.push_back({"Australia Occidental",
                            "Australia Oriental, Indonesia", "Nueva Guinea"});
}

bool Juego::asignarInfanteria() {
  bool cantidad = false;
  int cantInfa = 0;

  if (getCantJugadores() == 3) {
    cantInfa = 35;
    recorrerJugadores(listaJugadores, cantInfa);
    cantidad = true;
  } else if (getCantJugadores() == 4) {
    cantInfa = 30;
    recorrerJugadores(listaJugadores, cantInfa);
    cantidad = true;
  } else if (getCantJugadores() == 5) {
    cantInfa = 25;
    recorrerJugadores(listaJugadores, cantInfa);
    cantidad = true;
  } else if (getCantJugadores() == 6) {
    cantInfa = 20;
    recorrerJugadores(listaJugadores, cantInfa);
    cantidad = true;
  } else {
    cout << "Cantidad de jugadores no es apta, vuelva a intentar\n\n";
  }
  return cantidad;
}


void Juego::recorrerJugadores(list<Jugador> &listaJugadores, int cantidad) {
  for (Jugador &jugador : listaJugadores) {
    jugador.setInfanteriaInicial(cantidad);
  }
}

void Juego::inicializarCartas() {
  vector<Tarjeta> tarjetasVec;
  tarjetasVec.push_back(Tarjeta(1, "Alaska", 1));
  tarjetasVec.push_back(Tarjeta(1, "Alberta", 2));
  tarjetasVec.push_back(Tarjeta(1, "América Central", 3));
  tarjetasVec.push_back(Tarjeta(1, "Estados Unidos Orientales", 3));
  tarjetasVec.push_back(Tarjeta(1, "Groenlandia", 1));
  tarjetasVec.push_back(Tarjeta(1, "Territorio Noroccidental", 3));
  tarjetasVec.push_back(Tarjeta(1, "Ontario", 2));
  tarjetasVec.push_back(Tarjeta(1, "Quebec", 2));
  tarjetasVec.push_back(Tarjeta(1, "Estados Unidos Occidentales", 3));
  tarjetasVec.push_back(Tarjeta(1, "Argentina", 1));
  tarjetasVec.push_back(Tarjeta(1, "Brasil", 3));
  tarjetasVec.push_back(Tarjeta(1, "Perú", 1));
  tarjetasVec.push_back(Tarjeta(1, "Venezuela", 1));
  tarjetasVec.push_back(Tarjeta(1, "Gran Bretaña", 3));
  tarjetasVec.push_back(Tarjeta(1, "Islandia", 1));
  tarjetasVec.push_back(Tarjeta(1, "Europa del Norte", 3));
  tarjetasVec.push_back(Tarjeta(1, "Escandinavia", 2));
  tarjetasVec.push_back(Tarjeta(1, "Europa del Sur", 3));
  tarjetasVec.push_back(Tarjeta(1, "Ucrania", 2));
  tarjetasVec.push_back(Tarjeta(1, "Europa Occidental", 3));
  tarjetasVec.push_back(Tarjeta(1, "Congo", 1));
  tarjetasVec.push_back(Tarjeta(1, "África Oriental", 1));
  tarjetasVec.push_back(Tarjeta(1, "Egipto", 1));
  tarjetasVec.push_back(Tarjeta(1, "Madagascar", 2));
  tarjetasVec.push_back(Tarjeta(1, "África del Norte", 2));
  tarjetasVec.push_back(Tarjeta(1, "África del Sur", 3));
  tarjetasVec.push_back(Tarjeta(1, "Afghanistán", 2));
  tarjetasVec.push_back(Tarjeta(1, "China", 1));
  tarjetasVec.push_back(Tarjeta(1, "India", 2));
  tarjetasVec.push_back(Tarjeta(1, "Irkutsk", 2));
  tarjetasVec.push_back(Tarjeta(1, "Japón", 3));
  tarjetasVec.push_back(Tarjeta(1, "Kamchatka", 1));
  tarjetasVec.push_back(Tarjeta(1, "Medio Oriente", 1));
  tarjetasVec.push_back(Tarjeta(1, "Mongolia", 1));
  tarjetasVec.push_back(Tarjeta(1, "Siam", 1));
  tarjetasVec.push_back(Tarjeta(1, "Siberia", 2));
  tarjetasVec.push_back(Tarjeta(1, "Ural", 2));
  tarjetasVec.push_back(Tarjeta(1, "Yakutsk", 2));
  tarjetasVec.push_back(Tarjeta(1, "Australia Oriental", 2));
  tarjetasVec.push_back(Tarjeta(1, "Indonesia", 3));
  tarjetasVec.push_back(Tarjeta(1, "Nueva Guinea", 1));
  tarjetasVec.push_back(Tarjeta(1, "Australia Occidental", 3));
  tarjetasVec.push_back(Tarjeta(2, "Comodín1"));
  tarjetasVec.push_back(Tarjeta(2, "Comodín2"));

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  default_random_engine rng(seed);
  shuffle(tarjetasVec.begin(), tarjetasVec.end(), rng);

  for (const Tarjeta &tarjeta : tarjetasVec) {
    cartas.push(tarjeta);
  }
}
//!!!
void Juego::darCarta(queue<Tarjeta> &cartas, Jugador &jugador) {
  if (!cartas.empty()) {
    Tarjeta carta = cartas.front();
    jugador.agregarCarta(carta);
    cartas.pop();
  } else {
    cout << "No hay cartas en la cola" << endl;
  }
}

bool Juego::validarListaTerritorios(Jugador jugador,
                                    list<string> &territorios) {
  bool exist = true;
  string encontrar = jugador.getNomTerritorio();
  for (const std::string &territorio : territorios) {
    if (territorio.find(encontrar) != std::string::npos) {
      exist = false;
    }
  }
  return exist;
}

bool Juego::validarTurno(string nombre) {
  bool valido = true;
  Jugador jugadorAct = *jugadorActual;
  if (nombre != jugadorAct.getNombre()) {
    return false;
  }
  return valido;
}

void Juego ::siguienteJugador() {
  jugadorActual++;
  if (jugadorActual == listaJugadores.end()) {
    jugadorActual = listaJugadores.begin();
  }
}
//!
void Juego::determinarGanador(Jugador jugador) {
  bool ganador = false;
  vector<int> copia;
  copia = jugador.getCantTerritorioXContinente();
  int totalTerritorio = 0;
  for (int copias : copia) {
    totalTerritorio += copias;
  }
  if (totalTerritorio == 42) {
    ganador = true;
    setGanadorJuego(jugador.getNombre());
  }
  setGanador(ganador);
}
void Juego::asignarTerritoriosEInfanteria() {
    for (Jugador &jugador : listaJugadores) {
      jugador.ingresarTerritorio();
      jugador.seleccionarTerritorio();
      jugador.eliminarTerritorioDisponible(territorios);
    }
} 

// GET Y SET
int Juego::getCantJugadores() { return cantJugadores; }
void Juego::setCantJugadores(int nCantJugadores) {
  cantJugadores = nCantJugadores;
}
int Juego::getContIntercambio() { return contIntercambio; }
void Juego ::setContIntercambio(int nuevoCont) { contIntercambio = nuevoCont; }
void Juego ::setGanadorJuego(string ganJuego) { ganadorJuego = ganJuego; }
void Juego::setGanador(bool ganador1) { ganador = ganador1; }
*/