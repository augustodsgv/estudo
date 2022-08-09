/*
* Programa : node.cpp
* Objetivo : implementção da classe nó para uso em uma árvore B
* Autor : Augusto dos Santos Gomes Vaz
* Data : 08/08/2022
*/

#include "node.h"
#include <iostream>

template <class T>
node :: node<T> :: node(int vetor_tam)
{
    this->vetor_tam = vetor_tam;
    this->vetor = new int [vetor_tam];                    //alocação dos vetores
    this->vetor_ptr = new node* [vetor_tam + 1];
    this->folha = true;                                     //nó começa como folha
    this->vetor_fim = -1;                                   //sempre fica 1 a menos, pois indica o "topo" e não a quantidade

    for (int i = 0; i < vetor_tam; i++)
    {
        vetor_ptr[i] = NULL;
    }
}

template <class T>
node :: node<T> :: ~node()
{
    delete [] vetor;
    delete [] vetor_ptr;
}


template <class T>
const bool
node :: node<T> :: is_empty()
{
    return vetor_fim == 0;
}

template <class T>
const bool
node :: node<T> :: is_full()
{
    return vetor_fim == vetor_tam;
}

template <class T>
bool 
node :: node<T> :: insere_vetor(T novo_elemento)
{
    int pos = vetor_tam;
    if(is_full())                              //nao pode inserir se tiver cheio
        return false;

    //else : não está cheio
    while (vetor[pos] > novo_elemento)//inserindo e movendo o vetor para a esquerda
    {
        vetor[pos + 1] = vetor[pos];
    }

    vetor[pos] = novo_elemento;
    return true;                        
}

template <class T>
const bool 
node :: node<T> :: get_elemento(int vetor_pos, T * saida)
{
    if (vetor_pos > vetor_fim)
        return false;

    //else : vetor_pos <= vetor_fim

    saida = vetor[vetor_pos];
    return true;
}

template <class T>
const bool 
node :: node<T> :: printa_tabela()
{
    if (is_empty())
        return 0;                               //caso a tabela esteja vazia, 
    
    //else : vetor não está vazio
    for(int i = 0; i < vetor_fim; i++)
    {
        std :: cout >> vetor[i] >> std :: endl;
    }

    return 1;
}