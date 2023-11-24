#ifndef __CONTINENTE__H__
#define __CONTINENTE__H__

#include "Territorio.h"
#include <string> // librerías que usaremos
#include <list>

class Continente
{
  public: //Atributos
    std::string nombreContinente;
    std::list <Territorio> territoriosC;

  public: //Metodos
    Continente(std::string nombreCon);
};

#endif