#include "Partida.h"
#include <iostream>
#include <limits>
#include <fstream>

// cosas que se necesitan para cambiar el color del texto
#define reset "\033[0m"
#define blue "\033[34m" 
#define red "\033[31m" 
#define green "\033[32m" 
#define yellow "\033[33m" 
#define magenta "\033[35m"
#define cyan "\033[36m"

Partida::Partida(int idP) : jugadoresP(), cartasP(), turnos()
{
  idPartida = idP;

  contiP[0] = new Continente("America Del Norte"); //llenar el arreglo con los continentes 
  contiP[1] = new Continente("America Del Sur");
  contiP[2] = new Continente("Europa");
  contiP[3] = new Continente("Africa");
  contiP[4] = new Continente("Asia");
  contiP[5] = new Continente("Australia");

  int num, numTrop;
  
  do
  {
  std::cout<<"\nIngrese la cantidad de jugadores: ";
  std::cin>>num;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  } while (num < 2 || num > 6);

  if (num == 2)
  {
    numTrop == 40;  
  }

  if (num == 3)
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
        std::cout<<"\nEl territorio "<<sele<<" no existe o no es tuyo\n\n";
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

  bool puede = false, puede2 = false, cancelar = false;
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
  
  while (puede == false)
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
    if(puede == false)
      std::cout<<"\nEl territorio "<<sele<<" no existe o no es tuyo\n";
  }

  if(cancelar == true)
  {
    std::cout<<"\nSe ha cancelado el ataque";
  }
  else
  {
    mostrarTerritoriosEnemigos(jug);
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
            std::cout<<"\nEl jugador "<<jug<<" va a atacar "<<sele2<<"\n";

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