#include "Continente.h"

#include <iostream>

Continente::Continente(std::string nombreCon) : territoriosC()
{
  nombreContinente = nombreCon;

  //Nombre de todos los territorios
  std::string ADN[9] = {"Alaska","Alberta","America Central","Estados Unidos Orientales","Groenlandia","Territorio Noroccidental","Ontario","Quebec","Estados Unidos Occidentales"};
  std::string ADS[4] = {"Argentina","Brasil","Peru","Venezuela"};
  std::string  EU[7] = {"Gran Bretana","Islandia","Europa del Norte","Escandinavia","Europa del Sur","Ucrania","Europa Occidental"};
  std::string  AF[6] = {"Congo","Africa Oriental","Egipto","Madagascar","Africa del Norte","Africa del Sur"};
  std::string  AS[12] = {"Afghanistan","China","India","Irkutsk","Japon","Kamchatka","Medio Oriente","Mongolia","Siam","Siberia","Ural","Yakutsk"};
  std::string  AST[4] = {"Australia Oriental","Indonesia","Nueva Guinea","Australia Occidental"};
  
    if (nombreContinente.compare("America Del Norte") == 0) //se asigna el territorio correspondiente a cada continente
    {
      for (int i = 0; i < 9; i++)
      {
        Territorio aux = Territorio(ADN[i]);
        territoriosC.push_back(aux);
      }    
    }
      
    else if (nombreContinente.compare("America Del Sur") == 0)
    {
      for (int i = 0; i < 4; i++)
      {
        Territorio aux = Territorio(ADS[i]);
        territoriosC.push_back(aux);
      } 
    }
      
    else if (nombreContinente.compare("Europa") == 0)
    {
      for (int i = 0; i < 7; i++)
      {
        Territorio aux = Territorio(EU[i]);
        territoriosC.push_back(aux);
      } 
    }

    else if (nombreContinente.compare("Africa") == 0)
    {
      for (int i = 0; i < 6; i++)
      {
        Territorio aux = Territorio(AF[i]);
        territoriosC.push_back(aux);
      } 
    }
      
    else if (nombreContinente.compare("Asia") == 0)
    {
      for (int i = 0; i < 12; i++)
      {
        Territorio aux = Territorio(AS[i]);
        territoriosC.push_back(aux);
      } 
    }
      
    else if (nombreContinente.compare("Australia") == 0)
    {
      for (int i = 0; i < 4; i++)
      {
        Territorio aux = Territorio(AST[i]);
        territoriosC.push_back(aux);
      }
    }
  
}