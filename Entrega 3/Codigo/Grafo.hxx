#include "Grafo.h"

#include <iostream>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>

// cosas que se necesitan para cambiar el color del texto
#define resetG "\033[0m"
#define blue "\033[34m" 
#define red "\033[31m" 
#define green "\033[92m" 
#define yellow "\033[93m" 
#define magenta "\033[35m"
#define cyan "\033[96m"

template<class T, class U>
bool Grafo<T, U>::buscarVertice(T vertice) {
    if (vertices.size() == 0) {
        return false;
    }
    for (int i = 0; i < this->vertices.size(); i++) {
        if (this->vertices[i] == vertice) {
            return true;
        }
    }
    return false;
}

template<class T, class U>
int Grafo<T, U>::indiceVertice(T vertice) {
    int indice = -1;
    for (int i = 0; i < this->vertices.size(); i++) {
        if (this->vertices[i] == vertice) {
            indice = i;
        }
    }
    return indice;
}

template<class T, class U>
bool Grafo<T, U>::insertarVertice(T vertice) {

    //Se verifica que el dato no sea repetido
    if (buscarVertice(vertice)) {
        return false;
    }
    //Se agrega el nuevo elemento al arreglo
    this->vertices.push_back(vertice);

    //Se agranda la matriz
    int n = this->vertices.size();
    this->matriz_adyacencia.resize(n);
    for (int i = 0; i < this->matriz_adyacencia.size(); i++)
        this->matriz_adyacencia[i].resize(n);
    return true;
}

template<class T, class U>
bool Grafo<T, U>::conectarVertices(T vertice1, T vertice2, U peso) {

    //Se verifica que los this->vertices existan
    if (!buscarVertice(vertice1)) {
        return false;
    }
    if (!buscarVertice(vertice2)) {
        return false;
    }

    //Se consiguen los indices de los vertices
    int n1 = indiceVertice(vertice1);
    int n2 = indiceVertice(vertice2);

    this->matriz_adyacencia[n1][n2] = peso;
    return true;
}

template<class T, class U>
bool Grafo<T, U>::buscarArista(T vertice1, T vertice2) {
    //Se verifica que los this->vertices existan
    if (!buscarVertice(vertice1)) {
        return false;
    }
    if (!buscarVertice(vertice2)) {
        return false;
    }

    //Se consiguen los indices de los vertices
    int n1 = indiceVertice(vertice1);
    int n2 = indiceVertice(vertice2);
    //Retorna verdadero si diferente de 0
    return this->matriz_adyacencia[n1][n2] != 0;
}

template<class T, class U>
U Grafo<T, U>::valorConexion(T vertice1, T vertice2) {
    //Se verifica que los this->vertices existan
    if (!buscarVertice(vertice1)) {
        return 0;
    }
    if (!buscarVertice(vertice2)) {
        return 0;
    }

    //Se consiguen los indices de los vertices
    int n1 = indiceVertice(vertice1);
    int n2 = indiceVertice(vertice2);

    //Retorna el valor
    return this->matriz_adyacencia[n1][n2];
}

template<class T, class U>
void Grafo<T, U>::imprimirMatriz() 
{
    std::cout << "\nMatriz de adyacencia:\n\n";

    for(int i=0; i<this->vertices.size()+ 1; i++)
    {            
        if(i==0)
            std::cout << "X:  ";

        else if(i<10)
            std::cout << "   " << i;

        else
            std::cout << "  " << i;
    }

    std::cout<<std::endl<<std::endl;

    for (int i = 0; i < this->matriz_adyacencia.size(); i++) 
    {
        if (i<9)
            std::cout << i+1 << ":     ";

        else
            std::cout << i+1 << ":    ";

        for (int j = 0; j < this->matriz_adyacencia[i].size(); j++) 
        {
           int aux = this->matriz_adyacencia[i][j];
           
            if(i==j)
                std::cout<<red;
           

            if(aux != 0)
                std::cout<<green;

            if(aux < 10)
                std::cout << this->matriz_adyacencia[i][j] << "   "<<resetG;

            else
                std::cout << this->matriz_adyacencia[i][j] << "  "<<resetG;
        }
        std::cout << "\n\n";
    }
}


template<class T, class U>
std::vector< std::pair<T, T> > Grafo<T, U>::dijkstra(T vertice) 
{
    T verticeActual = vertice;
    std::vector<U> distancias;
    std::vector<T> visitados;
    std::vector<T> grafo = this->vertices;
    std::vector<T> noVisitados = this->vertices;
    std::vector<T> prev(grafo.size());

    for (int i = 0; i < grafo.size(); i++) 
    {
        distancias.push_back(456361);
    }
    distancias[indiceVertice(verticeActual)] = 0;

    while (!noVisitados.empty()) 
    {
        U menor = 456361;
        for (int i = 0; i < noVisitados.size(); i++) 
        {
            if (distancias[indiceVertice(noVisitados[i])] < menor) 
            {
                menor = distancias[indiceVertice(noVisitados[i])];
                verticeActual = noVisitados[i];
            }
        }
        visitados.push_back(verticeActual);

        typename std::vector<T>::iterator it = noVisitados.begin();

        for(int i=0; i<noVisitados.size(); i++)
        {
            if(noVisitados[i] == verticeActual)
            {
                it = noVisitados.begin() + i;
            }
        }
        
        noVisitados.erase(it);

        for (int i = 0; i < grafo.size(); i++)
        {
            if (buscarArista(verticeActual, grafo[i])) 
            {
                U distanciaVertice = distancias[indiceVertice(verticeActual)];
                U distanciaVecino = distancias[indiceVertice(grafo[i])];
                U nuevaDistancia = distanciaVertice + valorConexion(verticeActual, grafo[i]);

                if (distanciaVecino > nuevaDistancia) 
                {
                    distancias[indiceVertice(grafo[i])] = nuevaDistancia;
                    prev[indiceVertice(grafo[i])] = verticeActual;
                }
            }
        }
    }

    std::vector< std::pair<T, T> > conexiones;

    for(int i=0; i<prev.size(); i++)
    {
        if (i == indiceVertice(vertice))
        {
            continue;
        }
        else
        {
            conexiones.push_back(std::make_pair(prev[i], grafo[i]));
        }
    }

    return conexiones;
}