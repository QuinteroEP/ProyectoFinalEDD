#ifndef ARBOLHUFFMAN_H_
#define ARBOLHUFFMAN_H_

#include "NodoHuffman.h"

class HuffmanArbol
{
private:
    HuffmanNodo *raiz;
    std::vector <std::pair <char,std::string>> codigos;

public:
    HuffmanArbol();
    void generarArbol(char dato[], long freq[],int size);
    struct comparar;
    void guardarCodigos(HuffmanNodo *inicio, std::string str);
    void imprimirCodigos();
    std::string obtenerCodigo(char caracter);
    std::string cifrar(std::string secunecia);
    std::string desCifrar(std::string cif, long longiSec);
    HuffmanNodo * deCodificar(HuffmanNodo *nodo, char dir, int &cont, std::string &des);
    HuffmanNodo * getRaiz();
};

#include "ArbolHuffman.cxx"
#endif 