#include "Partida.h"

#include <iostream>
#include <limits>
#include <fstream>
#include <algorithm>
#include <vector>

// cosas que se necesitan para cambiar el color del texto
#define reset "\033[0m"
#define blue "\033[34m" 
#define red "\033[31m" 
#define green "\033[92m" 
#define yellow "\033[93m" 
#define magenta "\033[35m"
#define cyan "\033[96m"

Partida::Partida(int idP) : jugadoresP(), cartasP(), turnos()
{
  idPartida = idP;

  contiP[0] = new Continente("America Del Norte"); //llenar el arreglo con los continentes 
  contiP[1] = new Continente("America Del Sur");
  contiP[2] = new Continente("Europa");
  contiP[3] = new Continente("Africa");
  contiP[4] = new Continente("Asia");
  contiP[5] = new Continente("Australia");

  crearGrafo();

  int num, numTrop;
  
  do
  {
  std::cout<<"\nIngrese la cantidad de jugadores: ";
  std::cin>>num;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  } while (num < 2 || num > 6);

  if (num == 2){
    numTrop = 40;
  }
  else if (num == 3)
  {
    numTrop = 35;
  }
  else if (num == 4)
  {
    numTrop = 30;
  }
  else if (num == 5)
  {
    numTrop = 25;
  }
  else if (num == 6)
  {
    numTrop = 20;
  }

  for (int i=0; i<num; i++)
  {
    std::string nom;
    std::cout<<"\nIngrese el nombre del jugador: ";
    std::cin>>nom;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string color;
    if (i == 0)
    {
      color = "azul";
      std::cout<<"\n"<<blue<<"Jugador "<<i<<" : "<<nom<<reset<<"\n";
    }

    else if (i == 1)
    {
      color = "rojo";
      std::cout<<"\n"<<red<<"Jugador "<<i<<" : "<<nom<<reset<<"\n";
    }

    else if (i == 2)
    {
      color = "verde";
      std::cout<<"\n"<<green<<"Jugador "<<i<<" : "<<nom<<reset<<"\n";
    }

    else if (i == 3)
    {
      color = "amarillo";
      std::cout<<"\n"<<yellow<<"Jugador "<<i<<" : "<<nom<<reset<<"\n";
    }

    else if (i == 4)
    {
      color = "magenta";
      std::cout<<"\n"<<magenta<<"Jugador "<<i<<" : "<<nom<<reset<<"\n";
    }

    else if (i == 5)
    {
      color = "cyan";
      std::cout<<"\n"<<cyan<<nom<<"Jugador "<<i<<" : "<<reset<<"\n";
    }
    
    Jugador j = Jugador(nom, color, numTrop);

    jugadoresP.push_back(j); // se crea la lista de jugadores

    turnos.push(nom); // se va creando la cola
  }

  std::string cont0;
  std::cout<<"\nPresione enter para continuar ";
  std::getline(std::cin, cont0);

  //elegir territorios

  int aux = 0;

  std::system("clear");
   
  //while(aux < 6)
  while(aux < 42)
  {
    bool puede = false, enc = false;
    std::list<Jugador>::iterator miIt;
    
    for (miIt = jugadoresP.begin(); miIt != jugadoresP.end(); miIt++)
    {      
      if(turnos.front() == miIt->nombreJugador)
      {        
        while(puede == false)
        {          
          mostrarTerritoriosDisponibles();
          
          std::string sele, aux2 = miIt->colorJugador;

          if(aux2.compare("azul") == 0)
          {
            std::cout<<blue;
          }
          else if(aux2.compare("rojo") == 0)
          {
            std::cout<<red;
          }
          else if(aux2.compare("verde") == 0)
          {
            std::cout<<green;
          }
          else if(aux2.compare("amarillo") == 0)
          {
            std::cout<<yellow;
          }
          else if(aux2.compare("magenta") == 0)
          {
            std::cout<<magenta;
          }
          else if(aux2.compare("cyan") == 0)
          {
            std::cout<<cyan;
          }

          std::cout<<"\nEs el turno de "<<miIt->nombreJugador<<" para elegir territorio\n";
          std::cout<<"\nQue territorio desea elegir? "<<reset;
          std::getline(std::cin, sele);

          std::system("clear");
          
          std::list<Territorio>::iterator miIt2;
          for(int i=0; i<6; i++)
          {
            for (miIt2 = contiP[i]->territoriosC.begin(); miIt2 != contiP[i]->territoriosC.end(); miIt2++)
            {
              if(sele.compare(miIt2->nombreTerritorio) == 0 && miIt2->tomado == false)
              {
                miIt2->tomado = true;
                miIt2->numTropas = 1;
                miIt2->duenio = miIt->nombreJugador;
                int canti = miIt->cantiTropas;
                miIt->cantiTropas = canti - 1; 
                puede = true;
                enc = true;

                std::string aux3 = miIt->colorJugador;

                if(aux3.compare("azul") == 0)
                {
                  std::cout<<blue;
                }
                else if(aux3.compare("rojo") == 0)
                {
                  std::cout<<red;
                }
                else if(aux3.compare("verde") == 0)
                {
                  std::cout<<green;
                }
                else if(aux3.compare("amarillo") == 0)
                {
                  std::cout<<yellow;
                }
                else if(aux3.compare("magenta") == 0)
                {
                  std::cout<<magenta;
                }
                else if(aux3.compare("cyan") == 0)
                {
                  std::cout<<cyan;
                }

                std::cout<<"El territorio "<<sele<<" es de "<<miIt->nombreJugador<<"\n"<<reset;

              }
              else if (sele.compare(miIt2->nombreTerritorio) == 0 && miIt2->tomado == true)
              {
                std::cout<<"El territorio "<<sele<<" ya fue selecionado por "<<miIt2->duenio<<"\n\n";
                enc = true;
              }
            }
          }
          
          if (aux == 0)
          {

          }
          else if (enc == false)
          {
            std::cout<<"No se pudo encontrar el territorio "<<sele<<"\n";
          } 
        }
      }
    }

    std::string turn = turnos.front();
    turnos.pop();
    turnos.push(turn);
    aux++;
  }

  bool finito = false;
  std::string sele2;

  while(finito == false) 
  {
    std::list<Jugador>::iterator miIt3;

    for (miIt3 = jugadoresP.begin(); miIt3 != jugadoresP.end(); miIt3++)
    { 
      if(turnos.front() == miIt3->nombreJugador)
      { 
        if(miIt3->cantiTropas > 0)
        {
          std::string nom = miIt3->nombreJugador;
          std::string col = miIt3->colorJugador;
          mostrarTerritoriosPropios(nom, col);
          
          bool puede2 = false;

          while(puede2 == false)
          {
            std::string aux4 = miIt3->colorJugador;

            if(aux4.compare("azul") == 0)
            {
              std::cout<<blue;
            }
            else if(aux4.compare("rojo") == 0)
            {
              std::cout<<red;
            }
            else if(aux4.compare("verde") == 0)
            {
              std::cout<<green;
            }
            else if(aux4.compare("amarillo") == 0)
            {
              std::cout<<yellow;
            }
            else if(aux4.compare("magenta") == 0)
            {
              std::cout<<magenta;
            }
            else if(aux4.compare("cyan") == 0)
            {
              std::cout<<cyan;
            }
            
            std::cout<<"\nEs el turno de "<<miIt3->nombreJugador<<" para asignar mas tropas\n";
            std::cout<<"\nQue territorio desea elegir? ";
            std::getline(std::cin, sele2);
            
            std::list<Territorio>::iterator miIt4;
            for(int i=0; i<6; i++)
            {
              for (miIt4 = contiP[i]->territoriosC.begin(); miIt4 != contiP[i]->territoriosC.end(); miIt4++)
              {
                if(sele2.compare(miIt4->nombreTerritorio) == 0 && miIt4->duenio ==  miIt3->nombreJugador)
                {
                  bool puede3 = false;
                  while (puede3 == false)
                  { 
                    int mandar;
                    std::cout<<"\nCuantas tropas quiere agregar? (tiene "<<miIt3->cantiTropas<<" tropas) ";
                    std::cin>>mandar;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    if (mandar <= miIt3->cantiTropas)
                    { 
                      int nueva = miIt4->numTropas;
                      miIt4->numTropas = nueva + mandar;

                      int canti = miIt3->cantiTropas;
                      miIt3->cantiTropas = canti - mandar;

                      puede3=true;
                    }
                    else
                    {
                      std::cout<<"\nNo tiene suficientes tropas\n";
                    }
                  }
                  puede2 = true;

                  std::system("clear");
                  std::cout<<"El territorio "<<sele2<<" de "<<miIt3->nombreJugador<<" ahora tiene "<<miIt4->numTropas<<" tropas\n"<<reset;
                }
                else
                {
                  
                }
              }
            }

            if(puede2 == false)
              std::cout<<"\nEl territorio "<<sele2<<" no existe o no es tuyo\n";
          }
        }
        else
        {
          std::string aux5 = miIt3->colorJugador;

          if(aux5.compare("azul") == 0)
          {
            std::cout<<blue;
          }
          else if(aux5.compare("rojo") == 0)
          {
            std::cout<<red;
          }
          else if(aux5.compare("verde") == 0)
          {
            std::cout<<green;
          }
          else if(aux5.compare("amarillo") == 0)
          {
            std::cout<<yellow;
          }
          else if(aux5.compare("magenta") == 0)
          {
            std::cout<<magenta;
          }
          else if(aux5.compare("cyan") == 0)
          {
            std::cout<<cyan;
          }
          
          std::cout<<"\nEl jugador "<<miIt3->nombreJugador<<" ya no tiene mas tropas\n"<<reset;
        }
      }
    }
    std::string turn = turnos.front();
    turnos.pop();
    turnos.push(turn);

    int conta = 0;

    std::list<Jugador>::iterator miItX;
    for(miItX = jugadoresP.begin(); miItX != jugadoresP.end(); miItX++)
    {
      if(miItX->cantiTropas == 0)
      {
        conta++;
      }
    }

    if (conta == num)
      finito = true;
  }
}

