#ifndef __MENU__H__
#define __MENU__H__

#include "Partida.h"
#include <string> // librerías que usaremos
#include <regex>

class Menu
{
  public:
    static void mapamundi(); // métodos de la clase
    static void menu();
    static Partida inicio();
    static Partida abrirNormal(std::string nombreArchivo);
    static bool guardarComprimido(Partida p, std::string nombreArchivo);
    static Partida abrirComprimido(std::string nombreArchivo);
};

#endif // __MENU__H__

// eof - Menu.h
