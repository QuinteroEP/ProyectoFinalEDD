using namespace std;
#include "tablero.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

Tablero::Tablero() : jugador_en_turno("", "", "0") {}

void Tablero::inicializarJuego(int cantJug, vector<Jugador> jugadores) {
  inicializarContientes();
  inicializarJugadores(jugadores);
  setJugadorEnTurno(jugador_en_turno);
  inicializarTarjetas();
  iterador_jugadores = jugadores_tablero.begin();

  vector<Territorio> terAux;
  for (list<Continente>::iterator it = continentes_tablero.begin();
       it != continentes_tablero.end(); it++) {
    for (Territorio t : it->getTerritoriosContinente()) {
      terAux.push_back(t);
    }
  }

  srand(time(0));
  int territorios_por_jugador = terAux.size() / cantJug;
  int territorios_extras = terAux.size() % cantJug;

  for (int i = 0; i < cantJug; i++) {
    int territorios_asignados = territorios_por_jugador;

    if (territorios_extras > 0) {
      territorios_asignados++;
      territorios_extras--;
    }

    for (int j = 0; j < territorios_asignados; j++) {
      int indice_territorio = rand() % terAux.size();
      while (terAux[indice_territorio].verificarExistenciaPropietario()) {
        indice_territorio = rand() % terAux.size();
      }
      jugadores_tablero[i].agregarTerritorio(&terAux[indice_territorio]);
      terAux[indice_territorio].establecerPropietario(
          jugadores_tablero[i].getId());
    }
  }

  // Repartir unidades por territorio teniendo en cuenta el jugador
  for (int i = 0; i < cantJug; i++) {
    int cant_territorios = jugadores_tablero[i].getTerritorios_jugador().size();
    int unidades_ejercito = jugadores_tablero[i].getUnidadesDeEjercito();
    int unidades_territorios = unidades_ejercito / cant_territorios;

    int unidades_extras = unidades_ejercito % (cant_territorios);

    for (int j = 0; j < cant_territorios; j++) {

      if (unidades_extras > 0) {
        jugadores_tablero[i]
            .getTerritorios_jugador()[j]
            ->setUnidadesDeEjercito_territorio(unidades_territorios + 1);
        unidades_extras--;
      } else {
        jugadores_tablero[i]
            .getTerritorios_jugador()[j]
            ->setUnidadesDeEjercito_territorio(unidades_territorios);
      }
    }
  }

  for (auto j : jugadores_tablero) {
    cout << endl
         << "Jugador: " << j.getNombre() << "  ID: " << j.getId() << endl;
    cout << "TERRITORIO -  UNIDAD EJERCITO" << endl;
    for (auto ter : j.getTerritorios_jugador()) {
      cout << ter->getNombre() << ": "
           << ter->getUnidadesDeEjercito_territorio() << endl;
    }
  }
}

