#include "ArbolHuffman.h"
#include <iostream>
#include <utility>
#include <vector>

HuffmanArbol::HuffmanArbol()
{
    this->raiz = NULL;
}

struct HuffmanArbol::comparar
{

    bool operator()(HuffmanNodo *l, HuffmanNodo *r)

    {
        return (l->obtenerFreq() > r->obtenerFreq());
    }
};

void HuffmanArbol::generarArbol(char dato[], long freq[], int tama)
{
    HuffmanNodo *left, *right, *top;

    std::priority_queue<HuffmanNodo *, std::vector<HuffmanNodo *>, comparar> minHeap;
    for(int i = 0; i < minHeap.size();++i){
        minHeap.pop();
    }
    for (int i = 0; i < tama; i++)
    {
        minHeap.push(new HuffmanNodo(dato[i], freq[i]));
    }
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();
        unsigned int nuevaFreq = left->obtenerFreq() + right->obtenerFreq();
        top = new HuffmanNodo(' ', nuevaFreq);
        top->fijarHijoDer(right);
        top->fijarHijoIzq(left);
        minHeap.push(top);
    }
    this->raiz = minHeap.top();
    guardarCodigos(this->raiz, "");
}

void HuffmanArbol::guardarCodigos(HuffmanNodo *inicio, std::string str)
{
    if (!inicio)
        return;
    if (inicio->obtenerDato() != ' ')
    {
        codigos.push_back(make_pair(inicio->obtenerDato(), str));
    }
    this->guardarCodigos(inicio->obtenerHijoIzq(), str + "0");
    this->guardarCodigos(inicio->obtenerHijoDer(), str + "1");
}

void HuffmanArbol::imprimirCodigos()
{
    std::vector<std::pair<char, std::string>>::iterator it;
    for (it = codigos.begin(); it != codigos.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

std::string HuffmanArbol::obtenerCodigo(char caracter)
{
    std::string codigo = "";
    bool encontrado = false;
    std::vector<std::pair<char, std::string>>::iterator it;
    for (it = codigos.begin(); it != codigos.end() && !encontrado; ++it)
    {
        if (it->first == caracter)
            codigo = it->second;
    }
    return codigo;
}

std::string HuffmanArbol::cifrar(std::string sec)
{
    std::string cifrado;
    for (int i = 0; i < sec.size(); ++i)
    {
        cifrado += this->obtenerCodigo(sec[i]);
    }
    int tama = cifrado.size() % 8;
    if(tama != 0){
        for (int i = 0; i < 8 - tama; i++){
            cifrado += "0";
        }
    }
    return cifrado;
}

std::string HuffmanArbol::desCifrar(std::string sec, long longiSec)
{
    HuffmanNodo *nodo = this->raiz;
    std::string desCifrado = "";
    int contador = 0;
    for (int i = 0; i < sec.size() +1; i++)
    {
        if (nodo->esHoja())
        {
            desCifrado += nodo->obtenerDato();
            nodo = this->raiz;
            contador++;
            if(contador == longiSec){
                break;
            }
        }
        if (sec[i] == '1')
        {
            nodo = nodo->obtenerHijoDer();
        }
        else
        {
            nodo = nodo->obtenerHijoIzq();
        }
    }
    return desCifrado;
}

HuffmanNodo * HuffmanArbol::getRaiz()
{
    return this->raiz;
}

HuffmanNodo * HuffmanArbol::deCodificar(HuffmanNodo *nodo, char dir, int &cont, std::string &des)
{
    if(nodo->esHoja()){
        des+= nodo->obtenerDato();
        nodo = this->raiz;
        cont++;
    }
    if(dir == '1'){
        nodo = nodo->obtenerHijoDer();
    }
    else if(dir == '0'){
        nodo = nodo->obtenerHijoIzq();
    }
    return nodo;
}