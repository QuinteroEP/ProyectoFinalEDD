#ifndef __PARTIDA__H__
#define __PARTIDA__H__

#include "Carta.h"
#include "Continente.h"
#include "Jugador.h"
#include <string> // librerías que usaremos
#include <list>
#include <queue>
#include <ctime>

class Partida
{
  public: //Atributos
    int idPartida;
    //std::string modoJuego;
    Continente* contiP[6];
    std::list<Jugador> jugadoresP;
    std::list<Carta> cartasP;
    std::queue<std::string> turnos;

  public: //Metodos
    Partida(int idP);
    Partida();
    Partida(Continente* contiP[], std::list<Jugador> jugadoresP, std::queue<std::string> turnos);
    void mostrarTerritoriosDisponibles();
    void mostrarTerritoriosPropios(std::string jug, std::string col);
    void mostrarTerritoriosEnemigos(std::string jug);
    void turno();
    void nuevasTropas();
    void atacar();
    void fortificar();
    bool guardarNormal(std::string nombreArchivo);
};

#endif 