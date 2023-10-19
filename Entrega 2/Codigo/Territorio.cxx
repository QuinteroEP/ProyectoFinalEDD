#include "Territorio.h"

#include <iostream>

Territorio::Territorio(std::string nombreTer)
{
  nombreTerritorio = nombreTer;
  numTropas = 0;
  tomado = false;
}