Partida::Partida() 
{
  
}

Partida::Partida(Continente* contiPa[], std::list<Jugador> jugadoresPa, std::queue<std::string> turnosPa)
{
  crearGrafo();

  for(int i=0; i<6; i++)
  {
    contiP[i] = contiPa[i];
  }

  jugadoresP = jugadoresPa;

  turnos = turnosPa;
}

void Partida::mostrarTerritoriosDisponibles()
{
  std::cout<<"\nEstos son los territorios disponibles:\n";
  for(int i=0; i<6; i++)
  {
    std::cout<<"\n"<<contiP[i]->nombreContinente<<":\n";
    int conta = 1;
    std::list<Territorio>::iterator miIt;
    for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
    {
      if(miIt->tomado == false)
      {
        std::cout<<conta<<". "<<miIt->nombreTerritorio<<"\n";
        conta++;
      }
    }
  }
}

void Partida::mostrarTerritoriosPropios(std::string jug, std::string col)
{
  if(col.compare("azul") == 0)
  {
    std::cout<<blue;
  }
  else if(col.compare("rojo") == 0)
  {
    std::cout<<red;
  }
  else if(col.compare("verde") == 0)
  {
    std::cout<<green;
  }
  else if(col.compare("amarillo") == 0)
  {
    std::cout<<yellow;
  }
  else if(col.compare("magenta") == 0)
  {
    std::cout<<magenta;
  }
  else if(col.compare("cyan") == 0)
  {
    std::cout<<cyan;
  }
  
  std::cout<<"\nEstos son los territorios de: "<<jug<<"\n"<<reset;
  
  for(int i=0; i<6; i++)
  {
    std::cout<<"\n"<<contiP[i]->nombreContinente<<":\n";
    int conta = 1;
    std::list<Territorio>::iterator miIt;
    for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
    {
      if(jug.compare(miIt->duenio) == 0)
      {
        std::cout<<conta<<". "<<miIt->nombreTerritorio<<"\t-->\tTropas: "<<miIt->numTropas<<"\n";
        conta++;
      }
    }
  }
}

void Partida::mostrarTerritoriosEnemigos(std::string jug)
{
  std::cout<<"\nEstos son los territorios de los enemigos de: "<<jug<<"\n";
  
  for(int i=0; i<6; i++)
  {
    std::cout<<"\n"<<contiP[i]->nombreContinente<<":\n";
    int conta = 1;
    std::list<Territorio>::iterator miIt;
    for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
    {
      if(jug.compare(miIt->duenio) != 0)
      {
        std::list<Jugador>::iterator miIt2;
        for(miIt2 = jugadoresP.begin(); miIt2 != jugadoresP.end(); miIt2++)
        {
          if(miIt->duenio.compare(miIt2->nombreJugador) == 0)
          {
            std::string aux = miIt2->colorJugador;

            if(aux.compare("azul") == 0)
            {
              std::cout<<blue;
            }
            else if(aux.compare("rojo") == 0)
            {
              std::cout<<red;
            }
            else if(aux.compare("verde") == 0)
            {
              std::cout<<green;
            }
            else if(aux.compare("amarillo") == 0)
            {
              std::cout<<yellow;
            }
            else if(aux.compare("magenta") == 0)
            {
              std::cout<<magenta;
            }
            else if(aux.compare("cyan") == 0)
            {
              std::cout<<cyan;
            }
          }
        }

        std::cout<<conta<<". "<<miIt->nombreTerritorio<<"\t-->\tTropas: "<<miIt->numTropas<<"\n"<<reset;
        conta++;
      }
    }
  }
}

