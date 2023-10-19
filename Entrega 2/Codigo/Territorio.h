#ifndef __TERRITORIO__H__
#define __TERRITORIO__H__

#include <string> // librerías que usaremos

class Territorio
{
  public: //Atributos
    std::string nombreTerritorio;
    //std::string vecinos[];
    std::string duenio;
    int numTropas;
    bool tomado;

  public: //Metodos
    Territorio(std::string nombreTer);
};

#endif