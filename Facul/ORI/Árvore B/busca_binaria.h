/*
* Programa : busca_binaria.h
* Objetivo : implementação de uma busca binária em um vetor
* Autor : Augusto dos Santos
* Data : 08/08/2022
*/

#ifndef BUSCA_BINARIA
#define BUSCA_BINARIA
#include <iostream>

using namespace std;
//namespace busca_binaria

    template <class T>
    bool
    busca_binaria(T * vetor, T elemento, int vetor_inicio, int vetor_fim, int & posicao)
    {
        int vetor_meio = (int)(vetor_fim + vetor_inicio) / 2;
        if(vetor_meio == vetor_inicio)                   //caso o vetor tenho somente um elemento
        {
            if(vetor[vetor_meio] == elemento)
            {
                posicao = vetor_meio;
                return true;
            }
            //else : um vetor unitário não é o elemento, logo, não está na lista
            return false;
        }

        
        if(vetor[vetor_meio] == elemento)                     //caso seja o elemento do meio
        {
            posicao = vetor_meio;
            return true;
        }
        
        //else : caso seja menor o elemento central
        if(vetor[vetor_meio] > elemento)                      
            return busca_binaria(vetor, elemento, vetor_inicio, vetor_meio -1, posicao);

        //else : caso seja menor que o elemento
        if(vetor[vetor_meio] < elemento)
            return busca_binaria(vetor, elemento, vetor_meio + 1, vetor_fim, posicao);

    }


#endif /* BUSCA_BINARIA */