void Partida::turno()
{
  nuevasTropas();
  actualizarGrafo();
  
  std::string deci;
  bool sigue = false, sigue2 = false;

  while(sigue == false)
  {
    std::cout<<"Desea atacar? (si o no) ";
    std::cin>>deci;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(deci.compare("si") == 0)
    {
      atacar();
      sigue = true;
    }
    else if (deci.compare("no") == 0)
    {
      sigue = true;
    }
    else
      std::cout<<"\nRespuesta no reconocida, intente nuevamente\n\n";
  }

  std::string cont2;
  std::cout<<"\nPresione enter para continuar ";
  std::getline(std::cin, cont2);

  while(sigue2 == false)
  {
    std::cout<<"\nDesea fortificar? (si o no) ";
    std::cin>>deci;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(deci.compare("si") == 0)
    {
      fortificar();
      sigue2 = true;
    }
    else if (deci.compare("no") == 0)
    {
      std::cout<<"\n";
      sigue2 = true;
    }
    else
      std::cout<<"\nRespuesta no reconocida, intente nuevamente\n\n";
  }

  std::string turn = turnos.front();
  turnos.pop();

  int conta = 0;

  for(int i=0; i<6; i++)
  {
    std::list<Territorio>::iterator miIt;
    for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
    {
      if(turn.compare(miIt->duenio) == 0)
      {
        conta++;
      }
    }
  }

  if (conta > 0)
    turnos.push(turn);
  else
    std::cout<<"\nEl jugador "<<turn<<" ha sido eliminado\n\n";

  std::string turnSig = turnos.front();

  int conta2 = 0;

  for(int i=0; i<6; i++)
  {
    std::list<Territorio>::iterator miIt2;
    for (miIt2 = contiP[i]->territoriosC.begin(); miIt2 != contiP[i]->territoriosC.end(); miIt2++)
    {
      if(turnSig.compare(miIt2->duenio) == 0)
      {
        conta2++;
      }
    }
  }

  if (conta2 == 0)
  {
    turnos.pop();
    std::cout<<"\nEl jugador "<<turnSig<<" ha sido eliminado\n\n";
  }

}

void Partida::nuevasTropas()
{
  std::system("clear");
  std::cout<<"\nNuevas Tropas\n";
  
  //Calcular nuevas tropas 
  std::string jug = turnos.front();
  int conta = 0, nuevos;

  for(int i=0; i<6; i++)
  {
    std::list<Territorio>::iterator miIt;
    for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
    {
      if(jug.compare(miIt->duenio) == 0)
      {
        conta++;
      }
    }
  }

  nuevos = conta/3;

  std::cout<<"\nEl jugador "<<jug<<" tiene "<< nuevos<<" tropas nuevas\n";

  std::string col;
  std::list<Jugador>::iterator miIt2;

  for(miIt2 = jugadoresP.begin(); miIt2 != jugadoresP.end(); miIt2++)
  {
    if(jug.compare(miIt2->nombreJugador) == 0)
    {
      col = miIt2->colorJugador;
    }
  }

  mostrarTerritoriosPropios(jug, col);
  
  bool puede = false;
  std::string sele;

  //insertar las nuevas tropas
  if(nuevos > 0)
  {
    while (puede == false)
    {
      std::cout<<"\nEn que territorio desea poner mas tropas? ";
      std::getline(std::cin, sele);

      std::list<Territorio>::iterator miIt3;
      for(int i=0; i<6; i++)
      {
        for (miIt3 = contiP[i]->territoriosC.begin(); miIt3 != contiP[i]->territoriosC.end(); miIt3++)
        {
          if(sele.compare(miIt3->nombreTerritorio) == 0 && jug.compare(miIt3->duenio) == 0)
          {
            int aux = miIt3->numTropas;
            aux = aux + nuevos;
            miIt3->numTropas = aux;
            std::cout<<"\nEl territorio "<<sele<<" ahora tiene "<<miIt3->numTropas<<" tropas\n\n";

            puede = true;
          }
          else
          {
            
          }
        }
      }
      if(puede == false)
        std::cout<<"\nEl territorio "<<sele<<" no existe o no es tuyo\n";
    }
  }
  else
  {
    std::cout<<"\nEl jugador "<<jug<<" no tiene tropas nuevas\n\n";
  }
}

