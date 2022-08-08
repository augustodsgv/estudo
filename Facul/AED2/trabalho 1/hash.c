/*
* Autor : Augusto dos Santos Gomes Vaz
* Programa : implementação de uma função de espalhamento
*/

/* BIBLIOTECAS */
#include "hash.h"

/* FUNÇÕES */
//função hash
int
hashFunc(char string [], int tamanho, int primo)
{
    int i = 0;
    int hash = 0;
    while (string[i] != '\0'){
        hash = (hash + string[i] * (i + 1)) * primo % tamanho;
        i++;
    }
    return hash % tamanho;
}