void Tablero::inicializarContientes() {
  Continente americaDelNorte("America del Norte", "Amarillo");
  Territorio alaska("Alaska", americaDelNorte.getColor());
  Territorio alberta("Alberta", americaDelNorte.getColor());
  Territorio americaCen("America_Central", americaDelNorte.getColor());
  Territorio estadosUnidosOri("Estados_Unidos_Orientales",
                              americaDelNorte.getColor());
  Territorio groenlandia("Groenlandia", americaDelNorte.getColor());
  Territorio territorioNoroc("Territorio_Noroccidental",
                             americaDelNorte.getColor());
  Territorio ontario("Ontario", americaDelNorte.getColor());
  Territorio quebec("Quebec", americaDelNorte.getColor());
  Territorio estadosUnidosOc("Estados_Unidos_Occidentales",
                             americaDelNorte.getColor());
  // Continente: America del Sur
  Continente americaDelSur("America del Sur", "Rojo");
  Territorio argentina("Argentina", americaDelSur.getColor());
  Territorio brasil("Brasil", americaDelSur.getColor());
  Territorio peru("Perú", americaDelSur.getColor());
  Territorio venezuela("Venezuela", americaDelSur.getColor());
  // Continente: Europa
  Continente europa("Europa", "Azul");
  Territorio granBretana("Gran_Bretana", europa.getColor());
  Territorio islandia("Islandia", europa.getColor());
  Territorio europaDelNorte("Europa_del_Norte ", europa.getColor());
  Territorio escandinavia("Escandinavia", europa.getColor());
  Territorio europaDelSur("Europa_del_Sur", europa.getColor());
  Territorio ucrania("Ucrania", europa.getColor());
  Territorio europaOc("Europa_Occidental", europa.getColor());
  // Continente: africa
  Continente africa("africa", "Naranja");
  Territorio congo("Congo", africa.getColor());
  Territorio africaOrien("africa_Oriental", africa.getColor());
  Territorio egipto("Egipto", africa.getColor());
  Territorio madagascar("Madagascar", africa.getColor());
  Territorio africaDelNorte("africa_del_Norte", africa.getColor());
  Territorio africaDelSur("africa_del_Sur", africa.getColor());
  // Continente: Asia
  Continente asia("Asia", "Naranja");
  Territorio afghanistan("Afghanistan", asia.getColor());
  Territorio china("China", asia.getColor());
  Territorio india("India", asia.getColor());
  Territorio irkutsk("Irkutsk", asia.getColor());
  Territorio japon("Japon", asia.getColor());
  Territorio kamchatka("Kamchatka", asia.getColor());
  Territorio medioOriente("Medio_Oriente", asia.getColor());
  Territorio mongolia("Mongolia", asia.getColor());
  Territorio siam("Siam", asia.getColor());
  Territorio siberia("Siberia", asia.getColor());
  Territorio ural("Ural", asia.getColor());
  Territorio yakutsk("Yakutsk", asia.getColor());
  // Continente: Australia
  Continente australia("Australia", "Morado");
  Territorio australiaOriental("Australia_Oriental", australia.getColor());
  Territorio indonesia("Indonesia", australia.getColor());
  Territorio nuevaGuinea("Nueva_Guinea", australia.getColor());
  Territorio australiaOc("Australia_Occidental", australia.getColor());

  alaska.agregarTerritorioAlrededor(&alberta);
  alaska.agregarTerritorioAlrededor(&territorioNoroc);
  alaska.agregarTerritorioAlrededor(&kamchatka);
  alberta.agregarTerritorioAlrededor(&alaska);
  alberta.agregarTerritorioAlrededor(&territorioNoroc);
  alberta.agregarTerritorioAlrededor(&ontario);
  alberta.agregarTerritorioAlrededor(&estadosUnidosOc);
  americaCen.agregarTerritorioAlrededor(&estadosUnidosOc);
  americaCen.agregarTerritorioAlrededor(&estadosUnidosOri);
  americaCen.agregarTerritorioAlrededor(&venezuela);
  estadosUnidosOri.agregarTerritorioAlrededor(&quebec);
  estadosUnidosOri.agregarTerritorioAlrededor(&ontario);
  estadosUnidosOri.agregarTerritorioAlrededor(&americaCen);
  estadosUnidosOri.agregarTerritorioAlrededor(&estadosUnidosOc);
  groenlandia.agregarTerritorioAlrededor(&quebec);
  groenlandia.agregarTerritorioAlrededor(&ontario);
  groenlandia.agregarTerritorioAlrededor(&territorioNoroc);
  groenlandia.agregarTerritorioAlrededor(&islandia);
  territorioNoroc.agregarTerritorioAlrededor(&groenlandia);
  territorioNoroc.agregarTerritorioAlrededor(&alaska);
  territorioNoroc.agregarTerritorioAlrededor(&alberta);
  territorioNoroc.agregarTerritorioAlrededor(&ontario);
  ontario.agregarTerritorioAlrededor(&groenlandia);
  ontario.agregarTerritorioAlrededor(&territorioNoroc);
  ontario.agregarTerritorioAlrededor(&quebec);
  ontario.agregarTerritorioAlrededor(&alberta);
  ontario.agregarTerritorioAlrededor(&estadosUnidosOc);
  ontario.agregarTerritorioAlrededor(&estadosUnidosOri);
  quebec.agregarTerritorioAlrededor(&groenlandia);
  quebec.agregarTerritorioAlrededor(&ontario);
  quebec.agregarTerritorioAlrededor(&estadosUnidosOri);
  estadosUnidosOc.agregarTerritorioAlrededor(&alberta);
  estadosUnidosOc.agregarTerritorioAlrededor(&ontario);
  estadosUnidosOc.agregarTerritorioAlrededor(&estadosUnidosOri);
  estadosUnidosOc.agregarTerritorioAlrededor(&americaCen);

  granBretana.agregarTerritorioAlrededor(&islandia);
  granBretana.agregarTerritorioAlrededor(&europaOc);
  granBretana.agregarTerritorioAlrededor(&europaDelNorte);
  granBretana.agregarTerritorioAlrededor(&escandinavia);
  islandia.agregarTerritorioAlrededor(&groenlandia);
  islandia.agregarTerritorioAlrededor(&granBretana);
  islandia.agregarTerritorioAlrededor(&escandinavia);
  europaDelNorte.agregarTerritorioAlrededor(&granBretana);
  europaDelNorte.agregarTerritorioAlrededor(&escandinavia);
  europaDelNorte.agregarTerritorioAlrededor(&europaDelSur);
  europaDelNorte.agregarTerritorioAlrededor(&ucrania);
  europaDelNorte.agregarTerritorioAlrededor(&europaOc);
  escandinavia.agregarTerritorioAlrededor(&granBretana);
  escandinavia.agregarTerritorioAlrededor(&europaDelNorte);
  escandinavia.agregarTerritorioAlrededor(&islandia);
  escandinavia.agregarTerritorioAlrededor(&ucrania);
  europaDelSur.agregarTerritorioAlrededor(&ucrania);
  europaDelSur.agregarTerritorioAlrededor(&europaDelNorte);
  europaDelSur.agregarTerritorioAlrededor(&europaOc);
  europaDelSur.agregarTerritorioAlrededor(&medioOriente);
  europaDelSur.agregarTerritorioAlrededor(&africaDelNorte);
  europaDelSur.agregarTerritorioAlrededor(&egipto);
  ucrania.agregarTerritorioAlrededor(&escandinavia);
  ucrania.agregarTerritorioAlrededor(&europaDelNorte);
  ucrania.agregarTerritorioAlrededor(&europaDelSur);
  ucrania.agregarTerritorioAlrededor(&afghanistan);
  ucrania.agregarTerritorioAlrededor(&medioOriente);
  ucrania.agregarTerritorioAlrededor(&ural);
  europaOc.agregarTerritorioAlrededor(&granBretana);
  europaOc.agregarTerritorioAlrededor(&africaDelNorte);
  europaOc.agregarTerritorioAlrededor(&europaDelNorte);
  europaOc.agregarTerritorioAlrededor(&europaDelSur);

  afghanistan.agregarTerritorioAlrededor(&ural);
  afghanistan.agregarTerritorioAlrededor(&china);
  afghanistan.agregarTerritorioAlrededor(&india);
  afghanistan.agregarTerritorioAlrededor(&medioOriente);
  china.agregarTerritorioAlrededor(&afghanistan);
  china.agregarTerritorioAlrededor(&india);
  china.agregarTerritorioAlrededor(&siam);
  china.agregarTerritorioAlrededor(&mongolia);
  china.agregarTerritorioAlrededor(&siberia);
  china.agregarTerritorioAlrededor(&ural);
  india.agregarTerritorioAlrededor(&china);
  india.agregarTerritorioAlrededor(&afghanistan);
  india.agregarTerritorioAlrededor(&medioOriente);
  india.agregarTerritorioAlrededor(&siam);
  irkutsk.agregarTerritorioAlrededor(&siberia);
  irkutsk.agregarTerritorioAlrededor(&yakutsk);
  irkutsk.agregarTerritorioAlrededor(&kamchatka);
  irkutsk.agregarTerritorioAlrededor(&mongolia);
  japon.agregarTerritorioAlrededor(&mongolia);
  japon.agregarTerritorioAlrededor(&kamchatka);
  kamchatka.agregarTerritorioAlrededor(&japon);
  kamchatka.agregarTerritorioAlrededor(&yakutsk);
  kamchatka.agregarTerritorioAlrededor(&mongolia);
  kamchatka.agregarTerritorioAlrededor(&irkutsk);
  kamchatka.agregarTerritorioAlrededor(&alaska);
  medioOriente.agregarTerritorioAlrededor(&afghanistan);
  medioOriente.agregarTerritorioAlrededor(&india);
  medioOriente.agregarTerritorioAlrededor(&europaDelSur);
  medioOriente.agregarTerritorioAlrededor(&ucrania);
  medioOriente.agregarTerritorioAlrededor(&egipto);
  mongolia.agregarTerritorioAlrededor(&siberia);
  mongolia.agregarTerritorioAlrededor(&china);
  mongolia.agregarTerritorioAlrededor(&irkutsk);
  mongolia.agregarTerritorioAlrededor(&japon);
  mongolia.agregarTerritorioAlrededor(&kamchatka);
  siam.agregarTerritorioAlrededor(&china);
  siam.agregarTerritorioAlrededor(&india);
  siam.agregarTerritorioAlrededor(&indonesia);
  siberia.agregarTerritorioAlrededor(&china);
  siberia.agregarTerritorioAlrededor(&irkutsk);
  siberia.agregarTerritorioAlrededor(&mongolia);
  siberia.agregarTerritorioAlrededor(&ural);
  siberia.agregarTerritorioAlrededor(&yakutsk);
  ural.agregarTerritorioAlrededor(&china);
  ural.agregarTerritorioAlrededor(&afghanistan);
  ural.agregarTerritorioAlrededor(&siberia);
  ural.agregarTerritorioAlrededor(&ucrania);
  yakutsk.agregarTerritorioAlrededor(&irkutsk);
  yakutsk.agregarTerritorioAlrededor(&kamchatka);
  yakutsk.agregarTerritorioAlrededor(&siberia);

  australiaOriental.agregarTerritorioAlrededor(&nuevaGuinea);
  australiaOriental.agregarTerritorioAlrededor(&australiaOc);
  indonesia.agregarTerritorioAlrededor(&siam);
  indonesia.agregarTerritorioAlrededor(&nuevaGuinea);
  indonesia.agregarTerritorioAlrededor(&australiaOc);
  nuevaGuinea.agregarTerritorioAlrededor(&australiaOriental);
  nuevaGuinea.agregarTerritorioAlrededor(&indonesia);
  nuevaGuinea.agregarTerritorioAlrededor(&australiaOc);
  australiaOc.agregarTerritorioAlrededor(&australiaOriental);
  australiaOc.agregarTerritorioAlrededor(&indonesia);
  australiaOc.agregarTerritorioAlrededor(&nuevaGuinea);

  congo.agregarTerritorioAlrededor(&africaOrien);
  congo.agregarTerritorioAlrededor(&africaDelNorte);
  congo.agregarTerritorioAlrededor(&africaDelSur);
  africaOrien.agregarTerritorioAlrededor(&congo);
  africaOrien.agregarTerritorioAlrededor(&egipto);
  africaOrien.agregarTerritorioAlrededor(&madagascar);
  africaOrien.agregarTerritorioAlrededor(&africaDelNorte);
  africaOrien.agregarTerritorioAlrededor(&africaDelSur);
  egipto.agregarTerritorioAlrededor(&africaOrien);
  egipto.agregarTerritorioAlrededor(&africaDelNorte);
  egipto.agregarTerritorioAlrededor(&europaDelSur);
  egipto.agregarTerritorioAlrededor(&medioOriente);
  madagascar.agregarTerritorioAlrededor(&africaOrien);
  madagascar.agregarTerritorioAlrededor(&europaDelSur);
  africaDelNorte.agregarTerritorioAlrededor(&congo);
  africaDelNorte.agregarTerritorioAlrededor(&africaOrien);
  africaDelNorte.agregarTerritorioAlrededor(&egipto);
  africaDelNorte.agregarTerritorioAlrededor(&china);
  africaDelNorte.agregarTerritorioAlrededor(&europaOc);
  africaDelNorte.agregarTerritorioAlrededor(&europaDelSur);
  africaDelSur.agregarTerritorioAlrededor(&congo);
  africaDelSur.agregarTerritorioAlrededor(&africaOrien);
  africaDelSur.agregarTerritorioAlrededor(&madagascar);

  argentina.agregarTerritorioAlrededor(&brasil);
  argentina.agregarTerritorioAlrededor(&peru);
  brasil.agregarTerritorioAlrededor(&peru);
  brasil.agregarTerritorioAlrededor(&argentina);
  brasil.agregarTerritorioAlrededor(&venezuela);
  brasil.agregarTerritorioAlrededor(&africaDelNorte);
  peru.agregarTerritorioAlrededor(&argentina);
  peru.agregarTerritorioAlrededor(&brasil);
  peru.agregarTerritorioAlrededor(&venezuela);
  venezuela.agregarTerritorioAlrededor(&brasil);
  venezuela.agregarTerritorioAlrededor(&peru);
  venezuela.agregarTerritorioAlrededor(&americaCen);

  americaDelNorte.agregarTerritorios(alaska);
  americaDelNorte.agregarTerritorios(alberta);
  americaDelNorte.agregarTerritorios(americaCen);
  americaDelNorte.agregarTerritorios(estadosUnidosOri);
  americaDelNorte.agregarTerritorios(groenlandia);
  americaDelNorte.agregarTerritorios(territorioNoroc);
  americaDelNorte.agregarTerritorios(ontario);
  americaDelNorte.agregarTerritorios(quebec);
  americaDelNorte.agregarTerritorios(estadosUnidosOc);
  americaDelSur.agregarTerritorios(brasil);
  americaDelSur.agregarTerritorios(peru);
  americaDelSur.agregarTerritorios(venezuela);
  americaDelSur.agregarTerritorios(argentina);
  europa.agregarTerritorios(granBretana);
  europa.agregarTerritorios(islandia);
  europa.agregarTerritorios(europaDelNorte);
  europa.agregarTerritorios(escandinavia);
  europa.agregarTerritorios(europaDelSur);
  europa.agregarTerritorios(ucrania);
  europa.agregarTerritorios(europaOc);
  africa.agregarTerritorios(congo);
  africa.agregarTerritorios(africaOrien);
  africa.agregarTerritorios(egipto);
  africa.agregarTerritorios(madagascar);
  africa.agregarTerritorios(africaDelNorte);
  africa.agregarTerritorios(africaDelSur);
  asia.agregarTerritorios(afghanistan);
  asia.agregarTerritorios(china);
  asia.agregarTerritorios(india);
  asia.agregarTerritorios(irkutsk);
  asia.agregarTerritorios(japon);
  asia.agregarTerritorios(kamchatka);
  asia.agregarTerritorios(medioOriente);
  asia.agregarTerritorios(mongolia);
  asia.agregarTerritorios(siam);
  asia.agregarTerritorios(siberia);
  asia.agregarTerritorios(ural);
  asia.agregarTerritorios(yakutsk);
  australia.agregarTerritorios(australiaOriental);
  australia.agregarTerritorios(indonesia);
  australia.agregarTerritorios(nuevaGuinea);
  australia.agregarTerritorios(australiaOc);
  continentes_tablero.push_back(americaDelNorte);
  continentes_tablero.push_back(americaDelSur);
  continentes_tablero.push_back(europa);
  continentes_tablero.push_back(africa);
  continentes_tablero.push_back(asia);
  continentes_tablero.push_back(australia);
  /*
  for (auto x: continentes_tablero){
    vector<Territorio>  v = x.getTerritoriosContinente();
    cout << "Continente:" << x.getNombre() << endl;
    for (auto y: v){
      cout << "Territorio:" << y.getNombre() << endl;
      cout << "lista de alrededores" << endl;
      for(auto z: y.getTerritorioAlrededor()){
        cout << "-" << z->getNombre() << endl;
      }
    }
  }
  */
}

