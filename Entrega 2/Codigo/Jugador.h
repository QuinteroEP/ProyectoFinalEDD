#ifndef __JUGADOR__H__
#define __JUGADOR__H__

#include <string> // librerías que usaremos
#include <list>

class Jugador
{
  public: //Atributos
    std::string nombreJugador;
    std::string colorJugador;
    int cantiTropas;

  public: //Metodos
    Jugador(std::string nombreJug, std::string colorJug, int cantiTropas);
    
};

#endif 