void Partida::atacar()
{
  std::system("clear");
  std::cout<<"\nAtacar\n";

  std::string jug = turnos.front();

  bool puede = false, puede2 = false, cancelar = false, puede3 = true;
  std::string sele, sele2;

  std::string col;
  std::list<Jugador>::iterator miIt2;

  for(miIt2 = jugadoresP.begin(); miIt2 != jugadoresP.end(); miIt2++)
  {
    if(jug.compare(miIt2->nombreJugador) == 0)
    {
      col = miIt2->colorJugador;
    }
  }

  mostrarTerritoriosPropios(jug, col);
  
  while (puede == false && cancelar == false)
  {
    std::cout<<"\nDesde que territorio desea atacar? ";
    std::getline(std::cin, sele);

    std::list<Territorio>::iterator miIt3;
    for(int i=0; i<6; i++)
    {
      for (miIt3 = contiP[i]->territoriosC.begin(); miIt3 != contiP[i]->territoriosC.end(); miIt3++)
      {
        if(sele.compare(miIt3->nombreTerritorio) == 0 && jug.compare(miIt3->duenio) == 0 && miIt3->numTropas > 1)
        {
          std::cout<<"\nEl jugador "<<miIt3->duenio<<" va a atacar desde "<<sele<<"\n";
          puede = true;
        }
        else if (sele.compare(miIt3->nombreTerritorio) == 0 && jug.compare(miIt3->duenio) == 0 && miIt3->numTropas < 2)
        {
          std::cout<<"\nEste territorio no puede atacar\n";
          cancelar = true;
        }
        else
        {
          
        }
      }
    }
    if(puede == false && cancelar == false)
      std::cout<<"\nEl territorio "<<sele<<" no existe o no es tuyo\n";
  }

  if(cancelar == true)
  {
    std::cout<<"\nSe ha cancelado el ataque\n";
  }
  else
  {
    mostrarTerritoriosEnemigos(jug);

    int atqIndice = grafo.indiceVertice(sele);

    std::cout<<"\nPuedes atacar a: \n";
    for(int i=0; i<grafo.matriz_adyacencia[atqIndice].size(); i++)
    {
      if(grafo.matriz_adyacencia[atqIndice][i] != 0)
      {
        std::cout<<"   - "<<grafo.vertices[i]<<"\n";
      }
    }

    while (puede2 == false)
    {
      std::cout<<"\nQue territorio desea atacar? ";
      std::getline(std::cin, sele2);

      std::list<Territorio>::iterator miIt4;
      for(int i=0; i<6; i++)
      {
        for (miIt4 = contiP[i]->territoriosC.begin(); miIt4 != contiP[i]->territoriosC.end(); miIt4++)
        {
          if(sele2.compare(miIt4->nombreTerritorio) == 0 && jug.compare(miIt4->duenio) != 0)
          {
            int indAtq = grafo.indiceVertice(sele);
            int indAtq2 = grafo.indiceVertice(sele2);

            if(grafo.matriz_adyacencia[indAtq][indAtq2] != 0)
            {
              std::cout<<"\nEl jugador "<<jug<<" va a atacar "<<sele2<<"\n";
              puede2 = true;
            }
            else
            {
              std::cout<<"\nEl territorio "<<sele2<<" no es vecino de "<<sele<<"\n";
              puede3 = false;
            }
          }
          else
          {
            
          }
        }
      }
      if(puede2 == false && puede3 == true)
        std::cout<<"\nEl territorio "<<sele2<<" no existe o es tuyo\n";
    }

    bool final = false;
    srand(time(0));

    int dadoAtq, dadoDef, numD;
    bool sig = false;

    while (sig == false)
    {
      std::cout<<"\nCuantos dados desea tirar? (1, 2 o 3) ";
      std::cin>>numD;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      if(numD == 1)
      {
        sig = true;
      }
      else if (numD == 2)
      {
        sig = true;
      }
      else if (numD == 3)
      {
        sig = true;
      }
      else
      {
        std::cout<<"\nRespuesta no reconocida, intente nuevamente\n";
      }
    }

    while(final == false)
    {
      int check;

      if(numD == 1)
      {
        dadoAtq = 1 + std::rand() % 6; // Genera un número entre 1 y 6
        std::cout<<"\nEl atacante saco un: "<<dadoAtq;
        dadoDef = 1 + std::rand() % 6;
        std::cout<<"\nEl defensor saco un: "<<dadoDef<<"\n\n";
      }
      else if (numD == 2)
      {
        dadoAtq = 1 + std::rand() % 12; // Genera un número entre 1 y 12
        std::cout<<"\nEl atacante saco un: "<<dadoAtq;
        dadoDef = 1 + std::rand() % 12;
        std::cout<<"\nEl defensor saco un: "<<dadoDef<<"\n\n";
      }
      else if (numD == 3)
      {
        dadoAtq = 1 + std::rand() % 18; // Genera un número entre 1 y 18
        std::cout<<"\nEl atacante saco un: "<<dadoAtq;
        dadoDef = 1 + std::rand() % 18;
        std::cout<<"\nEl defensor saco un: "<<dadoDef<<"\n\n";
      }

      if (dadoAtq>dadoDef)
      {
        std::list<Territorio>::iterator miIt5;
        for(int i=0; i<6; i++)
        {
          for (miIt5 = contiP[i]->territoriosC.begin(); miIt5 != contiP[i]->territoriosC.end(); miIt5++)
          {
            if(sele2.compare(miIt5->nombreTerritorio) == 0 && jug.compare(miIt5->duenio) != 0)
            {
              int aux = miIt5->numTropas;
              
              if(aux < numD+1)
                aux = 0;
              else 
                aux = aux - numD;

              miIt5->numTropas = aux;
              
              std::list<Territorio>::iterator miItX;
              for(int j=0; j<6; j++)
              {
                for (miItX = contiP[j]->territoriosC.begin(); miItX != contiP[j]->territoriosC.end(); miItX++)
                {
                  if(sele.compare(miItX->nombreTerritorio) == 0 && jug.compare(miItX->duenio) == 0)
                  {
                    std::cout<<"El territorio "<<miItX->nombreTerritorio<<" ahora tiene "<<miItX->numTropas<<" tropas\n";
                  }
                }
              }

              std::cout<<"El territorio "<<miIt5->nombreTerritorio<<" ahora tiene "<<miIt5->numTropas<<" tropas\n";
              
              if (aux == 0)
              {
                miIt5->duenio = jug;
                miIt5->numTropas = 1;
                std::cout<<"\nEl territorio "<<miIt5->nombreTerritorio<<" ahora es del jugador "<<jug<<"\n";
                final = true;
              }
            }
            else
            {
              
            }
          }
        }
      }
      else if (dadoAtq<dadoDef)
      {
        std::list<Territorio>::iterator miIt6;
        for(int i=0; i<6; i++)
        {
          for (miIt6 = contiP[i]->territoriosC.begin(); miIt6 != contiP[i]->territoriosC.end(); miIt6++)
          {
            if(sele.compare(miIt6->nombreTerritorio) == 0 && jug.compare(miIt6->duenio) == 0)
            {
              int aux = miIt6->numTropas;

              if(aux < numD+1)
                aux = 0;
              else 
                aux = aux - numD;
              
              check = aux;
              miIt6->numTropas = aux;
              
              std::cout<<"El territorio "<<miIt6->nombreTerritorio<<" ahora tiene "<<miIt6->numTropas<<" tropas\n";

              std::list<Territorio>::iterator miItX;
              for(int j=0; j<6; j++)
              {
                for (miItX = contiP[j]->territoriosC.begin(); miItX != contiP[j]->territoriosC.end(); miItX++)
                {
                  if(sele2.compare(miItX->nombreTerritorio) == 0 && jug.compare(miItX->duenio) != 0)
                  {
                    std::cout<<"El territorio "<<miItX->nombreTerritorio<<" ahora tiene "<<miItX->numTropas<<" tropas\n";
                  }
                }
              }

              if (aux == 1)
              {
                std::cout<<"\nEl territorio "<<miIt6->nombreTerritorio<<" ya no puede seguir atacando \n\n";
                final = true;
              }
            }
            else
            {
              
            }
          }
        }
      }
      else if(dadoAtq == dadoDef)
      {
        std::list<Territorio>::iterator miIt7;
        for(int i=0; i<6; i++)
        {
          for (miIt7 = contiP[i]->territoriosC.begin(); miIt7 != contiP[i]->territoriosC.end(); miIt7++)
          {
            if(sele.compare(miIt7->nombreTerritorio) == 0 && jug.compare(miIt7->duenio) == 0)
            {
              int aux = miIt7->numTropas;
              
              if(aux < numD+1)
                aux = 0;
              else 
                aux = aux - numD;
              
              check = aux;
              miIt7->numTropas = aux;

              std::cout<<"El territorio "<<miIt7->nombreTerritorio<<" ahora tiene "<<miIt7->numTropas<<" tropas\n";

              std::list<Territorio>::iterator miItX;
              for(int j=0; j<6; j++)
              {
                for (miItX = contiP[j]->territoriosC.begin(); miItX != contiP[j]->territoriosC.end(); miItX++)
                {
                  if(sele2.compare(miItX->nombreTerritorio) == 0 && jug.compare(miItX->duenio) != 0)
                  {
                    std::cout<<"El territorio "<<miItX->nombreTerritorio<<" ahora tiene "<<miItX->numTropas<<" tropas\n";
                  }
                }
              }

              if (aux == 1)
              {
                std::cout<<"\nEl territorio "<<miIt7->nombreTerritorio<<" ya no puede seguir atacando \n";
                final = true;
              }
            }
            else
            {
              
            }
          }
        }
      }

      std::string deci2;
      bool sigue2 = false;

      if (final == false)
      {
        while(sigue2 == false)
        {
          std::cout<<"\nDesea terminar el ataque? (si o no) ";
          std::cin>>deci2;
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

          if(deci2.compare("si") == 0)
          {
            final = true;
            sigue2 = true;
          }
          else if (deci2.compare("no") == 0)
          {
            if (check == 1)
            {
              std::cout<<"\nEl territorio "<<sele<<" ya no puede seguir atacando \n\n";
              sigue2 = false; 
            }
            else 
              sigue2 = true;
          }
          else
            std::cout<<"\nRespuesta no reconocida, intente nuevamente\n";
        }
      }
    }
  }
}

