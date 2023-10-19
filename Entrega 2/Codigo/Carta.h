#ifndef __CARTA__H__
#define __CARTA__H__

#include <string> // librerías que usaremos

class Carta
{
  public: //Atributos
    std::string nombreCarta;
    std::string tipoCarta;
    std::string descripcion;
    std::string duenio;
    bool tomado;

  public: //Metodos
    Carta(std::string nombre, std::string tipo, std::string descri);

};

#endif 