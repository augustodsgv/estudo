/*
* Programa : node.h
* Objetivo : classe nó para uso em uma árvore B
* Autor : Augusto dos Santos Gomes Vaz
* Data : 08/08/2022
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "busca_binaria.h"

//namespace node
namespace node
{
    template <class T>
    class node
    {
        public: 
            node(int vetor_tam);
            ~node();

            //getters
            const bool get_elemento(int vetor_pos, T * saida);
            const bool is_folha();
            const bool is_empty();
            const bool is_full();
            //setters
            bool set_folha(bool modo);
            bool insere_vetor(T novo_elemento);
            bool remove_vetor(T elemento);

            const bool printa_tabela();

        private:
            int vetor_tam;
            int vetor_fim;
            T * vetor;                              //vetor com os elementos
            node ** vetor_ptr;                      //vetor com os ponteiros dos filhos do nó atual

            bool folha;

            



    };

    template <class T>
    node<T> :: node(int vetor_tam)
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
    node<T> :: ~node()
    {
        delete [] vetor;
        delete [] vetor_ptr;
    }


    template <class T>
    const bool
    node<T> :: is_empty()
    {
        return vetor_fim == -1;
    }

    template <class T>
    const bool
    node<T> :: is_full()
    {
        return vetor_fim == vetor_tam;
    }

    template <class T>
    bool 
    node<T> :: insere_vetor(T novo_elemento)
    {
        int pos;
        if(is_full())                              //nao pode inserir se tiver cheio
            return false;
        //else : não está cheio
        vetor[++vetor_fim] = novo_elemento;
        pos = vetor_fim - 1;


        while (vetor[pos] > novo_elemento && pos > 0)//inserindo e movendo o vetor para a esquerda
        {
            vetor[pos + 1] = vetor[pos];
        }

        return true;                        
    }

    template <class T>
    const bool 
    node<T> :: get_elemento(int vetor_pos, T * saida)
    {
        if (vetor_pos > vetor_fim)
            return false;

        //else : vetor_pos <= vetor_fim

        saida = vetor[vetor_pos];
        return true;
    }

    template <class T>
    bool
    node <T> :: remove_vetor(T elemento)
    {
        int posicao;
        if(!busca_binaria<T>(vetor, elemento, 0, vetor_fim + 1, posicao))            //caso a busca tenha dado errado
            return false;

        //else : achou o elemento
        //"rolando" o elemento achado até o final do vetor
        while (posicao < vetor_fim + 1)                                         //não precisa de + 1 pois posicao pode chegar
        {                                                                   //somente até tamanho -1
            vetor[posicao] = vetor[posicao + 1];
            posicao ++;
        }
        vetor_fim --;                                                       //reduzindo o tamanho do vetor, pois foi removido o elemento
    }

    template <class T>
    const bool 
    node<T> :: printa_tabela()
    {
        if (is_empty())
        {
            std :: cout << "no vazio " << std :: endl;
            return 0;                               //caso a tabela esteja vazia, 
        }
        //else : vetor não está vazio
        for(int i = 0; i <= vetor_fim; i++)
        {
            std :: cout << vetor[i] << " ";
        }
        std :: cout << std :: endl;

        return 1;
    }
}
#endif /* NODE_H */