void Partida::fortificar()
{
  std::system("clear");
  std::cout<<"\nFortificar\n";

  std::string jug = turnos.front();

  bool puede = false, puede2 = false, pocas = false;
  std::string sele, sele2;

  std::string col;
  std::list<Jugador>::iterator miIt2;

  for(miIt2 = jugadoresP.begin(); miIt2 != jugadoresP.end(); miIt2++)
  {
    if(jug.compare(miIt2->nombreJugador) == 0)
    {
      col = miIt2->colorJugador;
    }
  }

  std::list<Territorio>::iterator miIt3;
  int conta = 0;

  for(int i=0; i<6; i++)
  {
    for(miIt3 = contiP[i]->territoriosC.begin(); miIt3 != contiP[i]->territoriosC.end(); miIt3++)
    {
      if(jug.compare(miIt3->duenio) == 0)
      {
        conta++;
      }
    }
  }

  if(conta == 1)
  {
    puede = true;
    std::cout<<"\nEl jugador "<<jug<<" solo tiene un territorio, no puede Fortificar\n\n";
  }

  else 
  {
      mostrarTerritoriosPropios(jug, col);
    
    while (puede == false)
    {
      std::cout<<"\nDesde que territorio desea Fortificar? ";
      std::getline(std::cin, sele);

      pocas = false;

      std::list<Territorio>::iterator miIt;
      for(int i=0; i<6; i++)
      {
        for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
        {
          if(sele.compare(miIt->nombreTerritorio) == 0 && jug.compare(miIt->duenio) == 0 && miIt->numTropas > 1)
          {
            std::cout<<"\nEl jugador "<<miIt->duenio<<" va a Fortificar desde "<<sele<<"\n";

            puede = true;
          }
          else if (sele.compare(miIt->nombreTerritorio) == 0 && jug.compare(miIt->duenio) == 0 && miIt->numTropas < 2)
          {
            pocas = true;
          }
        }
      }
      if(puede == false)
      {
        if (pocas == true)
          std::cout<<"\nEste territorio no puede Fortificar porque solo tiene 1 tropa\n";
        else
          std::cout<<"\nEl territorio "<<sele<<" no existe o no es tuyo\n";
      }
    }
    
    while (puede2 == false)
    {
      std::cout<<"\nQue territorio desea Fortificar? ";
      std::getline(std::cin, sele2);

      std::list<Territorio>::iterator miIt2;
      for(int i=0; i<6; i++)
      {
        for (miIt2 = contiP[i]->territoriosC.begin(); miIt2 != contiP[i]->territoriosC.end(); miIt2++)
        {
          if(sele2.compare(miIt2->nombreTerritorio) == 0 && jug.compare(miIt2->duenio) == 0)
          {
            std::cout<<"\nEl jugador "<<miIt2->duenio<<" va a fortificar "<<sele2<<"\n";
            puede2 = true;
          }
          else
          {
            
          }
        }
      }
      if(puede2 == false)
        std::cout<<"\nEl territorio "<<sele2<<" no existe o es tuyo\n";
    }

    // 

    bool puede3 = false;
    int trop;
    
    while (puede3 == false)
    {
      std::cout<<"\nCuantas tropas desea mandar? ";
      std::cin>>trop;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::list<Territorio>::iterator miIt3;
      for(int i=0; i<6; i++)
      {
        for (miIt3 = contiP[i]->territoriosC.begin(); miIt3 != contiP[i]->territoriosC.end(); miIt3++)
        {
          if(sele.compare(miIt3->nombreTerritorio) == 0 && trop < miIt3->numTropas)
          {
            std::list<Territorio>::iterator miIt4;
            for(int i=0; i<6; i++)
            {
              for (miIt4 = contiP[i]->territoriosC.begin(); miIt4 != contiP[i]->territoriosC.end(); miIt4++)
              {
                if(sele2.compare(miIt4->nombreTerritorio) == 0)
                {
                  int quita = miIt3->numTropas;
                  quita = quita - trop;
                  miIt3->numTropas = quita;

                  int da = miIt4->numTropas;
                  da = da + trop;
                  miIt4->numTropas = da;

                  puede3 = true;

                  std::cout<<"\nEl territorio "<<miIt3->nombreTerritorio<<" quedo con "<<miIt3->numTropas<<" tropas";
                  std::cout<<"\nEl territorio "<<miIt4->nombreTerritorio<<" quedo con "<<miIt4->numTropas<<" tropas\n\n";
                }
              }
            }   
          }
        }
      }

      if (puede3 == false)
        std::cout<<"\nNo se han podido enviar tropas, intente nuevamente\n";
    }
  }
}

bool Partida::guardarNormal(std::string nombreArchivo)
{
  bool guardado = false;

  std::ofstream archivo(nombreArchivo);

  if(archivo.is_open())
  {
    archivo<<"- Numero de jugadores: "<<jugadoresP.size()<<"\n";

    archivo<<"- Territorios\n";
    for(int i=0; i<6; i++)
    {
      archivo<<i<<") "<<contiP[i]->nombreContinente<<"\n";
      std::list<Territorio>::iterator miIt;
      for (miIt = contiP[i]->territoriosC.begin(); miIt != contiP[i]->territoriosC.end(); miIt++)
      {
        archivo<<miIt->nombreTerritorio<<","<<miIt->duenio<<","<<miIt->numTropas<<","<<miIt->tomado<<"\n";
      }
    }

    archivo<<"- Jugadores\n";
    std::list<Jugador>::iterator miIt2;
    for(miIt2 = jugadoresP.begin(); miIt2 != jugadoresP.end(); miIt2++)
    {
      archivo<<miIt2->nombreJugador<<","<<miIt2->colorJugador<<","<<miIt2->cantiTropas<<"\n";
    }

    archivo<<"- Turnos\n";
    while(!turnos.empty())
    {
      archivo<<turnos.front();
      turnos.pop();

      if (!turnos.empty()) 
      {
        archivo << "\n";
      }
    }

    guardado = true;
    archivo.close();
  }
  else
  {
    guardado = false;
  }

  return guardado;
}