void Tablero::inicializarJugadores(vector<Jugador> jugadores) {
  jugadores_tablero = jugadores;

  int unidadesAux;
  if (jugadores_tablero.size() == 3) {
    unidadesAux = 35;
  } else if (jugadores_tablero.size() == 4) {
    unidadesAux = 30;
  } else if (jugadores_tablero.size() == 5) {
    unidadesAux = 25;
  } else if (jugadores_tablero.size() == 6) {
    unidadesAux = 20;
  }

  for (int i = 0; i < jugadores_tablero.size(); i++) {
    jugadores_tablero[i].setUnidadesDeEjercito(unidadesAux);
  }
}

void Tablero::inicializarTarjetas() {
  vector<Territorio> terAux;
  vector<int> valores = {1, 5, 10};
  vector<string> tipos = {"Infantería", "Caballería", "Artillería"};

  for (list<Continente>::iterator it = continentes_tablero.begin();
       it != continentes_tablero.end(); it++) {
    for (Territorio t : it->getTerritoriosContinente()) {
      terAux.push_back(t);
    }
  }

  for (int i = 0; i < terAux.size(); i++) {
    Tarjeta tar(tipos[i % 3], &terAux[i], valores[i % 3]);
    tarjetas_tablero.push_back(tar);
  }

  Tarjeta com1("Comodín", 0);
  Tarjeta com2("Comodín", 0);
  tarjetas_tablero.push_back(com1);
  tarjetas_tablero.push_back(com2);
}

