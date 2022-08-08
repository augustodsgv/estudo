/*
* Programa : tabela hash
* objetivo : implementação de uma tabela de espalhamento
* Autor : Augusto dos Santos Gomes Vaz
* Data : 04/08/2022
*/

/* BIBLIOTECAS */
#include "hash.h"
#include "tabelaHash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


//devolve um tamanho sugerido para a tabela com base na quantidade de elementos que serão guardados nela
int
tamanhoTabela(int n_elementos)
{
    int k = log2(n_elementos);
    return pow(2, k + 1);
}

//cria um struct palavra a partir de uma string e seu valor
word
criaPalavra(char palavra[], int valor)
{
    word novaPalavra;
    novaPalavra.wordString = palavra;
    novaPalavra.value = valor;
    novaPalavra.ativo = 0;
    return novaPalavra;
}

//cria uma tabela hash com o tamanho especificado
table *
criaTabela(int n_elementos)
{
    table * tabela = (table*) malloc (sizeof(table));
    tabela->tamanho = tamanhoTabela(n_elementos);
    tabela->primo = tabela->tamanho - 1;
    tabela->vetor = (word*) malloc (sizeof(word) * tabela->tamanho);

    for(int i = 0; i < tabela->tamanho; i++)
    {
        tabela->vetor[i].ativo = 0;
        tabela->vetor[i].wordString = NULL;
    }
    /*
    tabela->vetor[0].value = 0;
    tabela->vetor[0].wordString = NULL;
    //*/

    return tabela;
}

//percorre toda a tabela printando os seus valores
int
printaTabela(table * tabela)
{
    if (tabela != NULL)
    {
        for(int i = 0; i < tabela->tamanho; i++)
        {
            if(tabela->vetor[i].ativo)
                printf("[%d] %s, valor : %d\n", i, tabela->vetor[i].wordString, tabela->vetor[i].value);
            else
                printf("[%d] none\n", i);
        }
        return 1;


    }
    return 0;
}

//indica se achou a palavra na tabela
int
buscaTabela(table * tabela, char * string, int * valor)
{
    int hash, n_tentativas = 0;
    hash = hashFunc(string, tabela->tamanho, tabela->primo);
    
    while(tabela->vetor[hash].wordString != NULL && strcmp(tabela->vetor[hash].wordString, string))
    {
        if (!strcmp(tabela->vetor[hash].wordString, string))        //caso seja uma chave já usada, ela nao pode ser inserida novamente, 
                return 0;                                               //pois ela estaria inacessivel
            
            //else : o conflito não é com a mesma chave
            hash += (int)pow(2, n_tentativas);
            hash = hash % tabela->tamanho;         //para garantir que hash está dentro do tamanho do vetor
            n_tentativas++;
    }
    //descobrindo se existe, de fato, um elemento com esse código hash na tabela
    if(tabela->vetor[hash].wordString == NULL)
        return 0;

    //caso haja, verificando se é o primeiro elemento ou se é uma colisao
    if (!strcmp(tabela->vetor[hash].wordString, string))
    {
        *valor = tabela->vetor[hash].value;
        return 1;
    }
    return 0;  
}



//insere uma string na tabela
//se ele já existir, incrementa seu contador
//se houver colisao, ignora e mantem o antigo
int
insereTabela(table * tabela, char * string, int valor)
{
    int hash, n_tentativas;

    hash = hashFunc(string, tabela->tamanho, tabela->primo);

    //tratamento da colisão usando codificação aberta    
    //aqui sera usado um tratamento de colisao quadratico, ou seja,
    //cada vez que houver uma tentativa nova de inserção,
    //ele irá somar o valor do código hash com 2 ^ n_tentativas
    if(tabela->vetor[hash].wordString != NULL)
    {   
        n_tentativas = 0;
        while(tabela->vetor[hash].wordString != NULL)
        {
            if (!strcmp(tabela->vetor[hash].wordString, string))        //caso seja uma chave já usada, ela nao pode ser inserida novamente, 
                return 0;                                               //pois ela estaria inacessivel
            
            //else : o conflito não é com a mesma chave
            //printf("houve conflito\n");
            //printf("hash antes : %d", hash);
            hash += (int)pow(2, n_tentativas);
            hash = hash % tabela->tamanho;         //para garantir que hash está dentro do tamanho do vetor
            n_tentativas++;

        }
    }
    //adicionando à tabela
    tabela->vetor[hash].wordString = string;
    tabela->vetor[hash].value = valor;
    tabela->vetor[hash].ativo = 1;
    //tabela->vetor[hash].cont = 1;

    return 1;
}

//remove uma string da tabela
int
removeTabela(table * tabela, char * string)
{
    int hash = hashFunc(string, tabela->tamanho, tabela->primo);

    //caso não exista o elemento na table
    if (tabela->vetor[hash].wordString == NULL)
        return 0;

    //caso exista mas não seja a palavra
    if (!strcmp(tabela->vetor->wordString, string))
        return 0;

    //caso seja, de fato, a palavra procurada
    tabela->vetor[hash].wordString = NULL;
    tabela->vetor[hash].value = 0;
    return 1;

}

//desaloca a tabela
int
deletaTabela(table * tabela)
{
    free(tabela->vetor);
    tabela->vetor = NULL;
    free(tabela);
    tabela = NULL;
    return 1;
}