void Partida::crearGrafo()
{
  //Creamos los nodos
  grafo.insertarVertice("Alaska");
  grafo.insertarVertice("Alberta");
  grafo.insertarVertice("America Central");
  grafo.insertarVertice("Estados Unidos Orientales");
  grafo.insertarVertice("Groenlandia");
  grafo.insertarVertice("Territorio Noroccidental");
  grafo.insertarVertice("Ontario");
  grafo.insertarVertice("Quebec");
  grafo.insertarVertice("Estados Unidos Occidentales");
  grafo.insertarVertice("Argentina");
  grafo.insertarVertice("Brasil");
  grafo.insertarVertice("Peru");
  grafo.insertarVertice("Venezuela");
  grafo.insertarVertice("Gran Bretana");
  grafo.insertarVertice("Islandia");
  grafo.insertarVertice("Europa del Norte");
  grafo.insertarVertice("Escandinavia");
  grafo.insertarVertice("Europa del Sur");
  grafo.insertarVertice("Ucrania");
  grafo.insertarVertice("Europa Occidental");
  grafo.insertarVertice("Congo");
  grafo.insertarVertice("Africa Oriental");
  grafo.insertarVertice("Egipto");
  grafo.insertarVertice("Madagascar");
  grafo.insertarVertice("Africa del Norte");
  grafo.insertarVertice("Africa del Sur");
  grafo.insertarVertice("Afganistan");
  grafo.insertarVertice("China");
  grafo.insertarVertice("India");
  grafo.insertarVertice("Irkutsk");
  grafo.insertarVertice("Japon");
  grafo.insertarVertice("Kamchatka");
  grafo.insertarVertice("Medio Oriente");
  grafo.insertarVertice("Mongolia");
  grafo.insertarVertice("Siam");
  grafo.insertarVertice("Siberia");
  grafo.insertarVertice("Ural");
  grafo.insertarVertice("Yakutsk");
  grafo.insertarVertice("Australia Oriental");
  grafo.insertarVertice("Indonesia");
  grafo.insertarVertice("Nueva Guinea");
  grafo.insertarVertice("Australia Occidental");

  //Conectamos los nodos
  grafo.conectarVertices("Alaska", "Alberta", 1);
  grafo.conectarVertices("Alaska", "Territorio Noroccidental", 1);
  grafo.conectarVertices("Alaska", "Kamchatka", 1);

  grafo.conectarVertices("Alberta", "Alaska", 1);
  grafo.conectarVertices("Alberta", "Territorio Noroccidental", 1);
  grafo.conectarVertices("Alberta", "Ontario", 1);
  grafo.conectarVertices("Alberta", "Estados Unidos Occidentales", 1);

  grafo.conectarVertices("America Central", "Estados Unidos Orientales", 1);
  grafo.conectarVertices("America Central", "Estados Unidos Occidentales", 1);
  grafo.conectarVertices("America Central", "Venezuela", 1);

  grafo.conectarVertices("Estados Unidos Orientales", "America Central", 1);
  grafo.conectarVertices("Estados Unidos Orientales", "Ontario", 1);
  grafo.conectarVertices("Estados Unidos Orientales", "Quebec", 1);
  grafo.conectarVertices("Estados Unidos Orientales", "Estados Unidos Occidentales", 1);

  grafo.conectarVertices("Groenlandia", "Territorio Noroccidental", 1);
  grafo.conectarVertices("Groenlandia", "Ontario", 1);
  grafo.conectarVertices("Groenlandia", "Quebec", 1);
  grafo.conectarVertices("Groenlandia", "Islandia", 1);

  grafo.conectarVertices("Territorio Noroccidental", "Alaska", 1);
  grafo.conectarVertices("Territorio Noroccidental", "Alberta", 1);
  grafo.conectarVertices("Territorio Noroccidental", "Groenlandia", 1);
  grafo.conectarVertices("Territorio Noroccidental", "Ontario", 1);

  grafo.conectarVertices("Ontario", "Alberta", 1);
  grafo.conectarVertices("Ontario", "Estados Unidos Orientales", 1);
  grafo.conectarVertices("Ontario", "Groenlandia", 1);
  grafo.conectarVertices("Ontario", "Territorio Noroccidental", 1);
  grafo.conectarVertices("Ontario", "Quebec", 1);
  grafo.conectarVertices("Ontario", "Estados Unidos Occidentales", 1);

  grafo.conectarVertices("Quebec", "Estados Unidos Orientales", 1);
  grafo.conectarVertices("Quebec", "Groenlandia", 1);
  grafo.conectarVertices("Quebec", "Ontario", 1);

  grafo.conectarVertices("Estados Unidos Occidentales", "Alberta", 1);
  grafo.conectarVertices("Estados Unidos Occidentales", "America Central", 1);
  grafo.conectarVertices("Estados Unidos Occidentales", "Estados Unidos Orientales", 1);
  grafo.conectarVertices("Estados Unidos Occidentales", "Ontario", 1);

  grafo.conectarVertices("Argentina", "Brasil", 1);
  grafo.conectarVertices("Argentina", "Peru", 1);

  grafo.conectarVertices("Brasil", "Argentina", 1);
  grafo.conectarVertices("Brasil", "Peru", 1);
  grafo.conectarVertices("Brasil", "Venezuela", 1);
  grafo.conectarVertices("Brasil", "Africa del Norte", 1);

  grafo.conectarVertices("Peru", "Argentina", 1);
  grafo.conectarVertices("Peru", "Brasil", 1);
  grafo.conectarVertices("Peru", "Venezuela", 1);

  grafo.conectarVertices("Venezuela", "America Central", 1);
  grafo.conectarVertices("Venezuela", "Brasil", 1);
  grafo.conectarVertices("Venezuela", "Peru", 1);

  grafo.conectarVertices("Gran Bretana", "Islandia", 1);
  grafo.conectarVertices("Gran Bretana", "Europa del Norte", 1);
  grafo.conectarVertices("Gran Bretana", "Escandinavia", 1);
  grafo.conectarVertices("Gran Bretana", "Europa Occidental", 1);

  grafo.conectarVertices("Islandia", "Groenlandia", 1);
  grafo.conectarVertices("Islandia", "Gran Bretana", 1);
  grafo.conectarVertices("Islandia", "Escandinavia", 1);

  grafo.conectarVertices("Europa del Norte", "Gran Bretana", 1);
  grafo.conectarVertices("Europa del Norte", "Escandinavia", 1);
  grafo.conectarVertices("Europa del Norte", "Ucrania", 1);
  grafo.conectarVertices("Europa del Norte", "Europa del Sur", 1);
  grafo.conectarVertices("Europa del Norte", "Europa Occidental", 1);

  grafo.conectarVertices("Escandinavia", "Gran Bretana", 1);
  grafo.conectarVertices("Escandinavia", "Islandia", 1);
  grafo.conectarVertices("Escandinavia", "Europa del Norte", 1);
  grafo.conectarVertices("Escandinavia", "Ucrania", 1);

  grafo.conectarVertices("Europa del Sur", "Europa del Norte", 1);
  grafo.conectarVertices("Europa del Sur", "Ucrania", 1);
  grafo.conectarVertices("Europa del Sur", "Europa Occidental", 1);
  grafo.conectarVertices("Europa del Sur", "Egipto", 1);
  grafo.conectarVertices("Europa del Sur", "Africa del Norte", 1);
  grafo.conectarVertices("Europa del Sur", "Medio Oriente", 1);

  grafo.conectarVertices("Ucrania", "Europa del Norte", 1);
  grafo.conectarVertices("Ucrania", "Escandinavia", 1);
  grafo.conectarVertices("Ucrania", "Europa del Sur", 1);
  grafo.conectarVertices("Ucrania", "Afganistan", 1);
  grafo.conectarVertices("Ucrania", "Medio Oriente", 1);
  grafo.conectarVertices("Ucrania", "Ural", 1);

  grafo.conectarVertices("Europa Occidental", "Gran Bretana", 1);
  grafo.conectarVertices("Europa Occidental", "Europa del Norte", 1);
  grafo.conectarVertices("Europa Occidental", "Europa del Sur", 1);
  grafo.conectarVertices("Europa Occidental", "Africa del Norte", 1);

  grafo.conectarVertices("Congo", "Africa del Norte", 1);
  grafo.conectarVertices("Congo", "Africa Oriental", 1);
  grafo.conectarVertices("Congo", "Africa del Sur", 1);

  grafo.conectarVertices("Africa Oriental", "Congo", 1);
  grafo.conectarVertices("Africa Oriental", "Egipto", 1);
  grafo.conectarVertices("Africa Oriental", "Madagascar", 1);
  grafo.conectarVertices("Africa Oriental", "Africa del Norte", 1);
  grafo.conectarVertices("Africa Oriental", "Africa del Sur", 1);

  grafo.conectarVertices("Egipto", "Europa del Sur", 1);
  grafo.conectarVertices("Egipto", "Africa Oriental", 1);
  grafo.conectarVertices("Egipto", "Africa del Norte", 1);
  grafo.conectarVertices("Egipto", "Medio Oriente", 1);

  grafo.conectarVertices("Madagascar", "Africa Oriental", 1);
  grafo.conectarVertices("Madagascar", "Africa del Sur", 1);

  grafo.conectarVertices("Africa del Norte", "Brasil", 1);
  grafo.conectarVertices("Africa del Norte", "Europa del Sur", 1);
  grafo.conectarVertices("Africa del Norte", "Egipto", 1);
  grafo.conectarVertices("Africa del Norte", "Congo", 1);
  grafo.conectarVertices("Africa del Norte", "Africa Oriental", 1);

  grafo.conectarVertices("Africa del Sur", "Congo", 1);
  grafo.conectarVertices("Africa del Sur", "Africa Oriental", 1);
  grafo.conectarVertices("Africa del Sur", "Madagascar", 1);

  grafo.conectarVertices("Afganistan", "Ucrania", 1);
  grafo.conectarVertices("Afganistan", "China", 1);
  grafo.conectarVertices("Afganistan", "India", 1);
  grafo.conectarVertices("Afganistan", "Medio Oriente", 1);
  grafo.conectarVertices("Afganistan", "Ural", 1);

  grafo.conectarVertices("China", "Afganistan", 1);
  grafo.conectarVertices("China", "India", 1);
  grafo.conectarVertices("China", "Mongolia", 1);
  grafo.conectarVertices("China", "Siam", 1);
  grafo.conectarVertices("China", "Siberia", 1);
  grafo.conectarVertices("China", "Ural", 1);

  grafo.conectarVertices("India", "Afganistan", 1);
  grafo.conectarVertices("India", "China", 1);
  grafo.conectarVertices("India", "Medio Oriente", 1);
  grafo.conectarVertices("India", "Siam", 1);

  grafo.conectarVertices("Irkutsk", "Kamchatka", 1);
  grafo.conectarVertices("Irkutsk", "Mongolia", 1);
  grafo.conectarVertices("Irkutsk", "Siberia", 1);
  grafo.conectarVertices("Irkutsk", "Yakutsk", 1);

  grafo.conectarVertices("Japon", "Kamchatka", 1);
  grafo.conectarVertices("Japon", "Mongolia", 1);

  grafo.conectarVertices("Kamchatka", "Alaska", 1);
  grafo.conectarVertices("Kamchatka", "Irkutsk", 1);
  grafo.conectarVertices("Kamchatka", "Japon", 1);
  grafo.conectarVertices("Kamchatka", "Mongolia", 1);
  grafo.conectarVertices("Kamchatka", "Yakutsk", 1);

  grafo.conectarVertices("Medio Oriente", "Egipto", 1);
  grafo.conectarVertices("Medio Oriente", "Europa del Sur", 1);
  grafo.conectarVertices("Medio Oriente", "India", 1);
  grafo.conectarVertices("Medio Oriente", "Afganistan", 1);
  grafo.conectarVertices("Medio Oriente", "Ucrania", 1);

  grafo.conectarVertices("Mongolia", "China", 1);
  grafo.conectarVertices("Mongolia", "Irkutsk", 1);
  grafo.conectarVertices("Mongolia", "Japon", 1);
  grafo.conectarVertices("Mongolia", "Kamchatka", 1);
  grafo.conectarVertices("Mongolia", "Siberia", 1);

  grafo.conectarVertices("Siam", "China", 1);
  grafo.conectarVertices("Siam", "India", 1);
  grafo.conectarVertices("Siam", "Indonesia", 1);

  grafo.conectarVertices("Siberia", "Irkutsk", 1);
  grafo.conectarVertices("Siberia", "Mongolia", 1);
  grafo.conectarVertices("Siberia", "Ural", 1);
  grafo.conectarVertices("Siberia", "Yakutsk", 1);

  grafo.conectarVertices("Ural", "Afganistan", 1);
  grafo.conectarVertices("Ural", "China", 1);
  grafo.conectarVertices("Ural", "Europa del Norte", 1);
  grafo.conectarVertices("Ural", "Siberia", 1);

  grafo.conectarVertices("Yakutsk", "Irkutsk", 1);
  grafo.conectarVertices("Yakutsk", "Kamchatka", 1);
  grafo.conectarVertices("Yakutsk", "Siberia", 1);

  grafo.conectarVertices("Australia Oriental", "Nueva Guinea", 1);
  grafo.conectarVertices("Australia Oriental", "Australia Occidental", 1);

  grafo.conectarVertices("Indonesia", "Siam", 1);
  grafo.conectarVertices("Indonesia", "Nueva Guinea", 1);
  grafo.conectarVertices("Indonesia", "Australia Occidental", 1);

  grafo.conectarVertices("Nueva Guinea", "Australia Oriental", 1);
  grafo.conectarVertices("Nueva Guinea", "Indonesia", 1);
  grafo.conectarVertices("Nueva Guinea", "Australia Occidental", 1);

  grafo.conectarVertices("Australia Occidental", "Australia Oriental", 1);
  grafo.conectarVertices("Australia Occidental", "Indonesia", 1);
  grafo.conectarVertices("Australia Occidental", "Nueva Guinea", 1);

  //grafo.imprimirMatriz();
}