void Tablero::setJugadorEnTurno(Jugador j) { jugador_en_turno = j; }

Jugador Tablero::getJugadorEnTurno() { return jugador_en_turno; }

bool Tablero::asignarTurno(string idJug) {

  bool jugadorCorrecto = false;

  // cout << "ID INGRESADO POR USUARIO: " << idJug << endl;
  // cout << "Fuera if: " << jugador_en_turno.getId() << endl;
  if (jugador_en_turno.getId() == idJug) {
    // cout << "Dentro if: " << jugador_en_turno.getId() << endl;

    while (iterador_jugadores != jugadores_tablero.end()) {
      if (iterador_jugadores == jugadores_tablero.begin()) {
        setJugadorEnTurno(*iterador_jugadores);
      }
      jugadorCorrecto = true;
      cout << "Jugador en turno" << iterador_jugadores->getNombre() << endl;

      faseDraft(jugador_en_turno.getId());
      faseAtacar(jugador_en_turno.getId());
      faseFortalecer(jugador_en_turno.getId());

      ++iterador_jugadores;

      if (iterador_jugadores == jugadores_tablero.end()) {
        iterador_jugadores = jugadores_tablero.begin();
      }
      setJugadorEnTurno(*iterador_jugadores);

      break;
    }
  }

  return jugadorCorrecto;
}

