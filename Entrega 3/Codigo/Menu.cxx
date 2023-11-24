#include "Menu.h"

#include <iostream>
#include <fstream>
#include "ArbolHuffman.h"
#include "Caracter.h"

// cosas que se necesitan para cambiar el color del texto
#define reset "\033[0m"
#define blue "\033[34m" 
#define red "\033[31m" 
#define green "\033[92m" 
#define yellow "\033[93m" 
#define magenta "\033[35m"
#define cyan "\033[96m"


void Menu::mapamundi()
{

  // Diseño de un mapa del mundo para portada

  std::cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
      std::cout<<cyan<<"\n Bienvenido a RISK!!"<<reset;

  std::cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";


  std::cout<<green<<"\n\t                                                      \t";
  std::cout<<"\n\t               *    ,*** *******.         ,       .      *       \t";           
  std::cout<<"\n\t    ****     *.    **  ,*******.     .       *   ******** *********** \t";       
  std::cout<<"\n\t   **********,** * .*    *****                  *,*******************   \t";    
  std::cout<<"\n\t  ,,*,,**********,   **  ***/         ****  ***.****************** *     \t";   
  std::cout<<"\n\t       .*******,   **    *          ** *,**********************    /    \t";    
  std::cout<<"\n\t       **********.****              .  ********.**/****.*********       \t";    
  std::cout<<"\n\t       ************,*.            ******,,.** ******,**********. .       \t";   
  std::cout<<"\n\t       .**********               *,    , ***,. ,*,*,*********, *.,       \t";   
  std::cout<<"\n\t          ***                   ********** **,/******,,,,*****            \t";  
  std::cout<<"\n\t           ***     *           ************.****   .**  .*,   .            \t"; 
  std::cout<<"\n\t                 ****           *****,,*,*,***       /         ,           \t"; 
  std::cout<<"\n\t                **,*****,.           ****,**              * ***   ,         \t";
  std::cout<<"\n\t                 ***,*****           .***,**                     *         \t"; 
  std::cout<<"\n\t                   ,**,*.             *****                  ********    .  \t";
  std::cout<<"\n\t                   ****                ,                     ***.****,      \t";
  std::cout<<"\n\t                   *,                                              *        \t";
  std::cout<<"\n\t                   *                                                    *   \t";
  std::cout<<"\n\t                                    \t  \n"<<reset;

  std::cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

};