void Partida::actualizarGrafo()
{
  for(int i=0; i<grafo.matriz_adyacencia.size(); i++)
  {
    for(int j=0; j<grafo.matriz_adyacencia[i].size(); j++)
    {
      if(grafo.matriz_adyacencia[i][j] != 0)
      {
        int aux;

        std::list<Territorio>::iterator miIt;
        for(int x=0; x<6; x++)
        {
          for(miIt=contiP[x]->territoriosC.begin(); miIt!=contiP[x]->territoriosC.end(); miIt++)
          {
            if(grafo.vertices[j].compare(miIt->nombreTerritorio) == 0)
            {
              aux = miIt->numTropas;
            }
          }
        }

        grafo.matriz_adyacencia[i][j] = aux;
      }
    }
  }
  //grafo.imprimirMatriz();
}

void Partida::costoconquista(std::string paisAtacado)
{
  actualizarGrafo();

  std::string jugador = turnos.front();
  std::vector<std::string> paisesAtacantes;
  bool puede = true;

  std::list<Territorio>::iterator miIt;
  for(int i=0; i<6; i++)
  {
    for(miIt=contiP[i]->territoriosC.begin(); miIt!=contiP[i]->territoriosC.end(); miIt++)
    {
      if(miIt->nombreTerritorio.compare(paisAtacado) == 0 && miIt->duenio.compare(jugador) == 0)
      {
        std::cout<<"\nEl jugador ";
        std::list<Jugador>::iterator miIt3;
        for (miIt3 = jugadoresP.begin(); miIt3 != jugadoresP.end(); miIt3++)
        {      
          if(jugador.compare(miIt3->nombreJugador) == 0)
          {                
            std::string aux2 = miIt3->colorJugador;

            if(aux2.compare("azul") == 0)
            {
              std::cout<<blue;
            }
            else if(aux2.compare("rojo") == 0)
            {
              std::cout<<red;
            }
            else if(aux2.compare("verde") == 0)
            {
              std::cout<<green;
            }
            else if(aux2.compare("amarillo") == 0)
            {
              std::cout<<yellow;
            }
            else if(aux2.compare("magenta") == 0)
            {
              std::cout<<magenta;
            }
            else if(aux2.compare("cyan") == 0)
            {
              std::cout<<cyan;
            }
          }
        }
        std::cout<<jugador<<reset;
        std::cout<<" es dueño de "<<paisAtacado<<" entonces no lo puede atacar\n\n";
        puede = false;
      }
    }
  }

  bool encontrado = false;

  for(int i=0; i<grafo.vertices.size(); i++)
  {
    if(paisAtacado.compare(grafo.vertices[i]) == 0)
    {
      encontrado = true;
    }
  }

  if(encontrado == false)
  {
    std::cout<<"\nEl territorio "<<red<<paisAtacado<<reset<<" no existe\n\n";
    puede = false;
  }
  

  if(puede == true)
  {
    std::list<Territorio>::iterator miIt2;
    for(int i=0; i<6; i++)
    {
      for(miIt2=contiP[i]->territoriosC.begin(); miIt2!=contiP[i]->territoriosC.end(); miIt2++)
      {
        if(miIt2->duenio.compare(jugador) == 0)
        {
          paisesAtacantes.push_back(miIt2->nombreTerritorio);
        }
      }
    }

    std::vector< std::vector< std::pair<std::string, std::string> > > dijkPaises;

    for(int i=0; i<paisesAtacantes.size(); i++)
    {
      std::vector< std::pair<std::string, std::string> > dijkPais = grafo.dijkstra(paisesAtacantes[i]);
      
      std::stack< std::pair<std::string, std::string> > pilaDijk;
      std::vector< std::pair<std::string, std::string> > dijkFinal;

      bool terminado = false;
      std::string nombreDes = paisAtacado;

      while(terminado == false)
      {
        for(int i=0; i<dijkPais.size(); i++)
        {
          if(dijkPais[i].second.compare(nombreDes) == 0)
          {
            nombreDes = dijkPais[i].first;
            pilaDijk.push(dijkPais[i]);
          }
        }

        if(nombreDes.compare(paisesAtacantes[i]) == 0)
        {
          terminado = true;
        }
      }

      while(!pilaDijk.empty())
      {
        dijkFinal.push_back(pilaDijk.top());
        pilaDijk.pop();
      }

      dijkPaises.push_back(dijkFinal);
    }

    int minPos = 0;

    for (int i = 1; i < dijkPaises.size(); i++) 
    {
        if (dijkPaises[i].size() < dijkPaises[minPos].size()) 
        {
            minPos = i;
        }
    }

    std::cout<<"\nEs el turno de ";
    std::list<Jugador>::iterator miIt4;
    for (miIt4 = jugadoresP.begin(); miIt4 != jugadoresP.end(); miIt4++)
    {      
      if(jugador.compare(miIt4->nombreJugador) == 0)
      {                
        std::string aux2 = miIt4->colorJugador;

        if(aux2.compare("azul") == 0)
        {
          std::cout<<blue;
        }
        else if(aux2.compare("rojo") == 0)
        {
          std::cout<<red;
        }
        else if(aux2.compare("verde") == 0)
        {
          std::cout<<green;
        }
        else if(aux2.compare("amarillo") == 0)
        {
          std::cout<<yellow;
        }
        else if(aux2.compare("magenta") == 0)
        {
          std::cout<<magenta;
        }
        else if(aux2.compare("cyan") == 0)
        {
          std::cout<<cyan;
        }
      }
    }
    std::cout<<jugador<<reset;
    std::cout<<"\nEl camino para conquistar "<<paisAtacado<<" es: ";
    for(int i=0; i<dijkPaises[minPos].size(); i++)
    {
      std::cout<<dijkPaises[minPos][i].first<<" -> ";
    }
    std::cout<<paisAtacado<<"\n";
    
    int costo = 0;

    for(int i=0; i<dijkPaises[minPos].size(); i++)
    {
      std::string primero = dijkPaises[minPos][i].first;
      std::string segundo = dijkPaises[minPos][i].second;
      int aux = grafo.valorConexion(primero, segundo);

      costo = costo + aux;
    }
    std::cout<<"El costo para conquistar "<<paisAtacado<<" es: "<<costo<<"\n\n";
  
  }
}