void Tablero::faseDraft(string idJug) {
  cout << "FASE DRAFT" << endl;
  int unidadesAsignadadas = calcularCantUnidadesNuevas(idJug);
  cout << "Se han asignado: " << unidadesAsignadadas << " unidades nuevas."
       << endl;

  for (Jugador &j : jugadores_tablero) {
    if (j.getId() == idJug) {

      bool encontroTerritorio = false;
      bool unidadesValidas = false;

      do {
        cout << "A cual territorio quiere asignar unidades?: ";
        string nom_territorio;
        cin >> nom_territorio;
        for (Territorio *t : j.getTerritorios_jugador()) {
          if (nom_territorio == t->getNombre()) {
            encontroTerritorio = true;

            do {
              cout << "Cuantas unidades quiere asignar?: ";
              int unidadesEspecificas;
              cin >> unidadesEspecificas;

              if (unidadesEspecificas > unidadesAsignadadas) {
                cout << "Unidades invalidas" << endl;
              } else {
                t->agregarUnidadesTerritorioAdicional(unidadesEspecificas);
                unidadesAsignadadas -= unidadesEspecificas;
                unidadesValidas = true;
              }
            } while (!unidadesValidas);
          }
        }

        if (!encontroTerritorio) {
          cout << "Territorio invalido" << endl;
        }

      } while (unidadesAsignadadas > 0);
    }
  }

  cout << "Se han agregado todas las unidades adicionales correctamente."
       << endl;
}

