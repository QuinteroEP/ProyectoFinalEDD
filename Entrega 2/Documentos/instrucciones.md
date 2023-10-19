# Instrucciones

### Compilación y ejecucción 
   
1. Navegar a la carpeta del código 

   ```
   cd Codigo
   ```
      
      Los archivos del codigo estan en la carpeta "Codigo" dentro del repositorio.
   
2. Compilación 

   ```
   g++ -std=c++11 main.cpp Menu.cxx Partida.cxx Carta.cxx Jugador.cxx Continente.cxx Territorio.cxx -o risk
   ```
   
      Compilamos el programa usando g++. Esto incluye todos los archivos necesarios para la compilación, como "Menu.cxx" que contiene las funciones desarrolladas para esta entrega, y "main.cpp" que contiene el punto de entrada
   
3. Ejecucción 

   ```
   ./risk
   ```
   
      Al ejecutar el programa podras ver menu que desarollamos, a continuación listamos cuales son los comandos que puedes ejecutar para que el programa funcione de forma correcta.

### Comandos 

1. Empezar juego 

   ```
   inicializar
   ```
   
   Este comando inicia el juego, solicitando al usuario la cantidad de jugadores. Luego, pide el nombre de cada jugador para identificarlos durante la partida. En turnos sucesivos, cada jugador elige dónde desplegar sus unidades de ejército. El comando `inicializar` tiene dos resultados posibles: `Juego en curso` que indica que el juego ya se ha inicializado previamente, y `Inicialización Satisfactoria`, que confirma que el juego se ha inicializado correctamente.
   

-  ***Para obtener ayuda en este comando, puedes ejecutar:***

   ```
   inicializar ?
   ```
   
2. Turno del jugador 

   ```
   turno <id_jugador>
   ```
   
   - Este comando describe las acciones disponibles para el jugador. Puede realizar una de las siguientes acciones:

      - `Fortificar territorio`: Mover algunas unidades de ejército desde un territorio a otro.
      - `Atacar un territorio vecino`: Elegir un territorio de su ejército y atacar un territorio enemigo vecino. El resultado se determina mediante el lanzamiento de dados, y el proceso continúa hasta que un jugador pierde todas sus unidades o el atacante decide detenerse.
      - `Obtener nuevas unidades`: Verificar cuántas nuevas unidades puede reclamar y asignarlas a sus territorios, eligiendo la cantidad para cada uno. 

   - El comando `turno` puede tener varias salidas, como:

      - `Juego no inicializado`: La partida no se ha inicializado correctamente.
      - `Juego terminado`: La partida ha concluido con un ganador.
      - `Jugador no válido`: El ID o nombre de jugador proporcionado no existe en la partida.
      - `Jugador fuera de turno`: Un jugador intenta realizar un turno cuando no le corresponde.
      - `Turno terminado correctamente`: El turno del jugador se ha completado de manera exitosa. 
   
- ***Para obtener ayuda en este comando, puedes ejecutar:***
   
   ```
   turno ?
   ```

3. Salida de la aplicacion 

   ```
   salir
   ```
   
   Este comando termina la ejecución del programa. Este comando no tiene salidas. 

4. Guardado el juego 

   ```
   guardar <nombre_archivo>
   ```
   
   Este comando guarda toda la partida en un archivo de texto plano. El archivo incluye información sobre la cantidad de jugadores que participaron en la partida, para cada jugador se almacenan detalles como su nombre o ID, su color en la partida, la cantidad de países que controla, un identificador para cada territorio junto con la cantidad de unidades de ejército en él, la cantidad de tarjetas en posesión de cada jugador, y un identificador para cada tarjeta.

   - Las posibles salidas de este comando son las siguientes:

      - `Juego no inicializado`: Indica que la partida no se ha inicializado correctamente.
      - `Comando correcto`: Confirma que la partida se ha guardado con éxito.
      - `Error al Guardar`: Significa que la partida no se guardó de manera adecuada.

- ***Para obtener ayuda en este comando, puedes ejecutar:***
   
   ```
   guardar ?
   ```

5. Guardar el juego en un archivo comprimido 

   ```
   guardar_comprimido <nombre_archivo>
   ```
   
   Este comando realiza la misma función que el comando `guardar <nombre_archivo>`, pero en este caso, crea un archivo binario con extensión `.bin` que contiene la misma información que el archivo de texto. 
      - Las posibles salidas de este comando son las siguientes:

         - `Juego no inicializado`: Indica que la partida no se ha inicializado correctamente.
         - `Comando correcto`: Confirma que la partida se ha guardado con éxito.
         - `Error al Comprimir`: Significa que la partida no se guardó ni comprimió correctamente.