void Partida::conquistaMasBarata(std::string jugador)
{
  actualizarGrafo();

  std::vector < std::pair <std::string, int> > paisesCostos;

  for(int i=0; i<grafo.matriz_adyacencia.size(); i++)
  {
    for(int x=0; x<6; x++)
    {
      std::list<Territorio>::iterator miIt;
      for(miIt=contiP[x]->territoriosC.begin(); miIt!=contiP[x]->territoriosC.end(); miIt++)
      {
        if(grafo.vertices[i].compare(miIt->nombreTerritorio) == 0 && jugador.compare(miIt->duenio) == 0)
        {
          for(int j=0; j<grafo.matriz_adyacencia[i].size(); j++)
          {
            if(grafo.matriz_adyacencia[i][j] != 0)
            {
              std::list<Territorio>::iterator miIt2;
              for(int y=0; y<6; y++)
              {
                for(miIt2=contiP[y]->territoriosC.begin(); miIt2!=contiP[y]->territoriosC.end(); miIt2++)
                {
                  if(grafo.vertices[j].compare(miIt2->nombreTerritorio) == 0 && jugador.compare(miIt2->duenio) != 0)
                  {
                    paisesCostos.push_back(std::make_pair(grafo.vertices[j], grafo.matriz_adyacencia[i][j]));
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::sort(paisesCostos.begin(), paisesCostos.end(), [](const std::pair <std::string, int> a, const std::pair <std::string, int> b){
        return a.second < b.second;
    });

  std::cout<<"\nEs el turno de ";
  std::list<Jugador>::iterator miIt3;
  for (miIt3 = jugadoresP.begin(); miIt3 != jugadoresP.end(); miIt3++)
  {      
    if(jugador.compare(miIt3->nombreJugador) == 0)
    {                
      std::string aux2 = miIt3->colorJugador;

      if(aux2.compare("azul") == 0)
      {
        std::cout<<blue;
      }
      else if(aux2.compare("rojo") == 0)
      {
        std::cout<<red;
      }
      else if(aux2.compare("verde") == 0)
      {
        std::cout<<green;
      }
      else if(aux2.compare("amarillo") == 0)
      {
        std::cout<<yellow;
      }
      else if(aux2.compare("magenta") == 0)
      {
        std::cout<<magenta;
      }
      else if(aux2.compare("cyan") == 0)
      {
        std::cout<<cyan;
      }
    }
  }
        
  std::cout<<jugador<<reset;
  std::cout<<"\nEl pais mas barato para conquistar es: ";
  std::cout<<paisesCostos[0].first<<", teniendo un costo de "<<paisesCostos[0].second<<" tropas\n";

  int j = grafo.indiceVertice(paisesCostos[0].first);

  for(int i=0; i<grafo.matriz_adyacencia.size(); i++)
  {
    if(grafo.matriz_adyacencia[i][j] != 0)
    {
      for(int x=0; x<6; x++)
      {
        std::list<Territorio>::iterator miIt4;
        for(miIt4=contiP[x]->territoriosC.begin(); miIt4!=contiP[x]->territoriosC.end(); miIt4++)
        {
          if(grafo.vertices[i].compare(miIt4->nombreTerritorio) == 0 && jugador.compare(miIt4->duenio) == 0)
          {
            std::cout<<"Lo puedes atacar desde "<<grafo.vertices[i]<<"\n";
          }
        }
      }
    }
  }

  std::cout<<"\n";
 
}