void Tablero::faseAtacar(string idJug) {
  vector<Territorio *> territoriosAtacar;
  string territorio_atacar = "";
  string territorio_ataque = "";
  
  cout << "FASE ATACAR" << endl;
  for (Jugador &j : jugadores_tablero) {
    if (j.getId() == idJug) {
      cout << "Tus territorios desde los que puedes atacar:" << endl;
      for (Territorio *ter : j.getTerritorios_jugador()) {
        cout << "Nombre: " << ter->getNombre() << endl;
      }

      cout << "Desde que territorio deseas atacar?: ";
      cin >> territorio_ataque;
      cin.ignore();
      for (Territorio *ter : j.getTerritorios_jugador()) {
        if (ter->getNombre() == territorio_ataque) {
          vector<Territorio *> vecAux = ter->getTerritorioAlrededor();
          cout << "Territorios que puedes atacar: " << endl;
          for (Territorio *terAux : vecAux) {
            if (terAux != nullptr && j.getId() != terAux->getPropietario()) {
              cout << terAux->getNombre() << endl;
              territoriosAtacar.push_back(terAux);
            }
          }

          cout << "Ingrese el territorio para atacar: " << endl;
          cin >> territorio_atacar;
          cin.ignore();
          for (Territorio *terAux2 : vecAux) {
            for (int i = 0; i < territoriosAtacar.size(); i++) {
              if (territoriosAtacar[i]->getNombre() == territorio_atacar) {
                
                int resultado = tirarDados();
                cout << "resultado dados" << resultado << endl;
                if (resultado == 1) {
                  int unidadesAux =
                      territoriosAtacar[i]->getUnidadesDeEjercito_territorio();
                  if (unidadesAux > 1) {
                    for (Jugador jr : jugadores_tablero) {
                      if (terAux2->getPropietario() == jr.getId()) {
                        jr.eliminarUnidadesEjercito();
                      }
                    }
                    territoriosAtacar[i]->eliminarUnidadesTerritorio();

                    cout << "Se ha eliminado 1 unidad de ejercito de "
                         << territoriosAtacar[i]->getNombre() << endl;
                  } else if (unidadesAux == 1) {
                    cout << "El territorio ha sido anexado" << endl;
                  }

                } else if (resultado == 2){
                  j.eliminarUnidadesEjercito();
                  ter->eliminarUnidadesTerritorio();
                  cout << "Se ha eliminado 1 unidad de ejercito de "
                       << ter->getNombre();
                }
              }
            }
          }
        }
      }
    }
  }
}

