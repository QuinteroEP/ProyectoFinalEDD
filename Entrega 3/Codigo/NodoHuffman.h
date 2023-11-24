#ifndef NODOHUFFMAN_H_
#define NODOHUFFMAN_H_

class HuffmanNodo
{
private:
    char dato;
    unsigned int freq;
    HuffmanNodo *der, *izq;
    
public:
    HuffmanNodo();
    HuffmanNodo(char dato, unsigned int freq);
    HuffmanNodo* obtenerHijoIzq();
    HuffmanNodo* obtenerHijoDer();
    void fijarHijoDer(HuffmanNodo* der);
    void fijarHijoIzq(HuffmanNodo* izq);
    unsigned int obtenerFreq();
    char obtenerDato();
    bool esHoja();
};

#include "NodoHuffman.cxx"

#endif