void Menu::menu()
{
  mapamundi();
  bool iniciado = false;
  bool terminado = false;
  std::regex pattern("^turno .*$");
  std::regex pattern2("^guardar .*$");
  std::regex pattern3("^inicializar_texto .*$");
  std::regex pattern4("^inicializar_binario .*$");
  std::regex pattern5("^guardar_comprimido .*$");
  std::regex pattern6("^costo_conquista .*$");
  Partida p;
  
  // Menu de todos los comandos

  std::string comando, tu, tuJ, gu, guN, ab, abN, gc, gcN, abc, abcN, cc, cN;
  std::cout<<"\n";
  
  while(comando.compare("salir") != 0) // while para ingresar comandos
  {
    std::cout<<"$ "; 
    std::getline(std::cin, comando); // se lee la linea completa ingresada por el usuario
    
    if(comando.size() > 5)
    {
      tu = comando.substr(0, 5);
      if (tu.compare("turno") == 0)
      {
        tuJ = comando.substr(6);
      }
    }

    if(comando.size() > 7)
    {
      gu = comando.substr(0, 7);
      if (gu.compare("guardar") == 0)
      {
        guN = comando.substr(8);
      }
    }

    if(comando.size() > 17)
    {
      ab = comando.substr(0, 17);
      if (ab.compare("inicializar_texto") == 0)
      {
        abN = comando.substr(18);
      }
    }

    if(comando.size() > 19)
    {
      abc = comando.substr(0, 19);
      if (abc.compare("inicializar_binario") == 0)
      {
        abcN = comando.substr(20);
      }
    }

    if(comando.size() > 18)
    {
      gc = comando.substr(0, 18);
      if (gc.compare("guardar_comprimido") == 0)
      {
        gcN = comando.substr(19);
      }
    }

    if(comando.size() > 15)
    {
      cc = comando.substr(0, 15);
      if (cc.compare("costo_conquista") == 0)
      {
        cN = comando.substr(16);
      }
    }
  
    if(comando.compare("") == 0);

    // condicionales de inicializar 

    else if (comando.compare("inicializar") == 0) 
    {
      if(terminado == false)
      {
        p = inicio();
        iniciado = true;
      }
      else
      {
        std::cout<<"\nEl juego ya ha terminado\n\n";
      }
    }

    else if (comando.compare("inicializar ?") == 0)
    {
      std::cout<< "\nLa forma correcta de utilizar este comando es: inicializar\n"<<std::endl;
      
    }

    // condicionales de turno 

    else if (comando.compare("turno ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: turno <id_jugador>\n"<<std::endl;
    }

    else if (std::regex_match(comando, pattern)) 
    {
      bool enc = false;
      std::list<Jugador>::iterator miIt;
      for (miIt = p.jugadoresP.begin(); miIt != p.jugadoresP.end(); miIt++)
      {
        if(tuJ.compare(miIt->nombreJugador) == 0)
          enc = true;
      }

      if(iniciado == false)
      {
        std::cout<<"\nEl juego no ha sido inicializado\n\n";
      }
      else if(terminado == true)
      {
        std::cout<<"\nEl juego ya ha terminado\n\n";
      }
      else 
      {
        if (enc == true)
        {
          if (tuJ.compare(p.turnos.front()) != 0)
          {
            std::cout<<"\nNo es el turno de "<<tuJ<<" es el turno de "<<p.turnos.front()<<"\n\n";
          }
          else if (tuJ.compare(p.turnos.front()) == 0)
          {
            p.turno();
          }
        }
        else if (enc == false)
        {
          std::cout<<"\nEl jugador "<<tuJ<<" no hace parte de esta partida\n\n";
        }

      }
    }

    // condicionales de guardar 

    else if (std::regex_match(comando, pattern2))
    {
      bool guardado = p.guardarNormal(guN);
      
      if (guardado == true)
        std::cout<<"\nSe ha guardado la partida en "<<guN<<"\n\n";

      else if (guardado == false)
        std::cout<<"\nNo se ha podido guardar la partida, intente nuevamente\n\n";
    }

    else if (comando.compare("guardar ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: guardar <nombre_archivo>\n"<<std::endl;
    }

    // condicionales de guardar_comprimido 
      
    else if (std::regex_match(comando, pattern5))
    {
      bool guardado = guardarComprimido(p, gcN);

      if (guardado == true)
        std::cout<<"\nSe ha guardado la partida en "<<gcN<<"\n\n";

      else if (guardado == false)
        std::cout<<"\nNo se ha podido guardar la partida, intente nuevamente\n\n";
    }

    else if (comando.compare("guardar_comprimido ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: guardar_comprimido <nombre_archivo>\n"<<std::endl;
    }

    // condicionales de inicializar_archivo texto y binario

    else if (std::regex_match(comando, pattern3))
    {
      if(terminado == false)
      {
        p = abrirNormal(abN);
        iniciado = true;
      }
      else
      {
        std::cout<<"\nEl juego ya ha terminado\n\n";
      }
    }

    else if (comando.compare("inicializar_texto ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: inicializar_texto <nombre_archivo>\n"<<std::endl;
    }

    else if (std::regex_match(comando, pattern4))
    {
      if(terminado == false)
      {
        p = abrirComprimido(abcN);
        iniciado = true;
      }
      else 
      {
        std::cout<<"\nEl juego ya ha terminado\n\n";
      }
    }

    else if (comando.compare("inicializar_binario ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: inicializar_binario <nombre_archivo>\n"<<std::endl;
    }

    // condicionales de costo_conquista 

    else if (std::regex_match(comando, pattern6))
    {
      if(iniciado == false)
      {
        std::cout<<"\nEl juego no ha sido inicializado\n\n";
      }
      else
      {
        p.costoconquista(cN);
      }
    }

    else if (comando.compare("costo_conquista ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: costo_conquista <territorio>\n"<<std::endl;
    }

    // condicionales de conquista_mas_barata 

    else if (comando.compare("conquista_mas_barata") == 0)
    {
      if(iniciado == false)
      {
        std::cout<<"\nEl juego no ha sido inicializado\n\n";
      }
      else
      {
        p.conquistaMasBarata(p.turnos.front());
      }
    }

    else if (comando.compare("conquista_mas_barata ?") == 0)
    {
      std::cout<<"\nLa forma correcta de utilizar este comando es: conquista_mas_barata\n"<<std::endl;
    }

    // condicional de help

    else if(comando.compare("ayuda") == 0)
    {
      std::cout<<"\nLos comandos disponibles son:"
               <<"\n - inicializar: inicia el juego donde le va a preguntar al usuario la cantidad de jugadores,\n   luego pregunta el nombre de cada uno de los jugadores para poder identificarlos durante la\n   partida. Después, por turnos, cada jugador seleccionará en que territorio desea ubicar sus\n   unidades de ejército."
               <<"\n - turno: Describe que puede hacer el jugador en este turno como: Fortificar terriorio, Atacar\n   un territorio Vecino o Obtener nuevas unidades" 
               <<"\n - salir: termina la ejecución del programa." 
               <<"\n - guardar: guarda toda la partida en un archivo de texto plano" 
               <<"\n - guardar_comprimido: guarda toda la partida en un archivo binario" 
               <<"\n - inicializar_texto: inicializa el juego con los datos contenidos en el archivo de texto <nombre_archivo>"
               <<"\n - inicializar_binario: inicializa el juego con los datos contenidos en el archivo binario <nombre_archivo>"  
               <<"\n - costo_conquista: calcula el costo y la secuencia de territoriors conquistados para lograr\n   controlar un territorio elegido." 
               <<"\n - conquista_mas_barata: calcula de todos los territorios posibles aquel que pueda sacrificar\n   el menor número de unidades perdidas"
               <<"\n - limpiar: limpia la interfaz y todos los comandos que se han hecho antes\n"<<std::endl;
        
    }

    else if(comando.compare("limpiar") == 0)
    {
      std::system("clear");
      mapamundi();
      std::cout<<"\n";
    }

    // condicional de salir
      
    else if (comando.compare("salir") == 0)
    {
      std::cout<<"\nGracias por jugar RISK!\n"<<std::endl; //aunque el enunciado dice que no tiene salida decidimos poner este mensaje 
    }

    // condicional en caso de que no se ingrese un comando válido

    else
      std::cout<<red<<"\nEl comando "<<reset<<comando<<red<<" no pudo ser reconocido, intente nuevamente\n"<<reset<<std::endl;

    // verificar que hay un ganador

    if(p.turnos.size() == 1)
    {
      if(comando.compare("salir") != 0)
        std::cout<<"El ganador es "<<p.turnos.front()<<"\nUtilice el comando \"salir\" para terminar el programa\n\n";
      terminado = true;
    }
  }
};

Partida Menu::inicio()
{
  int id;
  
  std::cout<<"\nIngrese el id de la partida (solo ingrese numeros): ";
  std::cin>>id;

  Partida p = Partida(id);

  return(p);
}

Partida Menu::abrirNormal(std::string nombreArchivo)
{
  std::string linea;
  std::ifstream archivo(nombreArchivo);

  int numJugadores = 0, numPaises = 0;
  std::string seccionActual;

  Continente* contiP[6];
  std::list<Jugador> jugadoresP;
  std::queue<std::string> turnos;

  if (archivo.is_open())
  {
    std::cout<<"\n-- Este es el archivo que se ha leido --\n\n";

    while (std::getline(archivo, linea))
    {
      std::cout<<linea<<std::endl;
      
      if (linea.find("Numero de jugadores:") != std::string::npos)
      {
        std::string nume = linea.substr(linea.find(":") + 2);
        numJugadores = std::stoi(nume);
      }
      else if (linea == "- Territorios")
      {
        seccionActual = "Territorios";
        numPaises = 0;
      }
      else if (linea == "- Jugadores")
      {
        seccionActual = "Jugadores";
      }
      else if (linea == "- Turnos")
      {
        seccionActual = "Turnos";
      }
      else
      {
        if (seccionActual == "Territorios")
        {
          if (linea.find(")") != std::string::npos)
          {
            std::string nombreContinente = linea.substr(linea.find(")") + 2);
            contiP[numPaises] = new Continente(nombreContinente);

            while (!contiP[numPaises]->territoriosC.empty())
            {
              contiP[numPaises]->territoriosC.pop_front();
            }

            numPaises++;
          }
          else
          {
            std::string nombreTerritorio = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);

            std::string duenio = linea.substr(0, linea.find(","));
            linea = linea.substr(linea.find(",") + 1);
            
            std::string numT = (linea.substr(0, linea.find(",")));
            linea = linea.substr(linea.find(",") + 1);
            int numTropas = std::stoi(numT);

            std::string toma = (linea.substr(0, linea.find(",")));
            int tomado = std::stoi(toma);
            
            Territorio nuevoTerritorio = Territorio(nombreTerritorio);
            nuevoTerritorio.duenio = duenio;
            nuevoTerritorio.numTropas = numTropas;
            nuevoTerritorio.tomado = tomado;

            contiP[numPaises-1]->territoriosC.push_back(nuevoTerritorio);
          }
        }
        else if (seccionActual == "Jugadores")
        {
          std::string nombreJugador = linea.substr(0, linea.find(","));
          linea = linea.substr(linea.find(",") + 1);

          std::string colorJugador = linea.substr(0, linea.find(","));
          linea = linea.substr(linea.find(",") + 1);

          std::string cantiT = (linea.substr(0, linea.find(",")));
          int cantiTropas = std::stoi(cantiT);

          Jugador nuevoJugador(nombreJugador, colorJugador, cantiTropas);

          jugadoresP.push_back(nuevoJugador);
        }
        else if (seccionActual == "Turnos")
        {
          turnos.push(linea);
        }
      }
    }

    std::cout<<"\n------------ Fin de archivo ------------\n\n";
    archivo.close();
  }
  else
  {
    std::cout<<"\nNo se pudo abrir el archivo\n\n";
  }

  Partida p = Partida(contiP, jugadoresP, turnos);

  return p;
}

bool Menu::guardarComprimido(Partida p, std::string nombreArchivo)
{
  bool a = p.guardarNormal("bin.txt");
  std::ifstream archivo("bin.txt");
  std::string linea;

  std::list<Caracter> listaCaracteres;
  std::string textoCifrar = "";

  if (archivo.is_open())
  {
    while (std::getline(archivo, linea))
    {
      textoCifrar = textoCifrar + linea + "\n";
    }
  }

  archivo.close();
  remove("bin.txt");

  for(int i=0; i<textoCifrar.size(); i++)
  {
    bool enc = false;
    std::list<Caracter>::iterator miIt;

    if(textoCifrar[i] == ' ')
    {
      textoCifrar[i] = '_';
    }
    
    for (miIt = listaCaracteres.begin(); miIt != listaCaracteres.end(); miIt++)
    {
      if(textoCifrar[i] == miIt->dato)
      {
        miIt->frec++;
        enc = true;
      }
    }

    if(enc == false)
    {
      Caracter nuevoCaracter = Caracter(textoCifrar[i]);
      listaCaracteres.push_back(nuevoCaracter);
    }
  }

  int tamano = listaCaracteres.size(), aux = 0;
  std::list<Caracter>::iterator miIt;

  char caracteres[tamano];
  long frecuencias[tamano];

  for(miIt = listaCaracteres.begin(); miIt != listaCaracteres.end(); miIt++)
  {
    caracteres[aux] = miIt->dato;
    frecuencias[aux] = miIt->frec;
    aux++;
  }

  HuffmanArbol arbol;
  
  arbol.generarArbol(caracteres, frecuencias, tamano);

  std::string textoCifrado = arbol.cifrar(textoCifrar);

  std::ofstream archivo2(nombreArchivo, std::ios::binary);

  bool creado = false;

  if (archivo2.is_open())
  {
    archivo2.write(reinterpret_cast<char*>(&tamano), sizeof(tamano));

    // Escribir el array 'caracteres'
    archivo2.write(reinterpret_cast<char*>(caracteres), sizeof(caracteres));

    // Escribir el array 'frecuencias'
    archivo2.write(reinterpret_cast<char*>(frecuencias), sizeof(frecuencias));

    //corección 
    for (int i = 0; i < textoCifrado.length(); i += 8) 
    {
      std::string byteStr = textoCifrado.substr(i, 8); // Obtiene 8 bits
      char byte = 0;

      // Convierte la cadena de 8 bits a un byte (char)
      for (int j = 0; j < 8; j++) 
      {
        if (byteStr[j] == '1')
        {
            byte |= (1 << (7 - j));
        }
      }
      // Escribe el byte en el archivo comprimido
      archivo2.write(&byte, sizeof(char));
    }
    //fin correcion

    creado = true;

    archivo2.close();
  }
  else
  {
    std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    creado = false;
  }

  return creado;
}

Partida Menu::abrirComprimido(std::string nombreArchivo)
{
  std::ifstream archivo(nombreArchivo, std::ios::binary);
  std::string textoDescifrado;
  bool sigue = false;

  if (archivo.is_open())
  {
    int tamano = 0;
    archivo.read(reinterpret_cast<char*>(&tamano), sizeof(tamano));

    char caracteres[tamano];
    long frecuencias[tamano];

    // Leer el array 'caracteres'
    archivo.read(reinterpret_cast<char*>(caracteres), sizeof(caracteres));

    // Leer el array 'frecuencias'
    archivo.read(reinterpret_cast<char*>(frecuencias), sizeof(frecuencias));

    //correcion
    std::string textoCifrado = "";
    
    char byte;
    while (archivo.read(&byte, sizeof(char))) 
    {
      for (int j = 7; j >= 0; j--) 
      {
        if ((byte >> j) & 1) 
        {
          textoCifrado += "1";
        } 
        else 
        {
          textoCifrado += "0";
        }
      }
    }
    //fin correcion

    HuffmanArbol arbol;
    arbol.generarArbol(caracteres, frecuencias, tamano);

    long longiSec;
    int aux=0;

    for(int i=0; i<tamano; i++)
    {
      aux = aux + frecuencias[i];
    }

    longiSec = aux;

    textoDescifrado = arbol.desCifrar(textoCifrado, longiSec);

    //std::cout << "Texto descifrado: " << textoDescifrado << std::endl;

    archivo.close();

    sigue = true;
  }
  else
  {
    std::cout<<"\nError al abrir el archivo para lectura\n\n";
    sigue = false;
  }

  Partida p;

  if(sigue == true)
  {
    std::ofstream archivo2("bin2.txt");

    for(int i=0; i<textoDescifrado.size(); i++)
    {
      if(textoDescifrado[i] == '_')
      {
        textoDescifrado[i] = ' ';
      }
    }

    if(archivo2.is_open())
    {
      archivo2 << textoDescifrado;
    }

    archivo2.close();

    p = abrirNormal("bin2.txt");

    remove("bin2.txt");
  }

  return p;
}