void Tablero::faseFortalecer(string idJug) {

  cout << "FASE FORTALECER" << endl;
  cout << "Quiere fortalecer? (si o no): " << endl;
  string fortalecer;
  cin >> fortalecer;

  if (fortalecer == "si") {
    cout << "Me fortaleci" << endl;

  } else {
    cout << "Turno finalizado" << endl;
  }
}
int Tablero::calcularCantUnidadesNuevas(string idJug) {
  int ejercitos_minimos = 0;
  int ejercitos_por_continente = 0;
  int ejercitos_por_cartas = 0;
  vector<string> continentes_conquistados;
  Jugador *jugAuxs;

  for (Jugador j : jugadores_tablero) {
    if (j.getId() == idJug) {
      jugAuxs = &j;
      ejercitos_minimos = max(3, j.getUnidadesDeEjercito() / 3);
    }
  }

  if (jugAuxs == nullptr) {
    return 0;
  }

  for (Continente c : continentes_tablero) {
    int cantTerAux = 0;
    for (Territorio t : c.getTerritoriosContinente()) {
      if (t.getPropietario() == jugAuxs->getNombre()) {

        cantTerAux++;
      }
    }
    if (cantTerAux == c.getTerritoriosContinente().size()) {
      continentes_conquistados.push_back(c.getNombre());
    }
  }

  for (string s : continentes_conquistados) {
    if (s == "AmericaDelSur" || s == "Australia") {
      ejercitos_por_continente += 2;
    } else if (s == "Africa") {
      ejercitos_por_continente += 3;
    } else if (s == "AmericaDelNorte" || s == "Europa") {
      ejercitos_por_continente += 5;
    } else if (s == "Asia") {
      ejercitos_por_continente += 7;
    }
  }

  // ejercitos_por_cartas = calcularCantUnidadesCartas(jugAuxs);
  int ejercitos_totales = ejercitos_minimos + ejercitos_por_continente;
  jugAuxs->setUnidadesDeEjercito(ejercitos_totales);
  return ejercitos_totales;
}

