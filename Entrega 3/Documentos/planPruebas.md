# Plan de pruebas

## Menú

### - Ingresar comando "inicializar" 
***Entrada:*** 
inicializar

***Resultado Esperado:***
La partida se crea correctamente al ejecutar este comando.

*Resultado Obtenido:* ✓

### - Ingresar comando "turno <id_jugador>" 
***Entrada:*** 
turno <id_jugador>

***Resultado Esperado:***
Se verifica si la partida ha iniciado, si el jugador especificado existe, y si es el turno del jugador indicado. Luego se llama a la función turno() del objeto partida.

*Resultado Obtenido:* ✓

### - Ingresar comando "ayuda" 
***Entrada:*** 
ayuda

***Resultado Esperado:***
Debería mostrar una lista de los posibles comandos y una breve explicación de cada uno.

*Resultado Obtenido:* ✓

### - Ingresar comando "limpiar" 
***Entrada:***
limpiar

***Resultado Esperado:***
La terminal se limpia y solo se muestra el banner.

*Resultado Obtenido:* ✓

## Constructor Partida 

### - Ingresar numero de jugadores 
***Entrada:***
Un número entero entre 2 y 6.

***Resultado Esperado: ***
Si el número cumple con la condición, se procede al siguiente paso.

*Resultado Obtenido:* ✓

### - Ingresar nombre de los jugadores 
***Entrada: ***
Nombre del jugador. 

***Resultado Esperado: ***
Debería mostrar el nombre del jugador y el color asignado.

*Resultado Obtenido:* ✓

### - Elegir territorios por turnos 
***Entrada: ***
Nombre del territorio.

***Resultado Esperado: ***
Debería mostrar el nombre del jugador y el color asignado.

*Resultado Obtenido:* ✓

### - Asignar mas tropas por turnos 
***Entrada: ***
Nombre del territorio.

***Resultado Esperado: ***
Debería mostrar el nombre del territorio y el jugador que lo eligió.

*Resultado Obtenido:* ✓

## Funcion turno 

### - Ingresar nuevas tropas 
***Entrada: ***
Nombre del territorio.

***Resultado Esperado: ***
Debería mostrar el nombre del territorio y la nueva cantidad de tropas.

*Resultado Obtenido:* ✓

### - Atacar 
***Entrada:*** 
Nombre del territorio de origen y nombre del territorio de destino.

***Resultado Esperado: ***
Se lanzan los dados y se muestra si el ataque tuvo éxito o no, permitiendo continuar con más ataques o finalizar el turno.

*Resultado Obtenido:* ✓

### - Fortificar 
***Entrada: ***
Nombre del territorio de origen, nombre del territorio de destino y cantidad de tropas a enviar.

***Resultado Esperado: ***
Debería mostrar el territorio de origen con la cantidad de tropas restantes y el territorio de destino con la nueva cantidad de tropas.

*Resultado Obtenido:* ✓

## Manejo de archivos 

### - Ingresar comando "guardar <nombre_archivo>" 
***Entrada: ***
guardar <nombre_archivo>

***Resultado Esperado: ***
La partida se guarda en un archivo y se muestra si la operación fue exitosa o si hubo un error.

*Resultado Obtenido:* ✓

### - Ingresar comando "inicializar_texto <nombre_archivo>" 
***Entrada: ***
inicializar_archivo <nombre_archivo> 

(este archivo es txt)

***Resultado Esperado: ***
Se debería intentar leer el archivo, mostrar su contenido y permitir continuar jugando normalmente.

*Resultado Obtenido:* ✓

### - Ingresar comando "guardar_comprimido <nombre_archivo>" 
***Entrada: ***
guardar_comprimido <nombre_archivo>

***Resultado Esperado: ***
La partida se guarda en un archivo binario comprimido y se muestra si la operación fue exitosa o si hubo un error.

*Resultado Obtenido:* ✓

### - Ingresar comando "inicializar_binario <nombre_archivo>" 
***Entrada: ***
inicializar_archivo <nombre_archivo>

***Resultado Esperado: ***
Se debería intentar leer el archivo comprimido, mostrar su contenido y permitir continuar jugando normalmente.

*Resultado Obtenido:* ✓


## Recorridos (grafos)
### - Ingresar comando "costo_conquista \<territorio\>"
Entrada: costo_conquista \<territorio\>

Devuelve el costo y el camino que se debe seguir para conquistar el territorio dado

*Resultado Obtenido:* ✓


### 2. Ingresar comando "conquista_mas_barata" 
Entrada: conquista_mas_barata

Resultado Esperado: la partida no ha iniciado o devuelve el costo, el destino y el origen de la conquista mas barata

*Resultado Obtenido:* ✓