- ***Para obtener ayuda en este comando, puedes ejecutar:***
   
   ```
   guardar_comprimido ?
   ```

6. Inicializar a partir de un archivo de texto 
   
      ```
      inicializar_texto <nombre_archivo>
      ```
      
      Este comando permite inicializar el juego utilizando los datos contenidos en el archivo `<nombre_archivo>`. Este archivo debe contener información de una partida normal, la cual pudo haber sido generada previamente con los comandos `guardar` o `guardar_comprimido`. 
      - Las posibles salidas de este comando son las siguientes:

         - `Juego en curso`: Indica que el juego ya ha sido inicializado y una partida está en progreso.
         - `Archivo vacío o incompleto`: Significa que el nombre del archivo no contiene información válida o el archivo no existe, por lo que la inicialización no se ha podido llevar a cabo.
   - ***Para obtener ayuda en este comando, puedes ejecutar:***
      ```
      inicializar_texto ?
      ```

7. Inicializar a partir de un archivo binario
   
      ```
      inicializar_binario <nombre_archivo>
      ```
      
      Este comando te permite iniciar el juego utilizando los datos almacenados en el archivo `<nombre_archivo>`. Debes asegurarte de que este archivo contenga información válida y haya sido generado previamente con los comandos `guardar` o `guardar_comprimido`. 
      - Las posibles salidas de este comando son las siguientes:

         - `Juego en curso`: Esto indica que el juego ya ha sido inicializado y una partida está en progreso.
         - `Archivo vacío o incompleto`: Significa que el nombre del archivo no contiene información válida o que el archivo no existe, por lo tanto, no se puede realizar la inicialización.
   - ***Para obtener ayuda en este comando, puedes ejecutar:***

      ```
      inicializar_binario ?
      ```

8. Calcular costo conquista 

      ```
      costo_conquista <territorio>
      ```       
      Este comando calcula el costo y la secuencia de territorios que deben ser conquistados para obtener el control del territorio especificado por el usuario. El territorio objetivo debe ser el más cercano al territorio del jugador que emite el comando. La información se analiza desde la perspectiva del jugador que tiene el turno en ese momento. 
      - Las posibles salidas de este comando son las siguientes:

         - `Juego no inicializado`: Indica que la partida no ha sido inicializada correctamente.
         - `Juego terminado`: Significa que la partida ha finalizado y se ha declarado un ganador.
         - `Comando correcto`: En este caso, el comando proporcionará los pasos necesarios para conquistar el territorio deseado, incluyendo la secuencia de territorios que deben ser atacados y la cantidad de unidades de ejército requeridas.
   - ***Para obtener ayuda en este comando, puedes ejecutar:***
   
      ```
      costo_conquista ?
      ```

9. Calcular costo de conquista mas bajo 

      ```
      conquista_mas_barata
      ```
      
      Este comando permite al jugador en su turno calcular cuál es la conquista más económica en términos de unidades perdidas. 
      - Las posibles salidas de este comando son las siguientes:

         - `Juego no inicializado`: Indica que la partida no ha sido inicializada correctamente.
         - `Juego terminado`: Se refiere a que la partida ha concluido y se ha determinado un ganador.
         - `Jugador no válido`: Ocurre cuando un jugador intenta utilizar este comando fuera de su turno.
         - `Comando correcto`: En esta situación, el comando proporcionará la información sobre la conquista más económica. Por ejemplo, "La conquista más barata es avanzar desde el territorio <territorio_2> hacia el territorio <territorio_1> a través de los territorios <territorio_3>, <territorio_4>, ..., <territorio_m>. Debe conquistar <n> unidades de ejército para lograrlo".
   - ***Para obtener ayuda en este comando, puedes ejecutar:***
      
      ```
      conquista_mas_barata ?
      ```

10. Ayuda 

      ```
      ayuda
      ```
         
      Al ejecutar este comando en la terminal, obtendrás una lista de todos los comandos disponibles junto con una breve explicación de cada uno, como se detalla a continuación:

      - `ayuda`: Muestra una lista de todos los comandos disponibles junto con sus explicaciones.

      Este comando te proporciona una referencia rápida de todos los comandos disponibles y sus funciones correspondientes.
11. Limpiar 
                    
      ```
      Limpiar
      ```
   
      Al ejecutar este comando en la terminal, la consola se limpiará, dejando únicamente visible el banner y la línea de comandos, lo que te permitirá introducir nuevos comandos de manera más clara.