int Tablero::calcularCantUnidadesCartas(Jugador *jugAuxs) {
  vector<Tarjeta *> cant_infanteria;
  vector<Tarjeta *> cant_artilleria;
  vector<Tarjeta *> cant_caballeria;
  vector<Tarjeta *> cant_comodines;
  int unidadesCartas = 0;

  for (Tarjeta *carta : jugAuxs->getTarjetas()) {
    if (carta->getTipo() == "Infanteria") {
      cant_infanteria.push_back(carta);
    } else if (carta->getTipo() == "Artilleria") {
      cant_artilleria.push_back(carta);
    } else if (carta->getTipo() == "Caballeria") {
      cant_caballeria.push_back(carta);
    } else if (carta->getTipo() == "Comodin") {
      cant_comodines.push_back(carta);
    }
  }

  if (cant_infanteria.size() == 3) {
    unidadesCartas += 4;
    for (Tarjeta *t : cant_infanteria) {
      vector<Tarjeta *> tarjetas = jugAuxs->getTarjetas();
      for (vector<Tarjeta *>::iterator it = tarjetas.begin();
           it != tarjetas.end();) {
        if (*it == t) {
          it = tarjetas.erase(it);
          break;
        } else {
          ++it;
        }
      }
    }
    cant_infanteria.clear();
  } else if (cant_caballeria.size() == 3) {
    unidadesCartas += 6;
    for (Tarjeta *t : cant_caballeria) {
      vector<Tarjeta *> tarjetas = jugAuxs->getTarjetas();
      for (vector<Tarjeta *>::iterator it = tarjetas.begin();
           it != tarjetas.end();) {
        if (*it == t) {
          it = tarjetas.erase(it);
          break;
        } else {
          ++it;
        }
      }
    }
    cant_caballeria.clear();
  } else if (cant_artilleria.size() == 3) {
    unidadesCartas += 8;
    for (Tarjeta *t : cant_artilleria) {
      vector<Tarjeta *> tarjetas = jugAuxs->getTarjetas();
      for (vector<Tarjeta *>::iterator it = tarjetas.begin();
           it != tarjetas.end();) {
        if (*it == t) {
          it = tarjetas.erase(it);
          break;
        } else {
          ++it;
        }
      }
    }
    cant_artilleria.clear();
  } else if (cant_infanteria.size() >= 1 && cant_artilleria.size() >= 1 &&
             cant_caballeria.size() >= 1) {
    unidadesCartas += 10;
  }

  return unidadesCartas;
}

int Tablero::tirarDados() {
  vector<int> dados_atacante;
  vector<int> dados_defensor;
  int victoriasAtacante = 0, victoriasDefensor = 0;

  mt19937 rng(time(0));
  uniform_int_distribution<int> dist(1, 6);

  for (int i = 0; i < 3; i++) {
    dados_atacante.push_back(dist(rng));
  }
  sort(dados_atacante.begin(), dados_atacante.end(), greater<int>());

  for (int i = 0; i < 2; i++) {
    dados_defensor.push_back(dist(rng));
  }
  sort(dados_defensor.begin(), dados_defensor.end(), greater<int>());

  for (int i = 0; i < 2; i++) {
    if (dados_atacante[i] > dados_defensor[i]) {
      victoriasAtacante++;
    } else {
      victoriasDefensor++;
    }
  }

  if (victoriasAtacante > victoriasDefensor) {

    return 1;
  } else if (victoriasDefensor > victoriasAtacante) {
    return 2;
  } else {
    return 2;
  }
}